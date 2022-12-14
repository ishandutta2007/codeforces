#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

#define ll long long
#define inf 1e9
#define eps 1e-10
#define md
#define N 2010
using namespace std;
int pre[N],next[N],left[N],right[N];
int main()
{
	int L,B,F;
	scanf("%d%d%d",&L,&B,&F);
	pre[1]=0; next[1]=2; right[1]=-B;
	pre[2]=1; next[2]=0; left[2]=L+F;
	int n,len,ty;
	scanf("%d",&n);
	int tot=2;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&ty,&len);
		if (ty==2)
		{
			len+=2;
			next[pre[len]]=next[len]; pre[next[len]]=pre[len];
		}
		else
		{
			tot=i+2;
			for (int x=1;next[x];x=next[x])
			{
				if (left[next[x]]-right[x]>=len+B+F)
				{
					int y=next[x];
					next[x]=pre[y]=tot;
					pre[tot]=x; next[tot]=y;
					left[tot]=right[x]+B; right[tot]=left[tot]+len;
					printf("%d\n",left[tot]); len=-1;
					break;
				}
			}
			if (len!=-1) printf("-1\n");
		}
	}
	return 0;
}