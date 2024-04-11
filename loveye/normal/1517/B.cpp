#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N][N],t,n,m;
int l[N],r[N],id[N][N],now,ans[N][N];
inline int cmp(int &i,int &j) {
	return a[now][i] < a[now][j];
}
int main() {
	cin >>t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1;i <= n;++i) {
			for(int j = 1;j <= m;++j)
			 	cin >> a[i][j],id[i][j] = j;
			now = i;
			sort(&id[i][1],&id[i][m+1],cmp);
			l[i] = 1,r[i] = m;
		}
		for(int i = 1;i <= m;++i) {
			int pos = 1;
			for(int j = 1;j <= n;++j)
				if(a[j][id[j][l[j]]] < a[pos][id[pos][l[pos]]]) pos = j;
			for(int j = 1;j <= n;++j) if(j == pos) ans[j][i] = a[j][id[j][l[j]]],++l[j];
			else ans[j][i] = a[j][id[j][r[j]]],--r[j];
		}
		for(int i= 1;i <= n;++i) {
			for(int j = 1;j <= m;++j)
				cout << ans[i][j] << ' ';
			cout << endl;
		}
	}
	return 0;
}