#include <iostream>
#include <deque>
#define llint long long
#define mod 998244353

using namespace std;

llint H, W, h, w;
llint g, a, b, c;
llint map[3005][3005];
llint mn[3005][3005];

llint calc(llint x)
{
	deque<llint> deq;
	for(int y = 1; y <= H; y++){
		while(deq.size() && map[x][deq.back()] > map[x][y]) deq.pop_back();
		deq.push_back(y);
		if(y >= h) mn[x][y-h+1] = map[x][deq.front()];
		if(deq.front() == y-h+1) deq.pop_front();
	}
}

llint calc2(llint y)
{
	deque<llint> deq;
	llint ret = 0;
	for(int x = 1; x <= W; x++){
		while(deq.size() && mn[deq.back()][y] > mn[x][y]) deq.pop_back();
		deq.push_back(x);
		if(x >= w) ret += mn[deq.front()][y];
		if(deq.front() == x-w+1) deq.pop_front();
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> H >> W >> h >> w;
	cin >> g >> a >> b >> c;
	
	for(int y = 1; y <= H; y++){
		for(int x = 1; x <= W; x++){
			map[x][y] = g;
			g = (g*a+b) % c;
		}
	}
	llint ans = 0;
	for(int x = 1; x <= W; x++) calc(x);
	
	/*for(int y = 1; y <= H; y++){
		for(int x = 1; x <= W; x++){
			cout << mn[x][y] << " ";
		}cout << endl;
	}*/
	
	for(int y = 1; y <= H-h+1; y++) ans += calc2(y);
	cout << ans << endl;
	
	return 0;
}