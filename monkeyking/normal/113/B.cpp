#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
vector <int> vec[2005];
bool is[2005][2005];
map <ll,bool> hash;

int main()
{
//	freopen("input.txt","r",stdin);
	string c;
	string st,en;
	vector <int> vs;
	vector <int> ve;
	cin>>c>>st>>en;
	int lc=c.size(),ls=st.size(),le=en.size();
	bool f;
	for(int i=0;i<=lc-ls;i++)
	{
		f=true;
		for(int j=i;j<i+ls;j++)
		{
//			cout<<c[i]<<'-'<<c[j]<<endl;
			if(c[j]!=st[j-i])
			{
//				cout<<i<<'-'<<j<<endl;
				f=false;
				break;
			}
		}
		if(f) vs.push_back(i);
	}
	for(int i=0;i<=lc-le;i++)
	{
		f=true;
		for(int j=i;j<i+le;j++)
		{
			if(c[j]!=en[j-i])
			{
				f=false;
				break;
			}
		}
		if(f) ve.push_back(i);
	}
//	rep(vs.size())
//	{
//		cout<<vs[i]<<' ';
//	}
//	cout<<endl;
//	rep(ve.size())
//	{
//		cout<<ve[i]<<' ';
//	}
//	cout<<endl;
	int lens=vs.size(),lene=ve.size();
	for(int i=0;i<lens;i++)
	{
		for(int j=0;j<lene;j++)
		{
//			cout<<i<<' '<<j<<endl;
			if(vs[i]>ve[j]) continue;
//			cout<<i<<' '<<j<<endl;
			if(vs[i]+ls>ve[j]+le) continue;
//			cout<<i<<' '<<j<<endl;
			vec[vs[i]].push_back(ve[j]);
		}
	}
	for(int i=0;i<lc;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			is[i][vec[i][j]]=true;
		}
	}
	ll now=0;
	int ans=0;
	vector <ll> vv;
	for(int i=0;i<lc;i++)
	{
		now=0;
		for(int j=i;j<lc;j++)
		{
			now=now*107+c[j];
			if(is[i][j])
			{
				vv.push_back(now);
//				if(!hash[now])
//				{
//					ans++;
//					hash[now]=true;
//				}
			}
//			cout<<is[i][j]<<' ';
		}
//		cout<<endl;
	}
	sort(vv.begin(),vv.end());
	cout<<(unique(vv.begin(),vv.end())-vv.begin())<<endl;
//	cout<<ans<<endl;
	return 0;
}