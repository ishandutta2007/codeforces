#include<cstdio>
#include<algorithm>
#include<utility>
#include<deque>
using std::min;
using std::pair;
using std::make_pair;
using std::deque;
#define int long long
const int N=3e5+5;
int n,q,last,pre,ansp,anss,ans;
int tag;
deque<pair<int,int> > V;
signed main()
{
	int opt,k,s,b;
	register int i;
	scanf("%lld%lld",&n,&q);
	pre=n;
	while(q--)
	{
		scanf("%lld",&opt);
		if(opt==1)
		{
			scanf("%lld",&k);
			pre+=k;ansp=0;
		}
		else if(opt==2)
		{
			scanf("%lld",&k);
			while((int)V.size()>=2&&(-last*tag-anss-V[0].second)*(V[0].first-V[1].first)<=(V[0].second-V[1].second)*(last-V[0].first))
				V.pop_front();
			V.push_front(make_pair(last,-last*tag-anss));
			last+=k;
		}
		else
		{
			scanf("%lld%lld",&b,&s);
			ansp+=b;b+=pre*s;
			anss+=b;tag+=s;
		}
		while((int)V.size()>=2&&V[0].first*tag+V[0].second+anss>=V[1].first*tag+V[1].second+anss)
			V.pop_front();
		if(V.empty()||ansp<=V[0].first*tag+V[0].second+anss)
			printf("%lld %lld\n",1ll,ansp);
		else
			printf("%lld %lld\n",pre+V[0].first+1,V[0].first*tag+V[0].second+anss);
	}
	return 0;
}