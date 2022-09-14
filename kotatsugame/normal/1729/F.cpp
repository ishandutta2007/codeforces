#include<iostream>
#include<vector>
using namespace std;
string S;
int sum[2<<17];
int W,M;
vector<int>ids[9];
pair<int,int>ans[9][9];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		for(int i=0;i<9;i++)ids[i].clear();
		cin>>S>>W>>M;
		for(int i=0;i<S.size();i++)sum[i+1]=sum[i]+S[i]-'0';
		for(int L=0;L+W<=S.size();L++)
		{
			ids[(sum[L+W]-sum[L])%9].push_back(L);
		}
		for(int v=0;v<9;v++)for(int k=0;k<9;k++)
		{
			ans[v][k]=make_pair(1e9,1e9);
			for(int i=0;i<9;i++)for(int j=0;j<9;j++)if((i*v+j)%9==k)
			{
				if(ids[i].empty())continue;
				int L1=ids[i][0],L2;
				if(i==j)
				{
					if(ids[j].size()<2)continue;
					L2=ids[j][1];
				}
				else
				{
					if(ids[j].empty())continue;
					L2=ids[j][0];
				}
				ans[v][k]=min(ans[v][k],make_pair(L1+1,L2+1));
			}
			if(ans[v][k].first==(int)1e9)ans[v][k]=make_pair(-1,-1);
		}
		for(;M--;)
		{
			int l,r,k;cin>>l>>r>>k;
			pair<int,int>p=ans[(sum[r]-sum[l-1])%9][k];
			cout<<p.first<<" "<<p.second<<"\n";
		}
	}
}