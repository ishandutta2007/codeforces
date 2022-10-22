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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

ll T;
ll n;
char c[1005][1005], d[1005][1005];

ll get(char c[1005][1005], ll i, ll j)
{
	return c[i][j]^c[i+1][j]^c[i][j+1]^c[i+1][j+1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) rep(j, 1, n) cin >> c[i][j], c[i][j] %= 2;
		rep(i, 1, n) rep(j, 1, n) cin >> d[i][j], d[i][j] %= 2;
		
		rep(i, 1, n-1) rep(j, 1, n-1){
			if(get(c, i, j) != get(d, i, j)){
				cout<< "NO" << endl;
				goto end;
			}
		}
		cout << "YES" << endl;
		end:;
	}
	
	return 0;
}