#include <bits/stdc++.h>
using namespace std;

bool ask(int x, int y, int z, int w){
	cout << "? " << x+1 << " " << y+1 << " " << z+1 << " " << w+1 << '\n';
	cout << flush;
	int res;
	cin >> res;
	return res ? true : false;
}

void pr(vector<string> x){
	for(string a : x){
		cout << a << '\n';
	}
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<string> vals(n, string(n, '0'));
	vals[0][0] = '1';
	char x = '0' ^ '1';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i + j < 2) continue;
			if(i + j == 2*n-2) continue;
			int v;
			if(j >= i){
				if(i >= 1){
					v = ask(i-1, j-1, i, j);
					vals[i][j] = vals[i-1][j-1];
				} else {
					v = ask(i, j-2, i, j);
					vals[i][j] = vals[i][j-2];
				}
			} else if(i > j){
				if(j >= 1){
					v = ask(i-1, j-1, i, j);
					vals[i][j] = vals[i-1][j-1];
				} else {
					v = ask(i-2, j, i, j);
					vals[i][j] = vals[i-2][j];
				}
			} else assert(false);
			if(!v) vals[i][j] ^= x;
		}
	}
	bool f = ask(0, 1, 2, 1);
	bool g = (vals[0][1] ^ vals[2][1]) != x;
	if(f != g){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((i + j) & 1){
					if(i > j){
						vals[i][j] ^= x;
					}
				}
			}
		}
	}
	vector<string> grid1 = vals;
	vector<string> grid2 = vals;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i + j) & 1){
				grid2[i][j] ^= x;
			}
		}
	}
	int q = -1;
	for(int i = 0; i + 2 < n; i++){
		if(grid1[i][i] != grid1[i+2][i+2]){
			q = i;
		}
	}
	assert(q != -1);
	for(int r = q; r < q+2; r++){
		bool pal1 = (grid1[r][q] == grid1[r+1][q+2]) && 
		((grid1[r+1][q] == grid1[r+1][q+1]) || (grid1[r][q+1] == grid1[r+1][q+1]) || (grid1[r][q+1] == grid1[r][q+2]));
		bool pal2 = (grid2[r][q] == grid2[r+1][q+2]) && 
		((grid2[r+1][q] == grid2[r+1][q+1]) || (grid2[r][q+1] == grid2[r+1][q+1]) || (grid2[r][q+1] == grid2[r][q+2]));
		if(pal1 != pal2){
			bool ans = ask(r, q, r+1, q+2);
			cout << "!" << '\n';
			if(ans == pal1){
				pr(grid1);
			} else {
				pr(grid2);
			}
			return 0;
		}
	}
	for(int r = q; r < q+2; r++){
		bool pal1 = (grid1[q][r] == grid1[q+2][r+1]) && 
		((grid1[q][r+1] == grid1[q+1][r+1]) || (grid1[q+1][r] == grid1[q+1][r+1]) || (grid1[q+1][r] == grid1[q+2][r]));
		bool pal2 = (grid2[q][r] == grid2[q+2][r+1]) && 
		((grid2[q][r+1] == grid2[q+1][r+1]) || (grid2[q+1][r] == grid2[q+1][r+1]) || (grid2[q+1][r] == grid2[q+2][r]));
		if(pal1 != pal2){
			bool ans = ask(q, r, q+2, r+1);
			cout << "!" << '\n';
			if(ans == pal1){
				pr(grid1);
			} else {
				pr(grid2);
			}
			return 0;
		}
	}
}