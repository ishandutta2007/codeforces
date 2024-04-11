#include<iostream>
#include<vector>
#include<set>
using namespace std;
int N,M;
int S[10000],A[10000];
set<int>G[10000],RG[10000];
vector<int>H[10000];
int cnt[10000];
vector<pair<int,int> >E;
vector<pair<int,int> >ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;u--,v--;
		if(S[u]==0)
		{
			if(S[v]==0)
			{
				ans.push_back(make_pair(u,v));
			}
			else
			{
				H[v].push_back(u);
				cnt[v]++;
			}
		}
		else
		{
			if(S[v]==0)
			{
				H[u].push_back(v);
				cnt[u]++;
			}
			else
			{
				G[u].insert(v);
				RG[v].insert(u);
				//cout<<u+1<<"->"<<v+1<<endl;
				A[u]++;
				A[v]--;
			}
		}
	}
	for(int i=0;i<N;i++)if(S[i]==1)
	{
		int a=abs(A[i]);
		if((cnt[i]-a)%2!=0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	vector<int>Q;
	vector<int>pr(N),tm(N,0);
	int T=0;
	for(int i=0;i<N;i++)if(S[i]==1&&abs(A[i])>cnt[i])
	{
		while(A[i]<-cnt[i])
		{
			Q.clear();
			Q.push_back(i);
			tm[i]=T;
			T++;
			int id=0,U=-1;
			while(id<Q.size())
			{
				int u=Q[id++];
				if(-cnt[u]<=A[u]-2)
				{
					U=u;
					break;
				}
				for(int v:RG[u])if(tm[v]<T)
				{
					tm[v]=T;
					pr[v]=u;
					Q.push_back(v);
				}
			}
			if(U==-1)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			while(U!=i)
			{
				int V=pr[U];
				//cout<<"("<<U+1<<"->"<<V+1<<") -> ("<<V+1<<"->"<<U+1<<")"<<endl;
				RG[V].erase(U);
				G[U].erase(V);
				RG[U].insert(V);
				G[V].insert(U);
				A[U]-=2;
				A[V]+=2;
				U=V;
			}
		}
		while(A[i]>cnt[i])
		{
			Q.clear();
			Q.push_back(i);
			tm[i]=T;
			T++;
			int id=0,U=-1;
			while(id<Q.size())
			{
				int u=Q[id++];
				if(A[u]+2<=cnt[u])
				{
					U=u;
					break;
				}
				for(int v:G[u])if(tm[v]<T)
				{
					tm[v]=T;
					pr[v]=u;
					Q.push_back(v);
				}
			}
			if(U==-1)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			while(U!=i)
			{
				int V=pr[U];
				//cout<<"("<<V+1<<"->"<<U+1<<") -> ("<<U+1<<"->"<<V+1<<")"<<endl;
				G[V].erase(U);
				RG[U].erase(V);
				G[U].insert(V);
				RG[V].insert(U);
				A[U]+=2;
				A[V]-=2;
				U=V;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int v:G[i])ans.push_back(make_pair(i,v));
		for(int v:H[i])
		{
			if(A[i]>=0)
			{
				A[i]--;
				ans.push_back(make_pair(v,i));
			}
			else
			{
				A[i]++;
				ans.push_back(make_pair(i,v));
			}
		}
	}
	cout<<"YES\n";
	for(pair<int,int>e:ans)cout<<e.first+1<<" "<<e.second+1<<"\n";
}