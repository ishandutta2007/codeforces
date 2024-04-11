#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;
int N;
int D1[1000],D2[1000];
int H[1000];
int TO[1000];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>D1[i];
		for(int i=0;i<N;i++)cin>>D2[i];
		sort(D1,D1+N);
		sort(D2,D2+N);
		bool fn=false;
		for(int i=0;!fn&&i<N;i++)
		{
			for(int pp:{D1[N-1]+D2[i],abs(D1[N-1]-D2[i])})
			{
				if(fn)continue;
				multiset<int>d2(D2,D2+N);
				TO[N-1]=D2[i];
				d2.erase(d2.find(D2[i]));
				bool out=false;
				for(int j=N-2;j>=0;j--)
				{
					{
						int t=D1[j]+pp;
						if(d2.find(t)!=d2.end())
						{
							d2.erase(d2.find(t));
							TO[j]=t;
							continue;
						}
					}
					{
						int t=abs(D1[j]-pp);
						if(d2.find(t)!=d2.end())
						{
							d2.erase(d2.find(t));
							TO[j]=t;
							continue;
						}
					}
					out=true;
					break;
				}
				if(out)continue;
				int p1=0;
				for(int j=0;j<N;j++)if(D1[j]+TO[j]!=pp)
				{
					assert(abs(D1[j]-TO[j])==pp);
					if(D1[j]<=TO[j])p1=max(p1,D1[j]);
				}
				cout<<"YES\n";
				for(int j=0;j<N;j++)
				{
					if(D1[j]+TO[j]==pp)
					{
						H[j]=p1+D1[j];
					}
					else
					{
						if(D1[j]<=TO[j])H[j]=p1-D1[j];
						else H[j]=p1+D1[j];
					}
					cout<<H[j]<<(j+1==N?"\n":" ");
				}
				cout<<p1<<" "<<p1+pp<<"\n";
				fn=true;
			}
		}
		if(!fn)cout<<"NO\n";
	}
}