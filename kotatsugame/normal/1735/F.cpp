#include<iostream>
#include<map>
#include<iomanip>
using namespace std;
struct dat{
	int p,q;
	bool operator<(const dat&rhs)const
	{//-q/p>-rhs.q/rhs.p
		return -(long long)q*rhs.p>-(long long)rhs.q*p;
	}
};
int N,A,B;
int P[3<<17],Q[3<<17];
const long double EPS=1e-9;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>A>>B;
		for(int i=0;i<N;i++)cin>>P[i];
		for(int i=0;i<N;i++)cin>>Q[i];
		multimap<dat,pair<long double,long double> >len;
		long double sx=A,sy=B;
		long double tx=A,ty=B;
		for(int i=0;i<N;i++)
		{
			sx-=P[i];tx+=P[i];
			sy+=Q[i];ty-=Q[i];
			len.insert(make_pair(dat{P[i],Q[i]},make_pair(P[i]*2,Q[i]*2)));
			while(!len.empty())
			{
				auto it=len.begin();
				dat t=it->first;
				long double l=it->second.first;
				if(sx+l<EPS)
				{
					sx+=it->second.first;
					sy-=it->second.second;
					len.erase(it);
					continue;
				}
				if(sx<EPS)
				{
					long double x=-sx;
					long double y=x*t.q/t.p;
					it->second.first-=x;
					it->second.second-=y;
					sx+=x;
					sy-=y;
				}
				break;
			}
			while(!len.empty())
			{
				auto it=len.end();it--;
				dat t=it->first;
				long double l=it->second.second;
				if(ty+l<EPS)
				{
					tx-=it->second.first;
					ty+=it->second.second;
					len.erase(it);
					continue;
				}
				if(ty<EPS)
				{
					long double y=-ty;
					long double x=y/t.q*t.p;
					it->second.first-=x;
					it->second.second-=y;
					tx-=x;
					ty+=y;
				}
				break;
			}
			cout<<fixed<<setprecision(16)<<tx<<"\n";
		}
	}
}