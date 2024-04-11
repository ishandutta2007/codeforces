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

ll h, w, k;
ll sx, sy, tx, ty;
ll dist[1005][1005];
bool used[1005][1005][4];
char c[1005][1005];
ll dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> k;
	rep(y, 1, h) rep(x, 1, w) cin >> c[x][y];
	cin >> sy >> sx >> ty >> tx;
	
	queue<P> Q;
	Q.push(P(sx, sy));
	rep(y, 1, h) rep(x, 1, w) dist[x][y] = inf;
	dist[sx][sy] = 0;
	
	while(Q.size()){
		ll x = Q.front().first, y = Q.front().second;
		Q.pop();
		rep(i, 0, 3){
			rep(j, 1, k){
				ll nx = x + dx[i]*j, ny = y + dy[i]*j;
				if(nx < 1 || nx > w || ny < 1 || ny > h) break;
				if(c[nx][ny] == '#') break;
				if(used[nx][ny][i]) break;
				used[nx][ny][i] = true;
				if(dist[nx][ny] > dist[x][y] + 1){
					dist[nx][ny] = dist[x][y] + 1;
					Q.push(P(nx, ny));
				}
			}
		}
	}
	
	/*rep(y, 1, h){
		rep(x, 1, w) cout<< dist[x][y] << " ";
		cout << endl;
	}*/
	
	
	if(dist[tx][ty] > inf/2) cout << -1 << endl;
	else cout << dist[tx][ty] << endl;
	
	return 0;
}