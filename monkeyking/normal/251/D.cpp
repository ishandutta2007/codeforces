//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//ll a[100005];
//int bel[100005];
//
//#ifndef _SELF_VS
//#define _SELF_VS 1
//#include <self/utility>
//using namespace std;
//
//struct XorSpace
//{
//	vector <ll > bases;
//	vector <int> baseIDs;
//	map <int,int> toXSID;
//	vector <vector<int> > trace;
//	int freeNum=0;
//	int recordTrace=-1;
//	void clear()
//	{
//		recordTrace=-1;
//		freeNum=0;
//		trace.clear();
//		toXSID.clear();
//		baseIDs.clear();
//		bases.clear();
//	}
//	void error(string str)
//	{
//		cout<<str<<endl;
//		exit(0);
//	}
//	void add(ll x)
//	{
//		if(recordTrace==1) error("You've ordered 'Record Trace' function, which is incompatible with single parameter function 'add'");
//		recordTrace=0;
//		for(auto &basis:bases)
//		{
//			chmin(x,x^basis);
//		}
//		if(x==0)
//		{
//			freeNum++;
//			return;
//		}
//		else bases.push_back(x);
//	}
//	vector <int> expandTrace(vector <int> v)
//	{
//		vector <int> t;
//		for(auto x:v)
//		{
//			for(auto u:trace[x])
//			{
//				t.push_back(u);
//			}
//		}
//		vector <int> res;
//		sort(all(t));
//		for(int i=0,j=0;i<t.size();i=j)
//		{
//			for(j=i;j<t.size();j++)
//			{
//				if(t[i]!=t[j]) break;
//			}
//			if((j-i)&1) res.push_back(t[i]);
//		}
//		return res;
//	}
//	void add(ll x,int id)
//	{
//		vector <int> tmp;
//		if(recordTrace==0) error("You've ordered 'Record Trace' function, which is incompatible with single parameter function 'add'");
//		recordTrace=true;
//		for(int i=0;i<bases.size();i++)
//		{
//			ll bit=bases[i]^x;
//			if(bit<x)
//			{
//				x=bit;
//				tmp.push_back(i);
//			}
//		}
//		if(x==0)
//		{
//			freeNum++;
//			return;
//		}
//		else
//		{
//			bases.push_back(x);
//			toXSID[id]=baseIDs.size();
//			baseIDs.push_back(id);
//			vector <int> t;
//			trace.push_back(expandTrace(tmp));
//			trace.back().push_back((int)baseIDs.size()-1);
//		}
//	}
//	bool query(ll x)
//	{
//		for(auto &basis:bases)
//		{
//			chmin(x,x^basis);
//		}
//		return (x==0);
//	}
//	pair<int,vector <int> > queryWithID(ll x)
//	{
//		if(recordTrace==0)
//		{
//			error("You've ordered 'Query With ID' function, which needs 'Record Trace' function opening");
//		}
//		ll tmp;
//		vector <int> res;
//		for(int i=0;i<bases.size();i++)
//		{
//			tmp=bases[i]^x;
//			if(tmp<x)
//			{
//				x=tmp;
//				res.push_back(i);
//			}
//		}
//		res=expandTrace(res);
//		for(auto &x:res)
//		{
//			x=baseIDs[x];
//		}
//		return mp((x==0),res);
//	}
//};
//#endif
//
//void build(XorSpace &xs,ll key,bool withID=false)
//{
//	xs.clear();
//	for(int i=0;i<n;i++)
//	{
//		if(!withID) xs.add(key&a[i]);else xs.add(key&a[i],i);
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	quickcin;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cin>>a[i];
//	}
//	XorSpace xs;
//	ll tot=0;
//	for(int i=0;i<n;i++)
//	{
//		tot^=a[i];
//	}
//	ll resd=tot;
//	ll key=0;
//	ll now=0;
//	for(int i=61;i>=0;i--)
//	{
//		if((tot & (1LL<<i))) continue;
//		resd+=2LL<<i;
//		key|=(1LL<<i);
//		now|=(1LL<<i);
//		build(xs,key);
//		if(xs.query(now&(ll)key))
//		{
////			cout<<i<<endl;
//			continue;
//		}
//		key^=(1LL<<i);
//		resd-=2LL<<i;
//	}
//	for(int i=62;i>=0;i--)
//	{
//		if(!(tot & (1LL<<i))) continue;
//		key|=(1LL<<i);
////		now[i]=0;
//		build(xs,key);
//		if(xs.query(now&(ll )key)) continue;
//		key^=(1LL<<i);
//	}
//	for(int i=0;i<n;i++)
//	{
//		bel[i]=2;
//	}
//	build(xs,key,true);
//	pair<int,vector <int> > o=xs.queryWithID(now&(ll)key);
//	for(auto id:o.second)
//	{
//		bel[id]=1;
//	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<bel[i]<<' ';
//	}
////	if(n==50) cout<<resd<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
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
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
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
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,set <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
		}
	}
	return v;
}
#endif

