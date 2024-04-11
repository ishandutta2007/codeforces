#include<cstdio>
#include<cstring>
typedef long long ll;
char base[100]="\0What are you doing at the end of the world? Are you busy? Will you save us?";
char begin[100]="\0What are you doing while sending \"";
char mid[100]="\0\"? Are you busy? Will you send \"";
char end[100]="\0\"?";
char ans[100];
int q;
ll n,k,tot;
ll f[100];
ll lb=strlen(begin+1),lba=strlen(base+1),lm=strlen(mid+1),le=strlen(end+1);
void solve(ll now,ll &k)
{
	if(k<=lb*now)
	{
		k%=lb;
		if(!k)
			k=lb;
		ans[++tot]=begin[k];
		return;
	}
	k-=lb*now;
	if(k<=lba)
	{
		ans[++tot]=base[k];
		return;
	}
	k-=lba;
	int cnt(0);
	while(k>lm+f[cnt]+le)
		k-=lm+f[cnt]+le,cnt++;
	if(k<=lm)
	{
		ans[++tot]=mid[k];
		return;
	}
	k-=lm;
	if(k>f[cnt])
	{
		k-=f[cnt];
		ans[++tot]=end[k];
		return;
	}
	solve(cnt,k);
	return;
}
signed main()
{
	scanf("%d",&q);
	f[0]=75;
	for(int i=1;i<=53;i++)
		f[i]=(f[i-1]<<1)+68;
	while(q--)
	{
		scanf("%I64d%I64d",&n,&k);
		if(n<=53&&f[n]<k)
		{
			ans[++tot]='.';
			continue;
		}
		solve(n,k);
	}
	puts(ans+1);
	return 0;
}