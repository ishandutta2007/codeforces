#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int h, w;
	cin >> h >> w;
	string grid[h];
	for(int i = 0; i < h; i++) cin >> grid[i];
	int r[h+1][w+1];
	int d[h+1][w+1];
	for(int i = 0; i <= h; i++){
		r[i][0] = 0;
		d[i][0] = 0;
	}
	for(int i = 0; i <= w; i++){
		r[0][i] = 0;
		d[0][i] = 0;
	}
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			r[i][j] = r[i-1][j]+r[i][j-1]-r[i-1][j-1];
			if(j < w && grid[i-1][j-1] == '.' && grid[i-1][j] == '.'){
				r[i][j]++;
			}
			d[i][j] = d[i-1][j]+d[i][j-1]-d[i-1][j-1];
			if(i<h && grid[i-1][j-1] == '.' && grid[i][j-1] == '.'){
				d[i][j]++;
			}
			//cout << r[i][j] << " " << d[i][j] << endl;
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << r[r2][c2-1]-r[r1-1][c2-1]-r[r2][c1-1]+r[r1-1][c1-1] + d[r2-1][c2]-d[r2-1][c1-1]-d[r1-1][c2]+d[r1-1][c1-1] << endl;
	}
}