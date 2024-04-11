#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;
int N;
int XOR[1000];
int ask(vector<int>s)
{
	for(int i=0;i<N;i++)cout<<(XOR[i]^s[i]?'T':'F');
	cout<<endl;
	int k;cin>>k;
	if(k==(int)s.size()||k==-1)exit(0);
	return k;
}
int ans[1000];
const int W=4;
int ASK[1<<W][1<<W];
double dp[1<<(1<<W)];
int need[1<<(1<<W)];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int s=0;s<1<<W;s++)
	{
		for(int t=0;t<1<<W;t++)
		{
			ASK[t][s]=__builtin_popcount(s^t^((1<<W)-1));
		}
		int v=ASK[0][s];
		for(int t=0;t<1<<W;t++)ASK[t][s]-=v;
	}
	for(int i=0;i<1<<(1<<W);i++)
	{
		if(__builtin_popcount(i)<=1)
		{
			dp[i]=0;
			continue;
		}
		dp[i]=1e150;
		vector<int>si;
		for(int s=0;s<1<<W;s++)if(i>>s&1)si.push_back(s);
		for(int t=0;t<1<<W;t++)
		{
			vector<pair<int,int> >mp(si.size());
			for(int j=0;j<si.size();j++)mp[j]=make_pair(ASK[t][si[j]],1<<si[j]);
			sort(mp.begin(),mp.end());
			double now=0;
			for(int j=0;j<mp.size();)
			{
				int k=j;
				int p=0;
				while(k<mp.size()&&mp[j].first==mp[k].first)p|=mp[k++].second;
				now+=dp[p]*(k-j);
				j=k;
			}
			now/=si.size();
			now+=1;
			if(dp[i]>now)
			{
				dp[i]=now;
				need[i]=t;
			}
		}
	}
	cin>>N;
	{
		random_device rng;
		for(int i=0;i<N;i++)XOR[i]=rng()%2;
	}
	int A=ask(vector<int>(N,0));
	for(int i=0;i<N;)
	{
		if(i+W>N)
		{
			vector<int>s(N,0);
			s[i]=1;
			int B=ask(s);
			if(A<B)ans[i]=1;
			i++;
			continue;
		}
		int now=(1<<(1<<W))-1;
		while(__builtin_popcount(now)>=2)
		{
			int t=need[now];
			vector<int>s(N,0);
			for(int j=0;j<W;j++)s[i+j]=t>>j&1;
			int B=ask(s);
			int nxt=0;
			for(int s=0;s<1<<W;s++)if(now>>s&1&&ASK[t][s]==B-A)nxt|=1<<s;
			now=nxt;
		}
		int s=0;
		while(!(now>>s&1))s++;
		for(int j=0;j<W;j++)ans[i+j]=s>>j&1;
		i+=W;
	}
	ask(vector<int>(ans,ans+N));
}