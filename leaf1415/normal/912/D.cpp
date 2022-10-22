#include <iostream>
#include <utility>
#include <queue>
#include <set>
#include <stdio.h>
#define llint long long 

using namespace std;
typedef pair<llint, llint> P;

llint H, W, r, k;
const int vx[] = {1, 0, -1, 0}, vy[] = {0, -1, 0, 1};

llint calc(llint x, llint y)
{
	llint w = min(x, W-r) - max(0LL, x-r+1) + 1;
	llint h = min(y, H-r) - max(0LL, y-r+1) + 1;
	return w*h;
}

int main(void)
{
	cin >> H >> W >> r >> k;
	
	priority_queue<pair<llint, P> > Q;
	Q.push( make_pair(calc(W/2, H/2), make_pair(W/2, H/2)) );
	set<P> s;
	s.insert(make_pair(W/2, H/2));
	
	llint ans = 0;
	llint x, y, nx, ny;
	while(k){
		ans += Q.top().first; k--;
		x = Q.top().second.first;
		y = Q.top().second.second;
		Q.pop();
		for(int dir = 0; dir < 4; dir++){
			nx = x + vx[dir], ny = y + vy[dir];
			if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
			if(s.count(make_pair(nx, ny))) continue;
			Q.push( make_pair( calc(nx, ny), make_pair(nx, ny) ) );
			s.insert(make_pair(nx, ny));
		}
	}
	
	llint all = (W-r+1) * (H-r+1);
	printf("%.12f\n", (double)ans / (double)all );
	return 0;
}