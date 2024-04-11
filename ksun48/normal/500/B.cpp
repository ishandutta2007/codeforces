#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
string stuff[400];
int p[400];
int connected[400];
int dfs(int k){
	for(int i = 0; i < n; i++){
		if(stuff[k][i] == '1'){
			if(connected[i] == 0){
				connected[i] = 1;
				dfs(i);
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++){
		cin >> stuff[i];
	}
	for(int i = 0; i < n; i++){
		for(int r= 0; r < 400; r++){
			connected[r] = 0;
		}
		connected[i] = 1;
		dfs(i);
		int sorts[400];
		int ns = 0;
		for(int i = 0; i < n; i++){
			if(connected[i] ==1){
				sorts[ns++] = p[i];
			}
		}
		sort(sorts, sorts+ns);
		ns = 0;
		for(int i = 0; i < n; i++){
			if(connected[i] ==1){
				p[i] = sorts[ns++];
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << p[i] << " ";
	}
	cout << endl;
}