void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
using namespace std;
int n;
ll a[100005];
int bel[100005];

#ifndef _SELF_VS
#define _SELF_VS 1
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
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
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

using namespace std;

struct XorSpace
{
	vector <ll > bases;
	vector <int> baseIDs;
	map <int,int> toXSID;
	vector <vector<int> > trace;
	int freeNum=0;
	int recordTrace=-1;
	void clear()
	{
		recordTrace=-1;
		freeNum=0;
		trace.clear();
		toXSID.clear();
		baseIDs.clear();
		bases.clear();
	}
	void error(string str)
	{
		cout<<str<<endl;
		exit(0);
	}
	void add(ll x)
	{
		if(recordTrace==1) error("You've ordered 'Record Trace' function, which is incompatible with single parameter function 'add'");
		recordTrace=0;
		for(auto &basis:bases)
		{
			chmin(x,x^basis);
		}
		if(x==0)
		{
			freeNum++;
			return;
		}
		else bases.push_back(x);
	}
	vector <int> expandTrace(vector <int> v)
	{
		vector <int> t;
		for(auto x:v)
		{
			for(auto u:trace[x])
			{
				t.push_back(u);
			}
		}
		vector <int> res;
		sort(all(t));
		for(int i=0,j=0;i<t.size();i=j)
		{
			for(j=i;j<t.size();j++)
			{
				if(t[i]!=t[j]) break;
			}
			if((j-i)&1) res.push_back(t[i]);
		}
		return res;
	}
	void add(ll x,int id)
	{
		vector <int> tmp;
		if(recordTrace==0) error("You've ordered 'Record Trace' function, which is incompatible with single parameter function 'add'");
		recordTrace=true;
		for(int i=0;i<bases.size();i++)
		{
			ll bit=bases[i]^x;
			if(bit<x)
			{
				x=bit;
				tmp.push_back(i);
			}
		}
		if(x==0)
		{
			freeNum++;
			return;
		}
		else
		{
			bases.push_back(x);
			toXSID[id]=baseIDs.size();
			baseIDs.push_back(id);
			vector <int> t;
			trace.push_back(expandTrace(tmp));
			trace.back().push_back((int)baseIDs.size()-1);
		}
	}
	bool query(ll x)
	{
		for(auto &basis:bases)
		{
			chmin(x,x^basis);
		}
		return (x==0);
	}
	pair<int,vector <int> > queryWithID(ll x)
	{
		if(recordTrace==0)
		{
			error("You've ordered 'Query With ID' function, which needs 'Record Trace' function opening");
		}
		ll tmp;
		vector <int> res;
		for(int i=0;i<bases.size();i++)
		{
			tmp=bases[i]^x;
			if(tmp<x)
			{
				x=tmp;
				res.push_back(i);
			}
		}
		res=expandTrace(res);
		for(auto &x:res)
		{
			x=baseIDs[x];
		}
		return mp((x==0),res);
	}
};
#endif

void build(XorSpace &xs,ll key,bool withID=false)
{
	xs.clear();
	for(int i=0;i<n;i++)
	{
		if(!withID) xs.add(key&a[i]);else xs.add(key&a[i],i);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	quickcin;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	XorSpace xs;
	ll tot=0;
	for(int i=0;i<n;i++)
	{
		tot^=a[i];
	}
	ll resd=tot;
	ll key=0;
	ll now=0;
	for(int i=61;i>=0;i--)
	{
		if((tot & (1LL<<i))) continue;
		resd+=2LL<<i;
		key|=(1LL<<i);
		now|=(1LL<<i);
		build(xs,key);
		if(xs.query(now&(ll)key))
		{
//			cout<<i<<endl;
			continue;
		}
		key^=(1LL<<i);
		resd-=2LL<<i;
	}
	for(int i=62;i>=0;i--)
	{
		if(!(tot & (1LL<<i))) continue;
		key|=(1LL<<i);
//		now[i]=0;
		build(xs,key);
		if(xs.query(now&(ll )key)) continue;
		key^=(1LL<<i);
	}
	for(int i=0;i<n;i++)
	{
		bel[i]=2;
	}
	build(xs,key,true);
	pair<int,vector <int> > o=xs.queryWithID(now&(ll)key);
	for(auto id:o.second)
	{
		bel[id]=1;
	}
	for(int i=0;i<n;i++)
	{
		cout<<bel[i]<<' ';
	}
//	if(n==50) cout<<resd<<endl;
	return 0;
}