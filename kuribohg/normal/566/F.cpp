#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000000;
const int MAXN=1000010;
int n,a[MAXN],f[MAXN],c[MAXN],ans;
int head[MAXN],to[MAXN*14],next[MAXN*14],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j+=i)
			adde(j,i);
	for(int i=1;i<=n;i++)
	{
		for(int j=head[a[i]];j;j=next[j])
			f[i]=max(f[i],c[to[j]]+1);
		c[a[i]]=max(c[a[i]],f[i]);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}