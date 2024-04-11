#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint h, w;
char c[2005][2006];
P pos[26];
int dx[] = {1, 0}, dy[] = {0, 1};
vector<pair<P, P> > vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				cin >> c[j][i];
			}
		}
		
		for(int i = 0; i < 26; i++) pos[i] = make_pair(0, 0);
		for(int x = 1; x <= w; x++){
			for(int y = 1; y <= h; y++){
				if(c[x][y] != '.'){
					if(pos[c[x][y]-'a'].first == 0) pos[c[x][y]-'a'] = make_pair(x, y);
				}
			}
		}
		
		int s = 26;
		for(int i = 25; i >= 0; i--){
			if(pos[i].first != 0){
				s = i;
				break;
			}
		}
		if(s == 26){
			cout << "YES" << "\n";
			cout << 0 << "\n";
			continue;
		}
		
		bool ans = true; vec.clear();
		for(int i = s; i >= 0; i--){
			if(pos[i].first == 0){
				vec.push_back(vec.back());
				continue;
			}
			bool find[2] = {false, false};
			for(int j = 0; j < 2; j++){
				int x = pos[i].first, y = pos[i].second;
				while(1){
					int nx = x + dx[j], ny = y + dy[j];
					if(nx < 1 || nx > w || ny < 1 || ny > h) break;
					if(c[nx][ny] == '.') break;
					if(c[nx][ny] == 'a'+i){
						find[j] = true;
						break;
					}
					if(c[nx][ny] != '*') break;
					x = nx, y = ny;
				}
			}
			if(find[0] && find[1]){
				ans = false;
				break;
			}
			
			int x = pos[i].first, y = pos[i].second;
			c[x][y] = '*';
			if(!find[0] && !find[1]){
				vec.push_back(make_pair(P(x, y), P(x, y)));
				continue;
			}
			int dir = 0;
			if(find[1]) dir = 1;
			while(1){
				int nx = x + dx[dir], ny = y + dy[dir];
				if(nx < 1 || nx > w || ny < 1 || ny > h) break;
				if(c[nx][ny] == '.') break;
				if(c[nx][ny] == 'a'+i) c[nx][ny] = '*';
				if(c[nx][ny] != '*') break;
				x = nx, y = ny;
			}
			vec.push_back(make_pair(P(pos[i].first, y = pos[i].second), P(x, y)));
			/*cout << i << " " << ans << "\n";
			for(int y = 1; y <= h; y++){
				for(int x = 1; x <= w; x++){
					cout << c[x][y];
				}
				cout << "\n";
			}*/
		}
		for(int x = 1; x <= w; x++){
			for(int y = 1; y <= h; y++){
				if(c[x][y] != '.' && c[x][y] != '*') ans = false;
			}
		}
		if(ans){
			cout << "YES" << "\n";
			cout << vec.size() << "\n";
			reverse(vec.begin(), vec.end());
			for(int i = 0; i < vec.size(); i++){
				cout << vec[i].first.second << " " << vec[i].first.first << " " <<
				vec[i].second.second << " " << vec[i].second.first << "\n";
			}
		}
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}