#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long S[1<<17];
int X[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,Q;
		cin>>N>>Q;
		vector<pair<int,int> >A;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			if(a>0)A.push_back(make_pair(i,a));
		}
		for(int i=0;i<A.size();i++)
		{
			S[i+1]=S[i]+A[i].second;
			X[i+1]=X[i]^A[i].second;
		}
		for(;Q--;)
		{
			int L,R;cin>>L>>R;L--;
			int lt=lower_bound(A.begin(),A.end(),make_pair(L,0))-A.begin();
			int rt=lower_bound(A.begin(),A.end(),make_pair(R,0))-A.begin();
			if(lt>=rt)
			{
				cout<<L+1<<" "<<L+1<<"\n";
				continue;
			}
			long long F=(S[rt]-S[lt])-(X[rt]^X[lt]);
			int al=A[lt].first,ar=A[rt-1].first;
			for(int l=lt;l<=lt+30&&l<rt;l++)
			{
				for(int r=rt;r>=rt-30&&l<r;r--)
				{
					long long f=(S[r]-S[l])-(X[r]^X[l]);
					int nl=A[l].first,nr=A[r-1].first;
					if(f>F||f==F&&ar-al>nr-nl)
					{
						F=f;
						al=nl,ar=nr;
					}
				}
			}
			if(F<=0)
			{
				cout<<L+1<<" "<<L+1<<"\n";
				continue;
			}
			cout<<al+1<<" "<<ar+1<<"\n";
		}
	}
}