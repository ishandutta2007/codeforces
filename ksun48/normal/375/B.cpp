#include<iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	char stuff[n+1][m+1];
	for(int i = 0; i < n; i++) cin >> stuff[i];
	int cur[n];
	for(int i = 0; i < n; i++) cur[i] = 0;
	int maxarea = 0;
	int newcur[n];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(stuff[j][i] == '0'){
				cur[j] = 0;
			} else {
				cur[j]++;
			}
			newcur[j] = cur[j];
		}
		sort(newcur, newcur+n);
		for(int j = 0; j < n; j++){
			maxarea = max(maxarea, newcur[j]*(n-j));
		}
	}
	cout << maxarea << endl;
	return 0;
}