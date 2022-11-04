#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , b[maxn] , s[maxn] , mi , ss[3][maxn] , ans , xx , yy;
char a[maxn];

void mmax(int &x , int y , int ii , int jj)
{
	if (x < y) 
	{
		x = y;
		xx = ii;
		yy = jj;
	}
}

int main()
{
	int i , j , jj;
	cin >> n;
	scanf("%s",a+1);
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == '(') b[i] = 1;
		else b[i] = -1;
		s[i] = s[i-1]+b[i];
		mi = min(mi,s[i]);
	}
	if (s[n] != 0)
	{
		cout << "0\n1 1\n";
		return 0;
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 0 ; j < 3 ; j++)
			ss[j][i] = ss[j][i-1];
		if (s[i]-mi < 3) ss[s[i]-mi][i]++;
	}
	xx = yy = 1;
	ans = ss[0][n]-ss[0][0];
	j = -1;
	for (i = 1 ; i <= n ; i++)
	{
		if (j != -1 && b[i] == -1) mmax(ans,ss[1][i-1]-ss[1][j-1],j,i);
		if (s[i] == mi) j = -1;
		else if (b[i] == 1 && j == -1) j = i;
	}
	j = -1;
	for (i = 1 ; i <= n ; i++)
	{
		if (j != -1 && b[i] == -1) mmax(ans,ss[2][i-1]-ss[2][j-1]+ss[0][n]-ss[0][0],j,i);
		if (s[i] == mi || s[i]-1 == mi) j = -1;
		else if (b[i] == 1 && j == -1) j = i;
	}
	j = -1;
	for (i = 1 ; i <= n ; i++)
	{
		if (b[i] == -1) j = i;
		if (ss[0][i] != ss[0][0]) break;
	}
	jj = -1;
	for (i = n-1 ; i >= 1 ; i--)
	{
		if (ss[0][i] != ss[0][n]) break;
		if (b[i+1] == 1) jj = i;
	}
	if (j != -1 && jj != -1 && ss[1][jj]-ss[1][j-1] != ss[1][n]-ss[1][0]) mmax(ans,ss[1][n]-ss[1][0]-ss[1][jj]+ss[1][j-1],j,jj+1);
	j = -1;
	for (i = 1 ; i <= n ; i++)
	{
		if (b[i] == -1) j = i;
		if (ss[0][i] != ss[0][0] || ss[1][i] != ss[1][0]) break;
	}
	jj = -1;
	for (i = n-1 ; i >= 1 ; i--)
	{
		if (ss[0][i] != ss[0][n] || ss[1][i] != ss[1][n]) break;
		if (b[i+1] == 1) jj = i;
	}
	if (j != -1 && jj != -1) mmax(ans,ss[0][n]-ss[0][0]+ss[2][n]-ss[2][0]-ss[2][jj]+ss[2][j-1],j,jj+1);
	cout << ans << "\n" << xx << " " << yy << "\n";
	return 0;
}