//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/st-table>
//using namespace std;
//int n;
//char c[500005];
//int sum[500005];
//int f[500005];
//int suf[500005];
//StTableFast <int,greater<int> > st;
//
//inline int calc(int ql,int qr,int rp,int limit)
//{
//    int l=ql,r=qr,mid,res=-1;
//    while(l<=r)
//    {
//        mid=l+r>>1;
//        if(st.query(mid,rp+1)<limit)
//        {
//            res=mid;
//            r=mid-1;
//        }
//        else
//        {
//            l=mid+1;
//        }
//    }
//    if(res==-1) return 0;
//    return qr-res+1;
//}
//
//int tmp[500005];
//int main()
//{
//    // freopen("input.txt","r",stdin);
//    cin>>n;
//    scanf("%s",c);
//    for(int i=0;i<n;i++)
//    {
//        c[i]-='0';
//    }
//    for(int i=n-1;i>=0;i--)
//    {
//        suf[i]=(suf[i+1]+1)*c[i];
//    }
//    st.init(suf,suf+n);
//    for(int i=0;i<n;i++)
//    {
//        sum[i]=(i?sum[i-1]:0)+c[i];
//        f[i]=n;
//    }
//    int pref=0;
//    ll res=0;
//    for(int i=0;i<n;i++)
//    {
//        if(c[i]==0)
//        {
//            pref=0;
//            continue;
//        }
//        pref++;
//        res+=1LL*pref*(n-i);
//        res+=1LL*calc(0,i-pref,i-pref,pref)*(n-i);
//    }
//    cout<<res<<endl;
//    return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
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
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_CONTROL_OF_MOD
int mod;
#else
const int mod=1e9+7;
#endif
const int gmod=2;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
using namespace std;
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<(int)vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T> 
void operator *= (vector <T> &vec,int k)
{
	for(auto &x:vec) x*=k;
}

template <typename T>
void operator -= (vector <T> &a,const vector <T> &b)
{
	assert(a.size()==b.size());
	for(size_t it=0;it<a.size();it++)
	{
		a[it]-=b[it];
	}
}

template <typename T>
vector <T> operator * (const vector <T> &vec,int k)
{
	vector <T> res(vec);
	res*=k;
	return res;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T,typename T2>
ostream & operator << (ostream & cout,set <T,T2> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
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

template <typename T1,typename T2,typename T3>
ostream & operator << (ostream &cout,map <T1,T2,T3> m)
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
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
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
	for(int i=0;i<(int)vec.size();i++)
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
#ifndef __SELF_ST_TABLE
#define __SELF_ST_TABLE 1

template <typename T,typename _Compare=std::less <T> >
struct StTableFast //
{
    std::vector <vector<T> > table;
    std::vector <T> logTable;
    _Compare comp;
    template <typename Iterator>
    void init(Iterator begin,Iterator end)
    {
        int n=end-begin;
        int lg=0;
        int nn=1;
        while(nn<=n)
        {
            nn<<=1;
            lg++;
        }
        lg--;
        table.resize(lg+1);
        for(int i=0;i<=lg;i++)
        {
            table[i].resize(n-(1<<i)+1);
        }
        logTable.resize(n+1);
        for(Iterator it=begin;it!=end;it++)
        {
            table[0][it-begin]=*it;
        }
        T ta,tb;
        for(int i=1;i<=lg;i++)
        {
            for(int j=0;j<n-(1<<i)+1;j++)
            {
                ta=table[i-1][j];
                tb=table[i-1][j+(1<<(i-1))];
                if(comp(ta,tb)) table[i][j]=ta;else table[i][j]=tb;
            }
        }
        logTable[1]=0;
        for(int i=2;i<=n;i++)
        {
            logTable[i]=logTable[i/2]+1;
        }
    }
    T query(int l,int r)
    {
        int n=r-l;
        int lg=logTable[n];
        T a=table[lg][l];
        T b=table[lg][r-(1<<lg)];
        if(comp(a,b)) return a;else return b;
    }
};

#endif
using namespace std;
int n;
char c[500005];
int sum[500005];
int f[500005];
int suf[500005];
StTableFast <int,greater<int> > st;

inline int calc(int ql,int qr,int rp,int limit)
{
    int l=ql,r=qr,mid,res=-1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(st.query(mid,rp+1)<limit)
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(res==-1) return 0;
    return qr-res+1;
}

int tmp[500005];
int main()
{
    // freopen("input.txt","r",stdin);
    cin>>n;
    scanf("%s",c);
    for(int i=0;i<n;i++)
    {
        c[i]-='0';
    }
    for(int i=n-1;i>=0;i--)
    {
        suf[i]=(suf[i+1]+1)*c[i];
    }
    st.init(suf,suf+n);
    for(int i=0;i<n;i++)
    {
        sum[i]=(i?sum[i-1]:0)+c[i];
        f[i]=n;
    }
    int pref=0;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(c[i]==0)
        {
            pref=0;
            continue;
        }
        pref++;
        res+=1LL*pref*(n-i);
        res+=1LL*calc(0,i-pref,i-pref,pref)*(n-i);
    }
    cout<<res<<endl;
    return 0;
}