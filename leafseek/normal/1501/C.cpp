#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=200000+5,MaxS=2500000+5,Border=100000000;
int org[MaxN];
int f[MaxS<<1][4];
int g[MaxS<<1][4];
vector<int> pit[MaxS];
int a[MaxN],rev[MaxN];
int main()
{
	register int n,m=0,k=0;
	scanf("%d",&n);
	rep(i,1,n)
		scanf("%d",&a[i]),org[i]=a[i],m=max(m,a[i]);
	rep(i,0,m)
		pit[i].push_back(0);
	rep(i,1,n)
		++pit[a[i]][0],pit[a[i]].push_back(i);
	register int pos=0;
	rep(i,0,m)
	{
		if(pit[i][0]>=4)
		{
			printf("YES\n");
			printf("%d %d %d %d\n",pit[i][1],pit[i][2],pit[i][3],pit[i][4]);
			assert(org[pit[i][1]]+org[pit[i][2]]==org[pit[i][3]]+org[pit[i][4]]);
			return 0;
		}
		if(pit[i][0]>=2)
		{
			if(pos!=0)
			{
				printf("YES\n");
				printf("%d %d %d %d\n",pit[pos][1],pit[i][1],pit[pos][2],pit[i][2]);
				assert(org[pit[i][1]]+org[pit[pos][1]]==org[pit[i][2]]+org[pit[pos][2]]);
				return 0;
			}
			pos=i;
		}
		rep(j,1,pit[i][0])
			++k,a[k]=i,rev[k]=pit[i][j];
	}
	register int cnt=0,Sum;
	rep(i,1,k-1)
		rep(j,i+1,k)
		{
			++cnt;
			if(cnt>=Border)
			{
				printf("NO\n");
				return 0;
			}
			Sum=(a[i]+a[j]);
			rep(x,1,f[Sum][0])
			{
				if(i!=f[Sum][x]&&i!=g[Sum][x]&&j!=f[Sum][x]&&j!=g[Sum][x])
				{
					printf("YES\n");
					printf("%d %d %d %d\n",rev[i],rev[j],rev[f[Sum][x]],rev[g[Sum][x]]);
					assert(org[rev[i]]+org[rev[j]]==org[rev[f[Sum][x]]]+org[rev[g[Sum][x]]]);
					return 0;
				}
			}
			++f[Sum][0],f[Sum][f[Sum][0]]=i;
			g[Sum][f[Sum][0]]=j;
		}
	printf("NO\n");
	return 0;
}