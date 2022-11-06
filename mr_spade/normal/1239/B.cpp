#include<cstdio>
#include<algorithm>
using std::min;
const int N=3e5+5;
int n,ans,p1=1,p2=1;
char s[N];
int sum[N],mnv;
namespace solver1
{
	int pre[N],suc[N],pos[N];
	int lp,rp,cans,cp1=1,cp2=1;
	void main()
	{
		int cur=0;
		register int i;
		for(i=1;i<=n;i++)
			cur+=(sum[i]==mnv);
		for(i=n;i>=1;i--)
			suc[i]=suc[i+1]+(sum[i]==mnv+1);
		for(i=1;i<=n;i++)
			pre[i]=pre[i-1]+(sum[i]==mnv+1);
		pos[n+1]=n+1;
		for(i=n;i>=1;i--)
			if(s[i]=='('&&suc[i]>suc[pos[i+1]])
				pos[i]=i;
			else
				pos[i]=pos[i+1];
		lp=n+1;
		for(i=n;i>=1;i--)
			if(sum[i]==mnv)
				lp=i;
		rp=0;
		for(i=1;i<=n;i++)
			if(sum[i]==mnv)
				rp=i;
		for(i=1;i<=lp;i++)
			if(s[i]==')')
			{
				if(pos[rp+1]!=n+1&&pre[i-1]+suc[pos[rp+1]]>cans)
					cans=pre[i-1]+suc[pos[rp+1]],cp1=i,cp2=pos[rp+1];
			}
		for(i=n;i>=1;i--)
			suc[i]=suc[i+1]+(sum[i]==mnv+2);
		for(i=1;i<=n;i++)
			pre[i]=pre[i-1]+(sum[i]==mnv+2);
		pos[n+1]=n+1;
		for(i=n;i>=1;i--)
			if(s[i]=='('&&suc[i]>suc[pos[i+1]])
				pos[i]=i;
			else
				pos[i]=pos[i+1];
		lp=n+1;
		for(i=n;i>=1;i--)
			if(sum[i]<=mnv+1)
				lp=i;
		rp=0;
		for(i=1;i<=n;i++)
			if(sum[i]<=mnv+1)
				rp=i;
		for(i=1;i<=lp;i++)
			if(s[i]==')')
			{
				if(pos[rp+1]!=n+1&&cur+pre[i-1]+suc[pos[rp+1]]>cans)
					cans=cur+pre[i-1]+suc[pos[rp+1]],cp1=i,cp2=pos[rp+1];
			}
		if(cans>ans)
			ans=cans,p1=cp1,p2=cp2;
		return;
	}
}
namespace solver2
{
	int pre[N],pos[N];
	int cans,cp1=1,cp2=1;
	void main()
	{
		int cur=0,lst=0;
		register int i;
		for(i=1;i<=n;i++)
			if(sum[i]==mnv)
				cur++;
		for(i=n;i>=1;i--)
			pre[i]=pre[i+1]+(sum[i]==mnv+1);
		pos[n+1]=-1;
		for(i=n;i>=1;i--)
		{
			lst=pos[i+1];
			if(sum[i]==mnv)
				lst=-1;
			if(s[i]==')'&&(lst==-1||pre[i]<pre[lst]))
				pos[i]=i;
			else
				pos[i]=lst;
		}
		for(i=1;i<=n;i++)
			if(s[i]=='(')
			{
				if(pos[i]!=-1&&pre[i]-pre[pos[i]]>cans)
					cans=pre[i]-pre[pos[i]],cp1=i,cp2=pos[i];
			}
		for(i=n;i>=1;i--)
			pre[i]=pre[i+1]+(sum[i]==mnv+2);
		pos[n+1]=-1;
		for(i=n;i>=1;i--)
		{
			lst=pos[i+1];
			if(sum[i]<=mnv+1)
				lst=-1;
			if(s[i]==')'&&(lst==-1||pre[i]<pre[lst]))
				pos[i]=i;
			else
				pos[i]=lst;
		}
		for(i=1;i<=n;i++)
			if(s[i]=='(')
			{
				if(pos[i]!=-1&&cur+pre[i]-pre[pos[i]]>cans)
					cans=cur+pre[i]-pre[pos[i]],cp1=i,cp2=pos[i];
			}
		if(cans>ans)
			ans=cans,p1=cp1,p2=cp2;
		return;
	}
}
signed main()
{
	register int i;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+(s[i]=='('?1:-1);
	if(sum[n]!=0)
		return puts("0\n1 1"),0;
	for(i=1;i<=n;i++)
		mnv=min(mnv,sum[i]);
	int cnt=0;
	for(i=1;i<=n;i++)
		cnt+=(sum[i]==mnv);
	ans=cnt;p1=p2=1;
	solver1::main();
	solver2::main();
	printf("%d\n%d %d\n",ans,p1,p2);
	return 0;
}