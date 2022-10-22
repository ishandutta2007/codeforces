#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
int a[1005][1005];
int r[1005][1005], c[1005][1005];
int R[1005], C[1005];
vector<int> comp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> a[i][j];
		}
	}
	
	for(int i = 0; i < h; i++){
		comp.clear();
		for(int j = 0; j < w; j++) comp.push_back(a[i][j]);
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for(int j = 0; j < w; j++) r[i][j] = lower_bound(comp.begin(), comp.end(), a[i][j]) - comp.begin();
		R[i] = comp.size();
	}
	for(int i = 0; i < w; i++){
		comp.clear();
		for(int j = 0; j < h; j++) comp.push_back(a[j][i]);
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for(int j = 0; j < h; j++) c[j][i] = lower_bound(comp.begin(), comp.end(), a[j][i]) - comp.begin();
		C[i] = comp.size();
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			int ans;
			if(r[i][j] < c[i][j]) ans = max(C[j], R[i]+c[i][j]-r[i][j]);
			else ans = max(R[i], C[j]+r[i][j]-c[i][j]);
			cout << ans << " ";
		}
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}