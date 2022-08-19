#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m, q;
	cin >> n >> m >> q;
	int stuff[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			stuff[i][j] = 0;
		}
	}
	vector<int> tl;
	vector<int> v;
	for(int i = 0; i < q; i++){
		int tt;
		cin >> tt;
		if(tt == 3){
			int r, c, x;
			cin >> r >> c >> x;
			r--;
			c--;
			stuff[r][c] = x;
		} else {
			tl.push_back(tt);
			int l;
			cin >> l;
			l--;
			v.push_back(l);
			if(tt == 1){
				int a = stuff[l][0];
				for(int i = 0; i+1<m; i++){
					stuff[l][i] = stuff[l][i+1];
				}
				stuff[l][m-1] = a;
			} else {
				int a = stuff[0][l];
				for(int i = 0; i+1<n; i++){
					stuff[i][l] = stuff[i+1][l];
				}
				stuff[n-1][l] = a;
			}
		}
	}
	for(int z = tl.size()-1; z >= 0; z--){
		int tt = tl[z];
		int l = v[z];
		if(tt == 1){
			int a = stuff[l][m-1];
			for(int i = m-1; i-1 >= 0; i--){
				stuff[l][i] = stuff[l][i-1];
			}
			stuff[l][0] = a;
		} else {
			int a = stuff[n-1][l];
			for(int i = n-1; i-1 >= 0; i--){
				stuff[i][l] = stuff[i-1][l];
			}
			stuff[0][l] = a;
		}		
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << stuff[i][j] << " ";
		}
		cout << endl;
	}	
}