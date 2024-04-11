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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint h, w;
llint a[305][305];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> a[x][y];
			}
		}
		
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				bool xflag = (x == 1 || x == w), yflag = (y == 1 || y == h);
				if(xflag && yflag){
					if(a[x][y] > 2){
						cout << "NO" << endl;
						goto end;
					}
					a[x][y] = 2;
				}
				else if(xflag || yflag){
					if(a[x][y] > 3){
						cout << "NO" << endl;
						goto end;
					}
					a[x][y] = 3;
				}
				else{
					if(a[x][y] > 4){
						cout << "NO" << endl;
						goto end;
					}
					a[x][y] = 4;
				}
			}
		}
		cout << "YES" << endl;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cout << a[x][y] << " ";
			}
			cout << endl;
		}
		end:;
	}
	
	return 0;
}