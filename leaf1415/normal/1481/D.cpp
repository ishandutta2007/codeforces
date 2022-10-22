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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n, m;
char c[1005][1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, n) rep(j, 1, n) cin >> c[i][j];
		
		if(m % 2){
			cout << "YES" << endl;
			rep(k, 1, m+1){
				if(k % 2 == 0) cout << 1 << " ";
				else cout << 2 << " ";
			}
			cout << endl;
			continue;
		}
		
		if(n == 2 && c[1][2] != c[2][1]){
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
		rep(i, 1, n){
			rep(j, 1, n){
				if(i == j) continue;
				if(c[i][j] == c[j][i]){
					rep(k, 1, m+1){
						if(k % 2 == 0) cout << i << " ";
						else cout << j << " ";
					}
					cout << endl;
					goto end;
				}
			}
		}
		
		rep(i, 1, n){
			int ina = 0, outa = 0, inb = 0, outb = 0;
			rep(j, 1, n){
				if(i == j) continue;
				
				if(c[i][j] == 'a') outa = j;
				else outb = j;
				
				if(c[j][i] == 'a') ina = j;
				else inb = j;
			}
			
			ll x = 0, y = 0;
			if(ina && outa) x = ina, y = outa;
			if(inb && outb) x = inb, y = outb;
			if(x == 0) continue;
			
			ll b = m/2%2;
			rep(k, 0, m/2){
				if(k % 2 == b) cout << i << " ";
				else cout << x << " ";
			}
			rep(k, 1, m/2){
				if(k % 2 == 0) cout << i << " ";
				else cout << y << " ";
			}
			cout << endl;
			
			goto end;
		}
		return -1;
		
		end:;
	}
	
	return 0;
}