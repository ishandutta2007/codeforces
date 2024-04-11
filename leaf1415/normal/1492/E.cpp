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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

int h, w;
int a[300005], b[300005];
vector<int> vec[300005];
bool dif[300005];

int p(int i, int j)
{
	return i*w+j;
}

bool check()
{
	rep(i, 0, h-1){
		int cnt = 0;
		rep(j, 0, w-1) if(b[j] != a[p(i, j)]) cnt++;
		if(cnt > 2) return false;
	}
	return true;
}

int check2(int id, int l, int r)
{
	int x = 0;
	rep(i, 1, h-1){
		int cnt = vec[i].size();
		if(dif[p(i, l)]) cnt--;
		if(dif[p(i, r)]) cnt--;
		if(a[p(id, l)] != a[p(i, l)]) cnt++;
		if(cnt <= 1) continue;
		if(cnt >= 3) return -1;
		if(x != 0 && x != a[p(i, r)]) return -1;
		x = a[p(i, r)];
	}
	if(x == 0) return 1;
	return x;
}

void print(int a[])
{
	cout << "Yes" << endl;
	rep(i, 0, w-1) cout << a[i] << " "; cout << endl;
	exit(0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	rep(i, 0, h*w-1) cin >> a[i];
	
	rep(i, 0, h-1){
		rep(j, 0, w-1){
			if(a[p(0, j)] != a[p(i, j)]){
				dif[p(i, j)] = true;
				vec[i].push_back(j);
			}
		}
	}
	
	ll max_val = 0, id;
	rep(i, 0, h-1){
		if(max_val < vec[i].size()){
			max_val = vec[i].size();
			id = i;
		}
	}
	
	if(max_val >= 5){
		cout << "No" << endl;
		return 0;
	}
	if(max_val <= 2) print(a);
	
	
	rep(i, 0, w-1) b[i] = a[i];
	vector<int> &cvec = vec[id];
	reps(i, cvec) reps(j, cvec){
		if(i >= j) continue;
		int l = cvec[i], r = cvec[j];
		b[l] = a[p(id, l)], b[r] = a[p(id, r)];
		if(check()) print(b);
		b[l] = a[l], b[r] = a[r];
	}
	
	if(max_val == 3){
		reps(i, cvec){
			rep(j, 0, w-1){
				int l = cvec[i];
				if(l == j) continue;
				int res = check2(id, l, j);
				if(res > 0){
					b[l] = a[p(id, l)], b[j] = res;
					print(b);
				}
			}
		}
	}
	
	cout << "No" << endl;
	
	return 0;
}