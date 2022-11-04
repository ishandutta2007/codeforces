#include <bits/stdc++.h>
using namespace std;

const int base = 500;
const int MAXN = 100000+10;

char a[MAXN][12];
int n,m,q;
int fx[MAXN][12],fy[MAXN][12];

void go (int index){
	int lo = index*base+1;
	int hi = min(n, (index+1)*base);
	for (int row=lo; row<=hi; row++){
		int l = 1;
		while (l<=m && a[row][l]=='<'){
			fx[row][l] = row; fy[row][l] = 0;
			l++;
		}
		int r = m;
		while (r>=1 && a[row][r]=='>'){
			fx[row][r] = row; fy[row][r] = m+1;
			r--;
		}
		for (int j=l; j<=r; j++)
			fx[row][j] = fy[row][j] = -1;
		for (int j=l; j<=r; j++) if (a[row][j]=='^'){
			fx[row][j] = (row==lo ? row-1 : fx[row-1][j]); 
			fy[row][j] = (row==lo ? j : fy[row-1][j]);
			int left=j-1, right=j+1;
			while (left>=1 && a[row][left]=='>'){
				fx[row][left] = fx[row][left+1];
				fy[row][left] = fy[row][left+1];
				left--;
			}
			while (right<=m && a[row][right]=='<'){
				fx[row][right] = fx[row][right-1];
				fy[row][right] = fy[row][right-1];
				right++;
			}
		}
	}
}

void get (int r, int c){
	while (r>=1 && r<=n && c>=1 && c<=m){
		int rr = fx[r][c];
		int cc = fy[r][c];
		r = rr;
		c = cc;
	}
	if (r == -1)
		printf("-1 -1\n");
	else
		printf("%d %d\n", r, c);
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=n; i++)
		scanf("%s", a[i]+1);
	memset(fx, -1, sizeof fx);
	memset(fy, -1, sizeof fy);
	for (int j=1; j<=m; j++)
		fx[0][j] = 0, fy[0][j] = j;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=m+1; j+=m+1)
			fx[i][j] = i, fy[i][j] = j;
	for (int i=1; i<=n; i+=base)
		go((i-1)/base);
	for (int o=0; o<q; o++){
		char ord; cin >> ord;
		if (ord == 'A'){
			int r,c; scanf("%d%d", &r, &c);
			get(r,c);
		}else{
			int r,c; char t; scanf("%d%d %c", &r, &c, &t);
			a[r][c] = t;
			go((r-1)/base);
		}
	}
	return 0;
}