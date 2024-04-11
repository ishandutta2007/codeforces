#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
int a[505][505], b[505][505];
vector<int> vec[1005], vec2[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> b[i][j];
		}
	}
	
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			vec[i+j].push_back(a[i][j]);
			vec2[i+j].push_back(b[i][j]);
		}
	}
	for(int i = 2; i <= h+w; i++){
		sort(vec[i].begin(), vec[i].end());
		sort(vec2[i].begin(), vec2[i].end());
		if(vec[i] != vec2[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}