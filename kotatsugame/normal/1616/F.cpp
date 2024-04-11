#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,M;
int U[256],V[256],C[256];
int col[64][64];
vector<vector<int> >dat;
void solve()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)col[i][j]=-1;
	for(int i=0;i<M;i++)
	{
		cin>>U[i]>>V[i]>>C[i];
		U[i]--,V[i]--;
		if(C[i]>0)C[i]--;
		col[U[i]][V[i]]=col[V[i]][U[i]]=i;
	}
	vector<vector<pair<int,int> > >G;
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
	{
		if(col[i][j]==-1)continue;
		for(int k=j+1;k<N;k++)
		{
			if(col[i][k]==-1||col[j][k]==-1)continue;
			int a=col[i][j],b=col[j][k],c=col[i][k];
			int sum=0;
			G.emplace_back();
			if(C[a]==-1)G.back().push_back(make_pair(a,1));
			else sum-=C[a];
			if(C[b]==-1)G.back().push_back(make_pair(b,1));
			else sum-=C[b];
			if(C[c]==-1)G.back().push_back(make_pair(c,1));
			else sum-=C[c];
			sum=(sum%3+3)%3;
			if(sum!=0)G.back().push_back(make_pair(M,sum));
		}
	}
	dat.assign(G.size(),vector<int>(M+1,0));
	for(int i=0;i<G.size();i++)
	{
		for(int j=0;j<G[i].size();j++)dat[i][G[i][j].first]=G[i][j].second;
	}
	int rank=0;
	vector<int>H(M,-1);
	{
		vector<int>tmp;
		for(int j=0;j<=M;j++)if(j==M||C[j]==-1)
		{
			int id=-1;
			for(int i=rank;i<G.size();i++)
			{
				if(dat[i][j]!=0)
				{
					id=i;
					break;
				}
			}
			if(id==-1)continue;
			if(j==M)
			{
				cout<<"-1\n";
				return;
			}
			if(id!=rank)dat[rank].swap(dat[id]);
			H[j]=rank;
			{
				tmp.clear();
				const int a=dat[rank][j];
				for(int k=j;k<=M;k++)if(dat[rank][k]!=0)
				{
					tmp.push_back(k);
					dat[rank][k]=dat[rank][k]*a%3;
				}
			}
			for(int i=0;i<G.size();i++)
			{
				if(i==rank||dat[i][j]==0)continue;
				const int a=dat[i][j];
				for(int k:tmp)dat[i][k]=(dat[i][k]-dat[rank][k]*a%3+3)%3;
			}
			rank++;
		}
	}
	for(int j=M;j--;)if(C[j]==-1)
	{
		if(H[j]==-1)C[j]=0;
		else
		{
			int id=H[j];
			int sum=dat[id][M];
			for(int k=j+1;k<M;k++)sum-=dat[id][k]*C[k];
			C[j]=(sum%3+3)%3;
		}
	}
	for(int j=0;j<M;j++)cout<<C[j]+1<<(j+1==M?"\n":" ");
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)solve();
}