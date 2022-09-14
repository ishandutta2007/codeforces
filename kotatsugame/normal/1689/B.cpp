#include<iostream>
#include<set>
using namespace std;
int T,N;
int P[1000],Q[1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>P[i];
		if(N==1)
		{
			cout<<"-1\n";
			continue;
		}
		set<int>S;
		for(int i=1;i<=N;i++)S.insert(i);
		for(int i=0;i+1<N;i++)
		{
			auto it=S.begin();
			if(*it==P[i])it++;
			Q[i]=*it;
			S.erase(it);
		}
		int u=*S.begin();S.erase(S.begin());
		if(P[N-1]!=u)Q[N-1]=u;
		else
		{
			Q[N-1]=Q[N-2];
			Q[N-2]=u;
		}
		for(int i=0;i<N;i++)cout<<Q[i]<<(i+1==N?"\n":" ");
	}
}