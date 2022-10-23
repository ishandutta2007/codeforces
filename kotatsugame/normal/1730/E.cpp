#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int A[5<<17];
vector<int>divisor[1<<20];
vector<int>pos[1<<20];
int posid[1<<20];
int L[5<<17],R[5<<17];
int Ll[5<<17],Rl[5<<17];
int Lg[5<<17],Rg[5<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<=1000000;i++)
	{
		for(int j=i;j<=1000000;j+=i)divisor[j].push_back(i);
	}
	int T;cin>>T;
	for(;T--;)
	{
		for(int i=1;i<=1000000;i++)
		{
			pos[i].clear();
			posid[i]=-1;
		}
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			pos[A[i]].push_back(i);
		}
		{
			vector<pair<int,int> >S;
			S.push_back(make_pair(0,-1));
			for(int i=0;i<N;i++)
			{
				while(S.back().first>=A[i])S.pop_back();
				Ll[i]=S.back().second;
				S.push_back(make_pair(A[i],i));
			}
		}
		{
			vector<pair<int,int> >S;
			S.push_back(make_pair(0,N));
			for(int i=N;i--;)
			{
				while(S.back().first>=A[i])S.pop_back();
				Rl[i]=S.back().second;
				S.push_back(make_pair(A[i],i));
			}
		}
		{
			vector<pair<int,int> >Ai(N);
			for(int i=0;i<N;i++)
			{
				L[i]=i-1,R[i]=i+1;
				Ai[i]=make_pair(A[i],i);
			}
			sort(Ai.begin(),Ai.end());
			long long ans=0;
			for(pair<int,int>p:Ai)
			{
				int id=p.second;
				Lg[id]=L[id];Rg[id]=R[id];
				if(L[id]>=0)R[L[id]]=R[id];
				if(R[id]<N)L[R[id]]=L[id];
			}
		}
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			int a=A[i];
			for(int d:divisor[a])
			{
				while(posid[d]+1<pos[d].size()&&pos[d][posid[d]+1]<=i)posid[d]++;
				int mL=Lg[i];
				if(posid[d]>=0)
				{
					int j=pos[d][posid[d]];
					int l=max(mL,Ll[j]);
					int r=min(Rg[i],Rl[j]);
					if(l<j&&i<r)ans+=(long long)(r-i)*(j-l);
					if(mL<j)mL=j;
				}
				if(posid[d]+1<pos[d].size())
				{
					int j=pos[d][posid[d]+1];
					int l=max(mL,Ll[j]);
					int r=min(Rg[i],Rl[j]);
					if(l<i&&j<r)ans+=(long long)(r-j)*(i-l);
				}
			}
		}
		cout<<ans<<"\n";
	}
}