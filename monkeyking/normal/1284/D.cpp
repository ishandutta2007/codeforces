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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int sa[100005],ea[100005],sb[100005],eb[100005];
int tsa[100005],tea[100005],tsb[100005],teb[100005];
int idas[100005];
int idae[100005];
int datahe[800005];
int datata[800005];
int nn;

void add(int data[],int x,int delta)
{
	while(x<=nn)
	{
		data[x]+=delta;
		x+=x & -x;
	}
}

int query(int data[],int x)
{
	int res=0;
	while(x)
	{
		res+=data[x];
		x&=(x-1);
	}
	return res;
}

bool compareas(const int &a,const int &b)
{
	return sa[a]<sa[b];
}

bool compareae(const int &a,const int &b)
{
	return ea[a]<ea[b];
}

void solve()
{
	vector <int> lsh;
	memset(datahe,0,sizeof(datahe));
	memset(datata,0,sizeof(datata));
	for(int i=0;i<n;i++)
	{
		lsh.push_back(sa[i]);
		lsh.push_back(sb[i]);
		lsh.push_back(eb[i]);
		lsh.push_back(ea[i]);
	}
	lsh.push_back(-1);
	lsh.push_back(-2);
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	for(int i=0;i<n;i++)
	{
		sa[i]=lower_bound(all(lsh),sa[i])-lsh.begin();
		ea[i]=lower_bound(all(lsh),ea[i])-lsh.begin();
		sb[i]=lower_bound(all(lsh),sb[i])-lsh.begin();
		eb[i]=lower_bound(all(lsh),eb[i])-lsh.begin();
	}
	for(int i=0;i<n;i++)
	{
		idas[i]=i;
		idae[i]=i;
	}
	sort(idas,idas+n,compareas);
	sort(idae,idae+n,compareae);
	set <int> he,ta;
	nn=1;
	while(nn<=(int)lsh.size())
	{
		nn<<=1;
	}
	for(int i=0,j=0;i<n;i++)
	{
		while(j<n && ea[idae[j]]<sa[idas[i]])
		{
			add(datahe,sb[idae[j]],1);
			add(datata,eb[idae[j]],1);
//			he.insert(sb[idae[j]]);
//			ta.insert(eb[idae[j]]);
			j++;
		}
		int l=sb[idas[i]],r=eb[idas[i]];
		int tot=query(datahe,nn)-query(datahe,r)+query(datata,l-1);
		assert(tot<=j);
		if(tot<j)
		{
			over("NO");
		}
	}
}

void func()
{
	for(int i=0;i<n;i++)
	{
		tsa[i]=sa[i];
		tea[i]=ea[i];
		tsb[i]=sb[i];
		teb[i]=eb[i];
	}
	solve();
	for(int i=0;i<n;i++)
	{
		sa[i]=2000000000-tsa[i];
		ea[i]=2000000000-tea[i];
		sb[i]=2000000000-tsb[i];
		eb[i]=2000000000-teb[i];
		swap(sa[i],ea[i]);
		swap(sb[i],eb[i]);
	}
	solve();
	for(int i=0;i<n;i++)
	{
		sa[i]=tsa[i];
		ea[i]=tea[i];
		sb[i]=tsb[i];
		eb[i]=teb[i];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
	}
	func();
	for(int i=0;i<n;i++)
	{
		swap(sa[i],sb[i]);
		swap(ea[i],eb[i]);
	}
	func();
	cout<<"YES\n";
	return 0;
}