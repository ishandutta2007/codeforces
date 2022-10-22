//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,P,k;
//pair<pii,int> p[100005];
//int kingChoose[100005];
//int citChoose[100005];
//vector <int> korder;
//vector <int> corder;
//vector <pair<pii,int> > vSort;
//int rk[100005];
//pii a[100005];
//
//int main()
//{
////	freopen("a.in","r",stdin);
////	freopen("a.out","w",stdout);
//	scanf("%d%d%d",&n,&P,&k);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d%d",&p[i].first.first,&p[i].first.second);
//		a[i]=p[i].first;
//		swap(p[i].first.first,p[i].first.second);
//		p[i].second=i;
//		p[i].first.first=-p[i].first.first;
//	}
//	sort(p,p+n);
//	for(int i=0;i<n;i++)
//	{
//		korder.push_back(p[i].second);
//		rk[korder[i]]=i;
//	}
//	for(int i=0;i<n;i++)
//	{
//		vSort.push_back(mp(mp(a[i].first,-rk[i]),i));
////		cout<<vSort.back()<<' ';
//	}
////	cout<<endl;
//	sort(all(vSort));
//	reverse(all(vSort));
//	for(int i=0;i<n;i++)
//	{
//		corder.push_back(vSort[i].second);
//	}
//	set <int> squ;
//	set <int> squ2;
////	for(int i=0;i<n;i++)
////	{
////		cout<<corder[i]+1<<' ';
////	}
////	cout<<endl;
////	for(int i=0;i<n;i++)
////	{
////		cout<<korder[i]+1<<' ';
////	}
////	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		squ.insert(i);
//		squ2.insert(i);
//	}
//	for(int i=0;i<P-k;i++)
//	{
//		squ.erase(korder[n-1-i]);
////		printf("%d ",korder[n-1-i]+1);
//	}
//	int s=0;
//	int rkmax=-1;
//	for(int i=0;i<n;i++)
//	{
//		if(squ.count(corder[i])) printf("%d ",corder[i]+1),s++,chmax(rkmax,rk[corder[i]]);
//		if(s==k) break;
//	}
//	vSort.clear();
//	for(int i=rkmax+1;i<n;i++)
//	{
//		vSort.push_back(mp(mp(a[korder[i]].second,-1),korder[i]));
//	}
//	sort(all(vSort));
//	reverse(all(vSort));
//	for(int i=0;i<P-k;i++)
//	{
//		printf("%d ",vSort[i].second+1);
//	}
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
int n,P,k;
pair<pii,int> p[100005];
int kingChoose[100005];
int citChoose[100005];
vector <int> korder;
vector <int> corder;
vector <pair<pii,int> > vSort;
int rk[100005];
pii a[100005];

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&P,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].first.first,&p[i].first.second);
		a[i]=p[i].first;
		swap(p[i].first.first,p[i].first.second);
		p[i].second=i;
		p[i].first.first=-p[i].first.first;
	}
	sort(p,p+n);
	for(int i=0;i<n;i++)
	{
		korder.push_back(p[i].second);
		rk[korder[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		vSort.push_back(mp(mp(a[i].first,-rk[i]),i));
//		cout<<vSort.back()<<' ';
	}
//	cout<<endl;
	sort(all(vSort));
	reverse(all(vSort));
	for(int i=0;i<n;i++)
	{
		corder.push_back(vSort[i].second);
	}
	set <int> squ;
	set <int> squ2;
//	for(int i=0;i<n;i++)
//	{
//		cout<<corder[i]+1<<' ';
//	}
//	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cout<<korder[i]+1<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		squ.insert(i);
		squ2.insert(i);
	}
	for(int i=0;i<P-k;i++)
	{
		squ.erase(korder[n-1-i]);
//		printf("%d ",korder[n-1-i]+1);
	}
	int s=0;
	int rkmax=-1;
	for(int i=0;i<n;i++)
	{
		if(squ.count(corder[i])) printf("%d ",corder[i]+1),s++,chmax(rkmax,rk[corder[i]]);
		if(s==k) break;
	}
	vSort.clear();
	for(int i=rkmax+1;i<n;i++)
	{
		vSort.push_back(mp(mp(a[korder[i]].second,-1),korder[i]));
	}
	sort(all(vSort));
	reverse(all(vSort));
	for(int i=0;i<P-k;i++)
	{
		printf("%d ",vSort[i].second+1);
	}
	return 0;
}