#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define inf (int)1e9

using namespace std;
typedef pair<int, int> P;

int n, k;
char map[2005][2005];
int dist[2005][2005];

int main(void)
{
	cin >> n >> k;
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			cin >> map[x][y];
		}
	}
	
	for(int x = 0; x <= n; x++){
		for(int y = 0; y <= n; y++){
			dist[x][y] = inf;
		}
	}
	dist[0][1] = 0;
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			dist[x][y] = min(dist[x-1][y], dist[x][y-1]);
			if(map[x][y] != 'a') dist[x][y]++;
		}
	}
	
	/*for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			cout << dist[y][x] << " "; 
		}
		cout << endl;
	}*/
	
	int mx = -1;
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			if(dist[x][y] > k) continue;
			mx = max(mx, (x-1)+(y-1));
		}
	}
	for(int i = 0; i <= mx; i++) cout << 'a';
	
	vector<pair<char, P> > vec, nvec;
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			if(dist[x][y] > k) continue;
			if((x-1)+(y-1) == mx) vec.push_back(make_pair(map[x][y], make_pair(x, y)));
		}
	}
	if(mx == -1){
		cout << map[1][1];
		vec.push_back(make_pair(map[1][1], make_pair(1, 1)));
		mx = 0;
	}
	
	int d = mx;
	for(int i = d+1; i <= 2*n-2; i++){
		nvec.clear();
		for(int j = 0; j < vec.size(); j++){
			int x = vec[j].second.first, y = vec[j].second.second;
			if(x < n) nvec.push_back(make_pair(map[x+1][y], make_pair(x+1, y)));
			if(y < n) nvec.push_back(make_pair(map[x][y+1], make_pair(x, y+1)));
		}
		sort(nvec.begin(), nvec.end());
		nvec.erase(unique(nvec.begin(), nvec.end()), nvec.end());
		char c = nvec[0].first; cout << c;
		nvec.erase(upper_bound(nvec.begin(), nvec.end(), make_pair(c, make_pair(inf, inf))), nvec.end());
		vec = nvec;
	}
	cout << endl;
	
	return 0;
}