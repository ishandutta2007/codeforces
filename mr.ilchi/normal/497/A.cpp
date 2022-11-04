#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000+5;

bool ok[MAXN];
char a[MAXN][MAXN];
int n,m;

int main(){
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++)
		scanf("%s", a[i]);
	int ans = 0;
	for (int col = 0; col < m; col++){
		bool flag = false;
		for (int row = 0; row < n-1; row++){
			if ((a[row][col] > a[row+1][col]) && (ok[row]==false)){
				ans++;
				flag = true;
				break;
			}
		}
		if (!flag){
			for (int row = 0; row < n-1; row++) 
				if (a[row][col] < a[row+1][col])
					ok[row] = true;
		}
	}
	cout << ans << endl;
	return 0;
}