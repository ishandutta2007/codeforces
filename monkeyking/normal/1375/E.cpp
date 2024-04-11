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
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
int n;
int a[1005];
bool used[1005];
pii p[105];
int k;

void print()
{
	for(int i=0;i<k;i++)
	{
		cout<<p[i].first<<' '<<p[i].second<<endl;
	}
	cout<<endl;
}

bool brute()
{
	int b[105];
	k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				p[k++]=mp(i,j);
			}
		}
	}
	sort(p,p+k);
	memcpy(b,a,sizeof(int)*n);
	bool haveans=false;
	do
	{
		memcpy(a,b,sizeof(int)*n);
		for(int i=0;i<k;i++)
		{
			swap(a[p[i].first],a[p[i].second]);
		}
		bool good=true;
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1]) good=false;
		}
		if(!good) continue;
		haveans=true;
//		break;
		print();
	}while(next_permutation(p,p+k));
	return haveans;
}

void solve()
{
	cin>>n;
	vector <pair<int,int> > vec;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vec.push_back(mp(a[i],i));
	}
	int s=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j]) s++;
		}
	}
	cout<<s<<endl;
	sort(all(vec));
	reverse(all(vec));
	for(int i=0;i<n;i++)
	{
		int pos=vec[i].second;
//		cout<<i<<":"<<pos<<endl;
		for(int j=0;j<pos;j++)
		{
			if(!used[j]) continue;
			swap(a[pos],a[j]);
			printf("%d %d\n",j+1,pos+1);
		}
		used[pos]=true;
	}
}

//#include <self/rand>
int main()
{
//	freopen("input.txt","r",stdin);
//	cin>>n;
//	for(int k=0;k<=100;k++)
//	{
//		for(int i=0;i<n;i++)
//		{
//			a[i]=rand(0,n);
//		}
//		if(!brute())
//		{
//			for(int i=0;i<n;i++)
//			{
//				cout<<a[i]<<' ';
//			}
//			cout<<endl;
//			break;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		cin>>a[i];
//	}
//	brute();
	solve();
	return 0;
}