#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<random>
#include<chrono>
using namespace std;
const long long p=1000000993;
const int bn=2;
int b[bn];
int bpw[bn][500];
int bpwsm[bn][500];
int N;
main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	for(int i=0;i<bn;i++)
	{
		b[i]=rng()%p;
		bpw[i][0]=1;
		bpwsm[i][0]=0;
		for(int j=1;j<500;j++)
		{
			bpw[i][j]=(long long)bpw[i][j-1]*b[i]%p;
			bpwsm[i][j]=(bpw[i][j-1]+bpwsm[i][j-1])%p;
		}
	}
	cin>>N;
	map<string,vector<string> >mp;
	for(int i=0;i<N;i++)
	{
		string s;cin>>s;
		string t=s;
		sort(t.begin(),t.end());
		mp[t].push_back(s);
	}
	long long ans=(long long)N*(N-1)/2*1337;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		int L=it->first.size();
		int n=it->second.size();
		ans-=(long long)n*(n-1)/2*1337;
		ans+=(long long)n*(n-1)/2*2;
		vector<string>S=it->second;
		if(n<=L*26)
		{
			for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
			{
				int l=0;
				while(l<L&&S[i][l]==S[j][l])l++;
				int r=L;
				while(r>0&&S[i][r-1]==S[j][r-1])r--;
				bool fi=true,fj=true;
				for(int k=l+1;k<r;k++)
				{
					if(S[i][k-1]>S[i][k])fi=false;
					if(S[j][k-1]>S[j][k])fj=false;
				}
				if(fi||fj)ans--;
			}
		}
		else
		{
			vector<pair<int,int> >rh(n);
			map<pair<int,int>,int>cnt;
			for(int i=0;i<n;i++)
			{
				int h1=0,h2=0;
				for(int j=0;j<L;j++)
				{
					h1=(h1+(long long)bpw[0][j]*S[i][j])%p;
					h2=(h2+(long long)bpw[1][j]*S[i][j])%p;
				}
				cnt[make_pair(h1,h2)]++;
				rh[i]=make_pair(h1,h2);
			}
			for(int i=0;i<n;i++)
			{
				vector<pair<int,int> >hs;
				int lh1=0,lh2=0;
				int rh1=rh[i].first,rh2=rh[i].second;
				for(int l=0;l<L;l++)
				{
					int nrh1=rh1,nrh2=rh2;
					int cnt[26]={};
					for(int r=l;r<L;r++)
					{
						nrh1=(nrh1+p-(long long)bpw[0][r]*S[i][r]%p)%p;
						nrh2=(nrh2+p-(long long)bpw[1][r]*S[i][r]%p)%p;
						cnt[S[i][r]-'a']++;
						int h1=(lh1+nrh1)%p,h2=(lh2+nrh2)%p;
						int sz=l;
						for(int k=0;k<26;k++)
						{
							h1=(h1+(long long)(bpwsm[0][sz+cnt[k]]-bpwsm[0][sz]+p)*(k+'a'))%p;
							h2=(h2+(long long)(bpwsm[1][sz+cnt[k]]-bpwsm[1][sz]+p)*(k+'a'))%p;
							sz+=cnt[k];
						}
						hs.push_back(make_pair(h1,h2));
					}
					rh1=(rh1+p-(long long)bpw[0][l]*S[i][l]%p)%p;
					rh2=(rh2+p-(long long)bpw[1][l]*S[i][l]%p)%p;
					lh1=(lh1+(long long)bpw[0][l]*S[i][l])%p;
					lh2=(lh2+(long long)bpw[1][l]*S[i][l])%p;
				}
				sort(hs.begin(),hs.end());
				hs.erase(unique(hs.begin(),hs.end()),hs.end());
				for(pair<int,int>p:hs)if(cnt.find(p)!=cnt.end())
				{
					ans-=cnt[p];
				}
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}