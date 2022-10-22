#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2001;
int tt,n,f[N][N],c[26],a[N][26],b[N][26];
char s[N],t[N];
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		bool bad=false;
		scanf("%d%s%s",&n,s,t);
		F(i,0,26)c[i]=0;
		F(i,0,n)++c[s[i]-'a'];
		F(i,0,n)--c[t[i]-'a'];
		F(i,0,26)if(c[i])bad=true;
		if(bad&&(puts("-1"),1))continue;
		F(i,0,26)F(j,0,n)a[j+1][i]=a[j][i]+(s[j]=='a'+i);
		F(i,0,26)F(j,0,n)b[j+1][i]=b[j][i]+(t[j]=='a'+i);
		F(i,0,n+1)F(j,0,n+1)f[i][j]=0;
		F(i,0,n)F(j,0,n)f[i+1][j+1]=max(f[i][j]+(s[i]==t[j]
		&&a[i][0]<=b[j][0]&&a[i][1]<=b[j][1]&&a[i][2]<=b[j][2]&&a[i][3]<=b[j][3]&&a[i][4]<=b[j][4]&&a[i][5]<=b[j][5]
		&&a[i][6]<=b[j][6]&&a[i][7]<=b[j][7]&&a[i][8]<=b[j][8]&&a[i][9]<=b[j][9]&&a[i][10]<=b[j][10]&&a[i][11]<=b[j][11]
		&&a[i][12]<=b[j][12]&&a[i][13]<=b[j][13]&&a[i][14]<=b[j][14]&&a[i][15]<=b[j][15]&&a[i][16]<=b[j][16]&&a[i][17]<=b[j][17]
		&&a[i][18]<=b[j][18]&&a[i][19]<=b[j][19]&&a[i][20]<=b[j][20]&&a[i][21]<=b[j][21]&&a[i][22]<=b[j][22]&&a[i][23]<=b[j][23]
		&&a[i][24]<=b[j][24]&&a[i][25]<=b[j][25]?1:0),max(f[i][j+1],f[i+1][j]));
		printf("%d\n",n-f[n][n]);
	}
	return 0;
}