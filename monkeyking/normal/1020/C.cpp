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
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(ll qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
typedef unsigned long long ull;
//const long long inf=1037240000082LL;
using namespace std;
ll n,m;
pair<ll,ll> a[3005];//votes and index
ll v[3005];//votes for each party
vector <ll> vec[3005];
//set <ll> mc;
priority_queue<ll,vector <ll>,greater<ll> >mc;

bool compare(pll a,pll b)
{
	return a>b;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	if(m==1) over(0);
	ll x,y;
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		x--;
		v[x]++;
		vec[x].push_back(y);
		if(x) mc.push(y);
	}
//	cout<<mc.size()<<endl;
//	if(n==3000 && m==3000 && vec[2792].size() && vec[2792][0]==58) over(6);//shit
	for(ll i=0;i<m;i++)
	{
		a[i].first=v[i];
		a[i].second=i;
		sort(all(vec[i]));
	}
	sort(a,a+m,compare);
	if(a[0].second==0 && a[0].first>a[1].first) over(0);
	ll need=a[0].first-v[0]+1;
	ll tneed;
	priority_queue <ll,vector<ll>,greater<ll> > tmc;
	ll res=541885418851154LL;
	ll cost;
//	cout<<need<<endl;
//	for(ll i=0;i<m;i++)
//	{
//		for(ll j=0;j<vec[i].size();j++)
//		{
//			cout<<vec[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<"F";
//	mc.insert(9489403875LL);
//	mc.insert(9489403875LL);
//	mc.insert(9489030875LL);
//	mc.insert(9489430875LL);
//	mc.insert(94894300875LL);
//	mc.insert(9489430875LL);
//	mc.insert(9489430875LL);
//	mc.insert(9489403875LL);
//	mc.insert(9489430875LL);
//	mc.insert(9489430875LL);
//	mc.insert(9489403875LL);
//	mc.insert(9489403875LL);
//	mc.insert(9489403875LL);
//	mc.insert(9489430875LL);
//	mc.insert(9489438075LL);
//	mc.insert(9489438075LL);
//	mc.insert(9489430875LL);
//	mc.insert(9489430875LL);
//	mc.insert(9489430875LL);
//cout<<"F";
//	cout<<mc.size()<<endl;
	for(ll i=0;i<=a[0].first;i++) 
	{
//		cout<<i<<endl;
		cost=0;
		while(tmc.size())
		{
			tmc.pop();
		}
//		tmc=mc;
		tneed=need;
		if(tneed<=0)
		{
			res=0;
			break;
		}
		ll debug=(i==2);
		for(ll j=0;j<m;j++)
		{
//			cout<<j<<endl;
			ll tj=a[j].second;
			for(ll k=max(v[tj]-i,0LL);k<v[tj];k++)
			{
				if(tj!=0) tmc.push(vec[tj][k]);
			}
//			if(debug) cout<<v[j]<<' ';
			if(v[tj]<=i) continue;
//			if(debug) cout<<j<<endl;
			for(ll k=0;k<v[tj]-i;k++)
			{
//				cout<<k<<endl;
				cost+=vec[tj][k];
//				tmc.pop();
//				tmc.erase(vec[tj][k]);
				tneed--;
				if(tneed==0) break;
			}
//			cout<<v[tj]-i<<endl;
			if(tneed==0) break;
		}
//		if(debug)
//		{
//			while(tmc.size())
//			{
//				cout<<tmc.top()<<' ';
//				tmc.pop();
//			}
//			cout<<endl;
//			break;
//		}
//		if(debug) cout<<tneed<<endl;
//		cout<<tneed<<' '<<i<<endl;
		tneed-=a[0].first-i;
//		if(debug) cout<<tneed<<endl;
//		cout<<tneed<<' '<<i<<endl<<endl;
		if(tneed<=0)
		{
//		    cout<<cost<<' '<<i<<endl;
			res=min(res,cost);
			continue;
		}
//		if(debug) cout<<tmc.size()<<endl;
//		set <ll> :: iterator it=tmc.begin();
//		if(debug) cout<<*it;
//				cout<<"F";
//		cout<<tmc.size()<<endl;
		for(ll j=0;j<tneed;j++)
		{
//			cout<<tneed<<endl;
//			cout<<"FICK";
//			cout<<(*it)<<endl;
			cost+=tmc.top();
			tmc.pop();
//		cout<<endl;
		}
//				cout<<"UCK\n";
//		cout<<cost<<'-'<<i<<endl;
//		cout<<i<<' '<<cost<<endl;
		res=min(res,cost);
	}
/*
5 5
1 7
3 3
2 7
2 4
1 2
*/
    cout<<res<<endl;
	return 0;
}