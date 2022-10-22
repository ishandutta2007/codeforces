#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<P, llint> T;

ll k, a, b;
ll A[3][3], B[3][3];
bool used[3][3];

ll calc(ll a, ll b, ll A[3][3], ll B[3][3])
{
	rep(i, 0, 2) rep(j, 0, 2) used[i][j] = false;
	
	vector<T> vec;
	while(!used[a][b]){
		if(a == (b+1)%3) vec.push_back(T(P(a, b), 1));
		else vec.push_back(T(P(a, b), 0));
		
		used[a][b] = true;
		ll na = A[a][b], nb = B[a][b];
		a = na, b = nb;
	}
	
	vector<T> vec2;
	rep(i, 0, (int)vec.size()-1){
		if(vec[i].first == P(a, b)){
			vec2.insert(vec2.begin(), vec.begin()+i, vec.end());
			vec.erase(vec.begin()+i, vec.end());
			break;
		}
	}
	
	ll rem = k, ans = 0;
	rep(i, 0, (int)vec.size()-1){
		if(rem == 0) break;
		rem--;
		ans += vec[i].second;
	}
	if(rem == 0) return ans;
	
	rem--;
	ll sum = 0, len = vec2.size();
	for(auto x : vec2) sum += x.second;
	
	ans += rem/len*sum, rem %= len;
	rep(i, 0, rem) ans += vec2[i].second;
	
	return ans;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k >> a >> b;
	a--, b--;
	
	rep(i, 0, 2) rep(j, 0, 2) cin >> A[i][j], A[i][j]--;
	rep(i, 0, 2) rep(j, 0, 2) cin >> B[i][j], B[i][j]--;
	
	cout << calc(a, b, A, B) << " ";
	
	rep(i, 0, 2) rep(j, 0, 2) if(i < j) swap(A[i][j], A[j][i]), swap(B[i][j], B[j][i]);
	
	cout << calc(b, a, B, A) << endl;
	
	return 0;
}