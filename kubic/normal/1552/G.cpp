#include <bits/stdc++.h>
using namespace std;
#define N 45
#define M 15
#define C 10000005
#define ull unsigned long long
int n,m,b[M],a[M][N];ull st[2][C];bool vs[N];
int main()
{
	scanf("%d %d",&n,&m);if(n==1) {puts("ACCEPTED");return 0;}
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&b[i]);
		for(int j=1;j<=b[i];++j) scanf("%d",&a[i][j]);
	}st[0][++st[0][0]]=0;
	for(int i=1,fl=1,cnt1=0;i<=m;++i,fl^=1,cnt1=0)
	{
		for(int j=1;j<=b[i];++j)
			if(!vs[a[i][j]]) ++cnt1,vs[a[i][j]]=1;
		while(st[fl^1][0])
		{
			int cnt=0;ull t=st[fl^1][st[fl^1][0]--];
			for(int j=1;j<=b[i];++j) cnt+=t>>a[i][j]-1&1;
			for(int j=1;j<=b[i]-cnt;++j)
				t&=(1ull<<n)-(1ull<<a[i][j]-1)-1;
			for(int j=b[i];j>b[i]-cnt;--j) t|=1ull<<a[i][j]-1;
			st[fl][++st[fl][0]]=t;
			for(int j=b[i]-cnt;j>b[i]-cnt-cnt1;--j)
				t|=1ull<<a[i][j]-1,st[fl][++st[fl][0]]=t;
		}
	}
	for(int i=1;i<=n;++i)
		if(!vs[i]) {puts("REJECTED");return 0;}
	while(st[m&1][0])
	{
		ull t=st[m&1][st[m&1][0]--];
		for(int i=1;i<n;++i) if(t>>i-1&1 && !(t>>i&1))
		{puts("REJECTED");return 0;}
	}puts("ACCEPTED");return 0;
}