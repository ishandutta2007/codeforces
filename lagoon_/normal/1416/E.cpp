#include<bits/stdc++.h>
#define re register
struct seg
{
	long long l,r;
	inline bool operator < (const seg&A)const{return l<A.l;}
};
std::multiset<seg>ss;
#define IT std::multiset<seg>::iterator
int nw;
long long k=1,b,v[500100];
int main()
{
	re int n,T;
	scanf("%d",&T);
	for(;T--;)
	{
		re IT it;
		k=1;b=0;nw=0;ss.clear();
		scanf("%d",&n);
		for(re int i=1;i<=n;i++)scanf("%lld",&v[i]);
		for(re int i=1;i<=n;i++)
		{
			if(v[i]%2==0)
			{
				re long long nc=(v[i]/2-b)/k;
				it=ss.upper_bound((seg){nc,nc});
				if(it!=ss.begin())
				{
					it--;
					if(it->l<=nc&&it->r>=nc)
					{
						ss.clear();k=1;b=0;nw+=2;
						ss.insert((seg){v[i]/2,v[i]/2});
						continue;
					}
				}
			}
			k=-k;b=v[i]-b;
			for(;!ss.empty();)
			{
				re long long ll1=k*ss.begin()->l+b,rr1=k*ss.begin()->r+b;
				ss.erase(ss.begin());
				if(ll1>rr1)std::swap(ll1,rr1);
				ll1=std::max(ll1,1ll);rr1=std::min(rr1,v[i]-1ll);
				if(ll1>rr1)continue;
				ll1=(ll1-b)/k;rr1=(rr1-b)/k;
				if(ll1>rr1)std::swap(ll1,rr1);
				ss.insert((seg){ll1,rr1});break;
			}
			for(;!ss.empty();)
			{
				re long long ll1=k*ss.rbegin()->l+b,rr1=k*ss.rbegin()->r+b;
				ss.erase(--ss.end());
				if(ll1>rr1)std::swap(ll1,rr1);
				ll1=std::max(ll1,1ll);rr1=std::min(rr1,v[i]-1ll);
				if(ll1>rr1)continue;
				ll1=(ll1-b)/k;rr1=(rr1-b)/k;
				if(ll1>rr1)std::swap(ll1,rr1);
				ss.insert((seg){ll1,rr1});break;
			}
			if(v[i]%2==0)
			{
				re long long nc=(v[i]/2-b)/k;
				ss.insert((seg){nc,nc});
			}
			if(ss.empty())
			{
				k=1;b=0;ss.insert((seg){1,v[i]-1});
			}
			else nw++;
		}
		printf("%d\n",2*n-nw);
	}
}