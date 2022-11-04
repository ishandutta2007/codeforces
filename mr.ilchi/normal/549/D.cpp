#include <bits/stdc++.h>
using namespace std;

char a[300][300];
int f[300][300];

int main(){
	int n,m; cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];
	int ans = 0;
	for (int i=n-1; i>=0; i--)
		for (int j=m-1; j>=0; j--){
			int need = a[i][j] == 'W' ? 1 : -1;
			if (need != f[i][j]){
				int change = need - f[i][j];
				for (int ii=0; ii<=i; ii++)
					for (int jj=0; jj<=j; jj++)
						f[ii][jj]+= change;
				ans++;
			}
		}
	cout << ans << endl;
	return 0;
}