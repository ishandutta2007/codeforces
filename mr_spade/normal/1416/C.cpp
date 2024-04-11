#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
const int N=1e7+5,M=3e5+5;
int tot=1;
int sum[N],ch[N][2];
int run[60][2];
void insert(int x,int d,int k)
{
	int t=k>>(d-1)&1;
	if(d==0)
		goto end;
	if(!ch[x][t])
		ch[x][t]=++tot;
	run[d-1][t]+=sum[ch[x][t^1]];
	insert(ch[x][t],d-1,k);
	end:;
	sum[x]++;
	return;
}
int n;
int a[M];
signed main()
{
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]),insert(1,31,a[i]);
	int ans1=0,ans2=0;
	for(i=0;i<=30;i++)
	{
		ans1+=std::min(run[i][0],run[i][1]);
		if(run[i][1]<run[i][0])
			ans2+=1<<i;
	}
	printf("%lld %lld\n",ans1,ans2);
}