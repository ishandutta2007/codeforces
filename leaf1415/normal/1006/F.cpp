#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair< pair<llint, llint>, llint> T;

vector<T> vec1, vec2;

llint h, w, k;
llint a[25][25];
llint dx[] = {1, 0}, dy[] = {0, 1};
llint dx2[] = {-1, 0}, dy2[] = {0, -1};

void dfs(llint x, llint y, llint v, llint n, vector<T> &vec)
{
	if(n == 0){
		vec.push_back(make_pair(make_pair(x, y), v));
		return;
	}
	int nx, ny;
	for(int i = 0; i < 2; i++){
		nx = x + dx[i], ny = y + dy[i];
		if(nx <= 0 || nx > w || ny <= 0 || ny > h) continue;
		dfs(nx, ny, v^a[nx][ny], n-1, vec);
	}
}

void dfs2(llint x, llint y, llint v, llint n, vector<T> &vec)
{
	if(n == 0){
		vec.push_back(make_pair(make_pair(x, y), v));
		return;
	}
	v ^= a[x][y];
	int nx, ny;
	for(int i = 0; i < 2; i++){
		nx = x + dx2[i], ny = y + dy2[i];
		if(nx <= 0 || nx > w || ny <= 0 || ny > h) continue;
		dfs2(nx, ny, v, n-1, vec);
	}
}

int main(void)
{
	cin >> h >> w >> k;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> a[x][y];
		}
	}
	
	dfs(1, 1, a[1][1], (w+h-2)/2, vec1);
	dfs2(w, h, k, (w+h-2) - (w+h-2)/2, vec2);
	sort(vec2.begin(), vec2.end());
	
	llint ans = 0;
	for(int i = 0; i < vec1.size(); i++){
		ans += upper_bound(vec2.begin(), vec2.end(), vec1[i]) - lower_bound(vec2.begin(), vec2.end(), vec1[i]);
	}
	cout << ans << endl;
	return 0;
}