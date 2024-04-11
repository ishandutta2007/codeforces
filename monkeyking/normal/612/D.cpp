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
#define all(A) A.begin(),A.end()
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,k;
set <pair<int,pii> >squ;
int vec[2000005];
int a[2000005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	int l,r;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&l,&r);
		squ.insert(mp(l,mp(0,i*2)));
		squ.insert(mp(r,mp(1,i*2)));
	}
	int cover=0;
	l=r=-1;
	vector <pii> res;
	for(set <pair<int,pii> > :: iterator it=squ.begin();it!=squ.end();it++)
	{
//		cout<<cover<<endl;
//		cout<<l<<' '<<r<<endl; 
		int x=it->first;
//		cout<<x<<endl;
		int type=it->second.first;
//		cout<<x<<' '<<type<<endl;
		if(type%2==0)
		{
			cover++;
			if(cover==k)
			{
				if(l==-1)
				{
					l=x;
				}
				else
				{
					r=x;
				}
			}
		}
		else
		{
			if(cover==k)
			{
//				cout<<"F";
				res.push_back(mp(l,x));
				l=r=-1;
			}
			cover--;
		}
	}
	set <pii> squ;
	for(int i=0;i<res.size();i++)
	{
//		squ.insert(mp(res[i].first,0));
		squ.insert(mp(res[i].first,i*2+0));
//		squ.insert(mp(res[i].second,1));
		squ.insert(mp(res[i].second,i*2+1));
	}
	int len=0;
	for(set <pii> :: iterator it=squ.begin();it!=squ.end();it++)
	{
		int x=it->first;
		int type=it->second;
		if(len && vec[len-1]==x && ((type & 1)==0))
		{
//			cout<<type<<endl;
			len--;
		}
		else
		{
			vec[len++]=x;
		}
	}
//	cout<<len/2<<endl;
//	for(int i=0;i<len/2;i++)
//	{
//		if(vec[i*2]==vec[i*2+1]) continue;
//		printf("%d %d\n",vec[i*2],vec[i*2+1]);//vec[i*2]<<' '<<vec[i*2+1]<<endl;	
//	}
//	vec[len++]=5;
//	vec[len++]=5;
	vector <pii> v;
	for(int i=0;i<len/2;i++)
	{
//		if(vec[i*2]!=vec[i*2+1])
//		{
			v.push_back(mp(vec[i*2],vec[i*2+1]));
//		}
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
	{
		printf("%d %d\n",v[i].first,v[i].second);
	}
//	vector <pii> vec;
//	l=res[0].first;
//	r=res[0].second;
//	vec.push_back(mp(-1,-1));
//	for(int i=0;i<res.size();i++)
//	{
//		if(res[i].second==res[i].first)
//		{
//			r=res[i+1].second;
//		}
//		else
//		{
//			vec.push_back(mp(l,r));
//			l=res[i+1].first;
//		}
//	}
//	cout<<vec.size()<<endl;
//	for(int i=0;i<vec.size();i++)
//	{
//		cout<<vec[i].first<<' '<<vec[i].second<<endl;
//	}
	return 0;
}