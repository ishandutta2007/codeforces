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
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
ll n;
ll start,page;
ll end;
set <ll> appear;
ll tt;
ll finish[50005];

struct form
{
	ll start_time;
	ll page;
	ll priority;
	ll num;
}a[50005],t[50005];

bool compare(form a,form b)
{
	return a.priority<b.priority;
}

bool compare2(form a,form b)
{
	return a.start_time<b.start_time;
}

void print(ll k,ll n,form a[])
{
//	cout<<k<<endl;
	priority_queue <pair<ll,pll> >que;
//	priority_queue <pair<ll,pll>,vector<pair<ll,pll> >,greater<pair<ll,pll> > >que;
	a[n].page=page;
	a[n].priority=k;
	a[n].start_time=start;
	a[n].num=tt;
	n++;
	sort(a,a+n,compare2);
//	for(ll i=0;i<n;i++)
//	{
//		cout<<i<<' '<<a[i].num<<' '<<a[i].page<<' '<<a[i].priority<<' '<<a[i].start_time<<endl;
//	}
//	cout<<endl;
	que.push(mp(a[0].priority,mp(0,a[0].page)));
	memset(finish,-1,sizeof(finish));
	for(ll i=1;i<n;i++)
	{
		ll time=a[i].start_time-a[i-1].start_time;
		ll now=a[i-1].start_time;
//		cout<<time<<' '<<now<<endl;
		while(!que.empty() && time)
		{
			pair<ll,pll> t=que.top();
//			cout<<t.first<<' '<<t.second.first<<' '<<t.second.second<<endl;
			que.pop();
			if(time>=t.second.second)
			{
//				cout<<a[0].num<<endl;
				finish[a[t.second.first].num]=now+t.second.second;
				time-=t.second.second;
				now+=t.second.second;
			}
			else
			{
				t.second.second-=time;
				time=0;
				que.push(t);
			}
		}
		que.push(mp(a[i].priority,mp(i,a[i].page)));
	}
	ll now=a[n-1].start_time;
	while(que.size())
	{
		pair<ll,pll> t=que.top();
		que.pop();
		finish[a[t.second.first].num]=now+t.second.second;
		now+=t.second.second;
	}
//	for(ll i=0;i<n;i++)
//	{
//		cout<<finish[i]<<' ';
//	}
//	cout<<endl; 
//	for(ll i=0;i<n;i++)
//	{
//		que
//	}
//	ll finish[n];
//	for(ll i=n-1;i>=0;i--)
//	{
//		finish[i]=a[i].start_time+a[i].page;
//		
//	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	ll offset=0;
	vector <ll> order; 
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&a[i+offset].start_time,&a[i+offset].page,&a[i+offset].priority);
		appear.insert(a[i+offset].priority);
		a[i+offset].num=i;
		if(offset==0 && a[i].priority==-1)
		{
			tt=i;
			offset=-1;
			start=a[i].start_time;
			page=a[i].page;
		}
	}
	cin>>end;
	n--;
	sort(a,a+n,compare);
//	order.push_back(1);
//	order.push_back(1000000000);
	if(a[0].priority!=1) order.push_back(a[0].priority-1);
	if(a[n-1].start_time!=1000000000) order.push_back(a[n-1].priority+1);
	for(ll i=0;i<n-1;i++)
	{
		if(a[i+1].priority!=a[i].priority+1)
		{
			order.push_back(a[i].priority+1);
		}
	}
//	cout<<endl;
	sort(order.begin(),order.end());
//	for(ll i=0;i<order.size();i++)
//	{
//		cout<<order[i]<<endl;
//	}
//	cout<<endl;
	ll l=0,r=order.size()-1,mid;
//	if(n==50000-1)
//	{
//		cout<<print(383498865,n,a)<<endl;//
//	}
	for(ll i=0;i<n;i++)
	{
		t[i]=a[i];
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
//		cout<<mid<<Endl;
		for(ll i=0;i<n;i++)
		{
			a[i]=t[i];
		}
		print(order[mid],n,a);
		if(finish[tt]==end)
		{
			cout<<order[mid]<<endl;
			for(int i=0;i<n+1;i++)
			{
				cout<<finish[i]<<' ';
			}
			cout<<endl;
			return 0;
		}
		else if(finish[tt]>end)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
//	print(order[mid],n,a);
//	cout<<endl;
//	cout<<endl;
//	cout<<Endl;
//	cout<<check(8)<<endl;
//	cout<<check(9)<<endl;
//	print(9);
//	if(!appear.count(1))
//	{
//		if(check(1))
//		{
//			print(1);
//			return 0;
//		}
//	}
//	if(!appear.count(1000000000))
//	{
//		if(check(1000000000))
//		{
//			print(1000000000);
//			return 0;
//		}
//	}
//	for(ll i=0;i<n-1;i++)
//	{
//		if(a[i].priority!=a[i+1].priority-1)
//		{
//			if(check(a[i].priority+1))
//			{
//				print(a[i].priority+1);
//				return 0;
//			}
//		}
//	}
	return 0;
}