#include<bits/stdc++.h>
using namespace std;

int n;
char a[105][105];
char b[105][105];
int f[5][2];
int calc1() {
	//char b[n + 5][n + 5];
	for (int i = 0;i < n;++i) 
		for (int j = 0;j < n;++j) 
			b[i][j] = ((i + j + 1) % 2) + '0';
	
	int ans = 0;
	for (int i = 0;i < n;++i) 
		for (int j = 0;j < n;++j) 
			ans += (a[i][j] != b[i][j]);
	return ans;
}

int calc0() {
	//char b[n + 5][n + 5];
	for (int i = 0;i < n;++i) 
		for (int j = 0;j < n;++j) 
			b[i][j] = ((i + j) % 2) + '0';
	
	int ans = 0;
	for (int i = 0;i < n;++i) 
		for (int j = 0;j < n;++j) 
			ans += (a[i][j] != b[i][j]);
	return ans;
}

int main() {
	cin >> n;
	int t = 4;
	while(t--) {
		for (int i = 0;i < n;++i) 
			for (int j = 0;j < n;++j)
				cin >> a[i][j];
		f[t][0] = calc0();
		f[t][1] = calc1();
		//cout << f[t][1] << endl;
		//for (int i = 0;i < n;++i) {
			//for (int j = 0;j < n;++j) cout << b[i][j];
				//cout << endl;
			//}
	}
	int ans = 1000000;
	ans = min(ans,f[0][0] + f[1][0] + f[2][1] + f[3][1]);
	ans = min(ans,f[0][0] + f[1][1] + f[2][0] + f[3][1]);
	ans = min(ans,f[0][0] + f[1][1] + f[2][1] + f[3][0]);
	ans = min(ans,f[0][1] + f[1][0] + f[2][0] + f[3][1]);
	ans = min(ans,f[0][1] + f[1][0] + f[2][1] + f[3][0]);
	ans = min(ans,f[0][1] + f[1][1] + f[2][0] + f[3][0]);
	cout << ans << endl;
	for (int i = 0;i < 4;++i) 
		for (int j = 0;j < 2;++j)
			return 0;//printf("f[%d][%d] = %d\n",i,j,f[i][j]);
}