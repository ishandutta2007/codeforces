#include <bits/stdc++.h>
using namespace std;
#define N 2005
int n,m,c,a[N],b[N],ans[N];char op[N];bitset<N> z1,z[N];
bool ins()
{
	for(int i=1;i<=n*2;++i) if(z1[i])
	{if(z[i][i]) z1^=z[i];else {z[i]=z1;break;}}
	return z1.count()>1 || !z1[0];
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) a[i]=1,a[n+i]=2;
	for(int i=1;i<=m;++i)
	{
		scanf("%s %d",op,&c);
		for(int j=1;j<=c;++j) scanf("%d",&b[j]);
		if(op[0]=='m')
		{
			scanf("%s",op);z1=0;
			for(int j=1;j<=c;++j)
			{
				if(a[b[j]]&1) z1[b[j]]=1;
				if(a[b[j]]&2) z1[n+b[j]]=1;
			}if(op[0]=='R' || op[0]=='B') z1[0]=1;
			if(!ins()) {puts("NO");return 0;}z1=0;
			for(int j=1;j<=c;++j)
			{
				if(a[n+b[j]]&1) z1[b[j]]=1;
				if(a[n+b[j]]&2) z1[n+b[j]]=1;
			}if(op[0]=='Y' || op[0]=='B') z1[0]=1;
			if(!ins()) {puts("NO");return 0;}
		}
		else if(op[0]=='R' && op[1]=='B')
			for(int j=1;j<=c;++j) a[n+b[j]]^=a[b[j]];
		else if(op[0]=='Y' && op[1]=='B')
			for(int j=1;j<=c;++j) a[b[j]]^=a[n+b[j]];
		else for(int j=1;j<=c;++j) swap(a[b[j]],a[n+b[j]]);
	}for(int i=1;i<=n*2;++i) if(!z[i][i]) z[i][i]=1;
	for(int i=n*2;i;--i) for(int j=i+1;j<=n*2;++j)
		if(z[i][j]) z[i][0]=z[i][0]^z[j][0];puts("YES");
	for(int i=1;i<=n;++i)
		if(z[n+i][0]) putchar(z[i][0]?'B':'Y');
		else putchar(z[i][0]?'R':'.');return 0;
}