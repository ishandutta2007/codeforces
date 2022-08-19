#include<iostream>
using namespace std;
typedef long long LL;
int stuff[2000][2000];
int main(){
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	int min1[k+1];
	int max1[k+1];
	int min2[k+1];
	int max2[k+1];
	for(int i = 0; i <= k; i++){
		min1[i] = 10000;
		max1[i] = -10000;
		min2[i] = 10000;
		max2[i] = -10000;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> stuff[i][j];
		min1[stuff[i][j]] = min(min1[stuff[i][j]], i+j);
		max1[stuff[i][j]] = max(max1[stuff[i][j]], i+j);
		min2[stuff[i][j]] = min(min2[stuff[i][j]], i-j);
		max2[stuff[i][j]] = max(max2[stuff[i][j]], i-j);
		}
	}
	int maxcomp = 0;
	int a[s];
	for(int i = 0; i < s; i++) cin >> a[i];
	for(int i = 1; i < s; i++){
		int c = a[i-1];
		int d = a[i];
		maxcomp = max(maxcomp, max1[d]-min1[c]);
		maxcomp = max(maxcomp, max1[c]-min1[d]);
		maxcomp = max(maxcomp, max2[d]-min1[c]);
		maxcomp = max(maxcomp, max2[c]-min2[d]);
	}
	cout << maxcomp << endl;
}