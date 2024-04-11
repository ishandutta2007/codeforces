#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
string board[100];
string board2[100];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> board[i];
		board2[i] = board[i];
	}
	int x[3000];
	int y[3000];
	int k = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == 'o'){
				x[k] = i;
				y[k] = j;
				//cout << x[k] << " " << y[k] << endl;
				k++;
			}
			board2[i][j] = '.';
		}
	}
	int stuff[2*n-1][2*n-1];
	stuff[n-1][n-1] = 2;
	for(int i = -n+1; i <= n-1; i++){
		for(int j = -n+1; j <= n-1; j++){
			stuff[i+n-1][j+n-1] = 1;
			for(int a = 0; a < k; a++){
				if((x[a]+i <0) || (x[a]+i >=n) || (y[a]+j < 0) || (y[a]+j >= n) || (board[x[a]+i][y[a]+j] != '.')){

				} else {
					stuff[i+n-1][j+n-1] = 0;
				}
			}
		}
	}

	for(int a = 0; a < k; a++){
		board2[x[a]][y[a]] = 'o';
		for(int i = -n+1; i <= n-1; i++){
			for(int j = -n+1; j <= n-1; j++){
				if(stuff[i+n-1][j+n-1]){
				if((x[a]+i <0) || (x[a]+i >=n) || (y[a]+j < 0) || (y[a]+j >= n)){
				} else {
					if(board2[x[a]+i][y[a]+j] != 'o') board2[x[a]+i][y[a]+j] = 'x';
				}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board2[i][j] != board[i][j]){
				cout << "NO" << endl;
				return 0;
			}
		}
		//cout << board2[i] << endl;

	}
	stuff[n-1][n-1] = 2;
	cout << "YES" << endl;
	for(int i = 0; i < 2*n-1; i++){
		for(int j = 0; j < 2*n-1; j++){
			if(stuff[i][j] == 0) cout << '.';
			if(stuff[i][j] == 1) cout << 'x';
			if(stuff[i][j] == 2) cout << 'o';
		}
		cout << endl;
	}
}