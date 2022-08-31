#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int num[n][n];
	int a[n];
	int r = 0;
	int used[n];
	string stuff;
	for(int i = 0; i < n; i++){
		cin >> stuff;
		for(int j = 0; j < n; j++){
			if(stuff[j] == '0'){
				num[i][j] = 0;
			} else {
				num[i][j] = 1;
			}
		}
	}
	int cur[n];
	for(int i = 0; i < n; i++){
		cur[i] = 0;
		used[i] = 0;
		cin >> a[i];
	}
	for(int zz = 0; zz <= n; zz++){
		int yes = -1;
		for(int i = 0; i < n; i++){
			if(a[i] == cur[i]){
				yes = i;
				break;
			}
		}
		if(yes == -1) break;
		r++;
		used[yes] = 1;
		for(int i = 0; i < n; i++){
			cur[i] += num[yes][i];
		}
	}
	cout << r << endl;
	for(int i = 0; i < n; i++){
		if(used[i]) cout << i+1 << " ";
	}
	cout << endl;


}