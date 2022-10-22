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

ll h, w;
char c[105][105];
ll gx, gy;
bool swapLR, swapUD;
ll dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
ll dist[105][105];

P query(ll d)
{
	if(d % 2 == 0 && swapLR) d = (d+2)%4;
	if(d % 2 && swapUD) d = (d+2)%4;
	ll y, x;
	cout << "RULD"[d] << endl;
	cin >> y >> x;
	if(x == gx && y == gy) exit(0);
	return P(x, y);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	rep(y, 1, h) rep(x, 1, w){
		cin >> c[x][y];
		if(c[x][y] == 'F'){
			gx = x, gy = y;
			c[x][y] = '.';
		}
	}
	
	P res;
	if(w >= 2 && c[2][1] == '.'){
		res = query(0);
		if(res == P(1, 1)) swapLR = true;
		else query(2);
		
		if(gy == 1){
			bool flag = true;
			rep(x, 1, gx) if(c[x][1] == '*') flag = false;
			if(flag){
				rep(j, 1, gx-1) query(0);
				return 0;
			}
		}
			
		ll pos;
		rep(x, 1, w){
			if(c[x][2] == '.'){
				pos = x;
				break;
			}
		}
		rep(j, 1, pos-1) query(0);
		res = query(3);
		if(res.second == 1) swapUD = true;
	}
	else{
		res = query(3);
		if(res == P(1, 1)) swapUD = true;
		else query(1);
		
		if(gx == 1){
			bool flag = true;
			rep(y, 1, gy) if(c[1][y] == '*') flag = false;
			if(flag){
				rep(j, 1, gy-1) query(3);
				return 0;
			}
		}
			
		ll pos;
		rep(y, 1, h){
			if(c[2][y] == '.'){
				pos = y;
				break;
			}
		}
		rep(j, 1, pos-1) query(3);
		res = query(0);
		if(res.first == 1) swapLR = true;
	}
	
	rep(y, 1, h) rep(x, 1, w) dist[x][y] = inf;
	dist[gx][gy] = 0;
	queue<P> Q;
	Q.push(P(gx, gy));
	
	ll x, y;
	while(Q.size()){
		x = Q.front().first, y = Q.front().second;
		Q.pop();
		rep(i, 0, 3){
			ll nx = x + dx[i], ny = y + dy[i];
			if(nx <= 0 || nx > w || ny <= 0 || ny > h) continue;
			if(c[nx][ny] == '*') continue;
			if(dist[nx][ny] < inf/2) continue;
			dist[nx][ny] = dist[x][y] + 1;
			Q.push(P(nx, ny));
		}
	}
	
	x = res.first, y = res.second;
	while(1){
		rep(i, 0, 3){
			ll nx = x + dx[i], ny = y + dy[i];
			if(nx <= 0 || nx > w || ny <= 0 || ny > h) continue;
			if(dist[nx][ny] == dist[x][y]-1){
				res = query(i);
				x = res.first, y = res.second;
				break;
			}
		}
	}
	
	return 0;
}