#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef pair< pair<int, int>, int> ope;

int h, w;
char map[105][105];
int l[105][105], r[105][105], u[105][105], d[105][105];
int s[105][105];
vector<ope> ans;

int main(void)
{
	cin >> h >> w;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> map[x][y];
		}
	}
	
	for(int x = 1; x <= w; x++){
		int cnt = 0;
		for(int y = 1; y <= h; y++){
			if(map[x][y] == '*') cnt++;
			else cnt = 0;
			u[x][y] = cnt;
		}
	}
	for(int x = 1; x <= w; x++){
		int cnt = 0;
		for(int y = h; y >= 1; y--){
			if(map[x][y] == '*') cnt++;
			else cnt = 0;
			d[x][y] = cnt;
		}
	}
	
	for(int y = 1; y <= h; y++){
		int cnt = 0;
		for(int x = 1; x <= w; x++){
			if(map[x][y] == '*') cnt++;
			else cnt = 0;
			l[x][y] = cnt;
		}
	}
	for(int y = 1; y <= h; y++){
		int cnt = 0;
		for(int x = w; x >= 1; x--){
			if(map[x][y] == '*') cnt++;
			else cnt = 0;
			r[x][y] = cnt;
		}
	}
	
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			s[x][y] = min(min(l[x][y], r[x][y]), min(u[x][y], d[x][y])) - 1;
		}
	}
	
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(s[x][y] > 0){
				ans.push_back(make_pair(make_pair(x, y), s[x][y])); 
				for(int dx = -s[x][y]; dx <= s[x][y]; dx++) map[x+dx][y] = '.';
				for(int dy = -s[x][y]; dy <= s[x][y]; dy++) map[x][y+dy] = '.';
			}
		}
	}
	
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(map[x][y] == '*'){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first.second << " " << ans[i].first.first << " " << ans[i].second << endl;
	}
	return 0;
}