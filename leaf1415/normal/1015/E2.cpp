#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef pair< pair<int, int>, int> ope;

int h, w;
char map[1005][1005];
int l[1005][1005], r[1005][1005], u[1005][1005], d[1005][1005];
int s[1005][1005];
int sum[1005][1005], dif[1005][1005];
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
				dif[x-s[x][y]][y]++, dif[x+s[x][y]+1][y]--, dif[x-s[x][y]][y+1]--, dif[x+s[x][y]+1][y+1]++;
				dif[x][y-s[x][y]]++, dif[x][y+s[x][y]+1]--, dif[x+1][y-s[x][y]]--, dif[x+1][y+s[x][y]+1]++;
			}
		}
	}
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			sum[x][y] = sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1] + dif[x][y];
		}
	}
	
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(map[x][y] == '*' && sum[x][y] == 0){
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