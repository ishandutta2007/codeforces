#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<bitset>
using namespace std;
const int mod=1e9+7;
const int inv2=5e8+4;
int p2[1<<17],invp2[1<<17];
int Tsum[26][1<<17];
int N,Q;
string S,T;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q>>S>>T;
	p2[0]=invp2[0]=1;
	for(int i=1;i<=N;i++)
	{
		p2[i]=p2[i-1]*2%mod;
		invp2[i]=invp2[i-1]*(long long)inv2%mod;
	}
	const int W=S.size()+1;
	bitset<100>Stest[26];
	for(int i=0;i<S.size();i++)Stest[S[i]-'a'][i]=1;
	for(int c=0;c<26;c++)
	{
		for(int i=0;i<T.size();i++)
		{
			Tsum[c][i+1]=Tsum[c][i];
			if(T[i]-'a'==c)(Tsum[c][i+1]+=invp2[i+1])%=mod;
		}
	}
	for(int ccc=0;ccc<Q;ccc++)
	{
		int k;
		string w;
		cin>>k>>w;
		int ans=0;
		vector<pair<string,int> >pos;
		{
			string ok(W,'?');
			for(int i=0;i<w.size();i++)
			{
				int id=i%W;
				if(ok[id]=='?')ok[id]=w[i];
				else if(ok[id]!=w[i])ok[id]='$';
			}
			bitset<100>now;
			for(int i=0;i<W;i++)
			{
				now<<=1;
				now[0]=1;
				if(ok[i]=='$')now.reset();
				else if(ok[i]!='?')now&=Stest[ok[i]-'a'];
			}
			for(int i=0;i<W;i++)
			{
				now<<=1;
				now[0]=1;
				if(ok[i]=='$')now.reset();
				else if(ok[i]!='?')now&=Stest[ok[i]-'a'];
				if(now[S.size()-1]==1)
				{
					string tmp="";
					for(int k=(i+1)%W;k<w.size();k+=W)tmp+=w[k];
					pos.push_back(make_pair(tmp,1));
				}
			}
		}
		for(int tid=0;!pos.empty()&&tid<=k;tid++)
		{
			sort(pos.begin(),pos.end());
			vector<pair<string,int> >nxt;
			for(int l=0;l<pos.size();)
			{
				int r=l;
				long long sum=0;
				string now=pos[l].first;
				while(r<pos.size()&&now==pos[r].first)sum+=pos[r++].second;
				l=r;
				sum%=mod;
				if(now.size()==0)
				{
					ans=(ans+p2[k-tid]*sum)%mod;
					continue;
				}
				else if(now.size()==1)
				{
					int c=now[0]-'a';
					ans=(ans+(Tsum[c][k]-Tsum[c][tid]+mod)%mod*(long long)p2[k]%mod*sum)%mod;
					continue;
				}
				string ok(2,'?');
				for(int i=0;i<now.size();i++)
				{
					if(ok[i%2]=='?')ok[i%2]=now[i];
					else if(ok[i%2]!=now[i])ok[i%2]='$';
				}
				for(int st=0;st<2;st++)
				{
					if(ok[st]=='?'||ok[st]==T[tid])
					{
						string nx="";
						for(int j=1-st;j<now.size();j+=2)nx+=now[j];
						nxt.push_back(make_pair(nx,(int)sum));
					}
				}
			}
			pos.swap(nxt);
		}
		cout<<ans<<"\n";
	}
}