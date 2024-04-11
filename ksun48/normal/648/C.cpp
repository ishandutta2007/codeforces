#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, x, y;
string a[110];
int dot(int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m) return 0;
	if(a[i][j] == '.' || a[i][j] == 'S') return 0;
	return 1;
}
int dot2(int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m) return 0;
	if(a[i][j] == '.') return 0;
	return 1;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'S'){
				x = i;
				y = j;
			}
		}
	}
	while(1){
		if(dot(x,y-1)){
			y--;
			cout << "L";
			a[x][y] = '.';
			continue;
		}
		if(dot(x,y+1)){
			y++;
			a[x][y] = '.';
			cout << "R";
			continue;
		}
		if(dot(x+1,y)){
			x++;
			a[x][y] = '.';
			cout << "D";
			continue;
		}
		if(dot(x-1,y)){
			x--;
			a[x][y] = '.';
			cout << "U";
			continue;
		}
		break;
	}
	while(1){
		if(dot2(x,y-1)){
			y--;
			cout << "L";
			a[x][y] = '.';
			continue;
		}
		if(dot2(x,y+1)){
			y++;
			a[x][y] = '.';
			cout << "R";
			continue;
		}
		if(dot2(x+1,y)){
			x++;
			a[x][y] = '.';
			cout << "D";
			continue;
		}
		if(dot2(x-1,y)){
			x--;
			a[x][y] = '.';
			cout << "U";
			continue;
		}
		break;
	}
	cout << endl;
}