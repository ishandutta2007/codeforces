#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using std::min;
const int N=1e5+5,inf=0x3f3f3f3f3f3f3f3f;
int n,x,y,ans,cur;
int bit[N];
inline void add(int x,int k)
{
	while(x<=n)
		bit[x]+=k,x+=x&-x;
	return;
}
inline int ask(int x)
{
	int res=0;
	while(x)
		res+=bit[x],x&=x-1;
	return res;
}
char s[N];
signed main()
{
	register int i;
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%lld%lld",&x,&y);
	cur=0;
	for(i=1;i<=n;i++)
		if(s[i]=='1')
			cur+=x*(i-1-ask(i)),add(i,1);
		else
			cur+=y*ask(i);
	ans=cur;
	for(i=1;i<=n;i++)
		if(s[i]=='?')
		{
			cur-=y*ask(i-1)+x*(ask(n)-ask(i));
			cur+=x*(i-1-ask(i-1))+y*(n-i-(ask(n)-ask(i)));
			add(i,1);ans=min(ans,cur);
		}
	memset(bit,0,sizeof(bit));
	cur=0;
	for(i=1;i<=n;i++)
		if(s[i]!='0')
			cur+=x*(i-1-ask(i)),add(i,1);
		else
			cur+=y*ask(i);
	ans=min(ans,cur);
	for(i=1;i<=n;i++)
		if(s[i]=='?')
		{
			cur-=x*(i-1-ask(i-1))+y*(n-i-(ask(n)-ask(i)));
			cur+=y*ask(i-1)+x*(ask(n)-ask(i));
			add(i,-1);ans=min(ans,cur);
		}
	printf("%lld\n",ans);
	return 0;
}