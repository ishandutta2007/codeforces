#include<cstdio>
#include<algorithm>
#include<vector>
#define min(a,b) (a<b?a:b)
#define int long long
using std::vector;
using std::pair;
using std::sort;
vector< pair<int,int> >a,b;
int n,s,ans,na,nb,ta,tb;
signed main()
{
	int i,j;
	int ss,aa,bb;
	pair<int,int>k;
	scanf("%I64d%I64d",&n,&s);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&ss,&aa,&bb);
		if(aa>bb)
		{
			ans+=ss*aa;
			na+=ss;
			k.first=aa-bb;
			k.second=ss;
			a.push_back(k);
		}
		else
		{
			ans+=ss*bb;
			nb+=ss;
			k.first=bb-aa;
			k.second=ss;
			b.push_back(k);
		}
	}
	na%=s;nb%=s;
	if(na+nb>s)
	{
		printf("%I64d\n",ans);
		return 0;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(i=0;na;i++)
	{
		ta+=min(na,a[i].second)*a[i].first;
		na-=min(na,a[i].second);
	}
	for(i=0;nb;i++)
	{
		tb+=min(nb,b[i].second)*b[i].first;
		nb-=min(nb,b[i].second);
	}
	ans-=min(ta,tb);
	printf("%I64d\n",ans);
	return 0;
}