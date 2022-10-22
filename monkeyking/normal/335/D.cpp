//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//int a[3005][3005];
//int h[3005][3005];
//int s[3005][3005];
//int maxDown[3005][3005],maxUp[3005][3005],maxLeft[3005][3005],maxRight[3005][3005];
//int data[3005][3005];
//tuple <int,int,int,int> rect[3005];
//
//inline int getnum()
//{
//    static int res;
//    static char c;
//    res=0;
//    c=0;
//    while(!isdigit(c)) c=getchar();
//    while(isdigit(c))
//    {
//        res=(res<<3)+(res<<1)+c-'0';
//        c=getchar();
//    }
//    return res;
//}
//
//inline void input(int T)
//{
//    int sx,ex,sy,ey;
//    sx=getnum();
//    sy=getnum();
//    ex=getnum();
//    ey=getnum();
//    rect[T]=make_tuple(sx,ex,sy,ey);
//    for(int i=sx;i<ex;i++)
//    {
//        for(int j=sy;j<ey;j++)
//        {
//            a[i][j]++;
//        }
//    }
//    for(int i=sx;i<ex;i++)
//    {
//        s[i][sy]=true;
//        s[i][ey]=true;
//    }
//    for(int i=sy;i<ey;i++)
//    {
//        h[sx][i]=true;
//        h[ex][i]=true;
//    }
//}
//
//inline void print(int x,int y,int k)
//{
//    puts("YES");
//    vector <int> res;
//    int sx,ex,sy,ey;
//    for(int T=0;T<n;T++)
//    {
//        tie(sx,ex,sy,ey)=rect[T];
//        if(sx>=x && ex<=x+k && sy>=y && ey<=y+k) res.push_back(T+1);
//    }
//    cout<<res.size()<<endl;
//    for(auto &id:res)
//    {
//        printf("%d ",id);
//    }
//    puts("");
//}
//
//int main()
//{
//    // freopen("input.txt","r",stdin);
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        input(i);
//    }
//    for(int i=0;i<=3000;i++)
//    {
//        for(int j=0;j<=3000;j++)
//        {
//            a[i][j]+=(i?a[i-1][j]:0)+(j?a[i][j-1]:0)-((i && j)?a[i-1][j-1]:0);
//        }
//    }
//    for(int i=0;i<=3000;i++)
//    {
//        for(int j=0;j<=3000;j++)
//        {
//            maxLeft[i][j]=(j?(maxLeft[i][j-1]+1)*h[i][j-1]:0);
//            maxUp[i][j]=(i?(maxUp[i-1][j]+1)*s[i-1][j]:0);
//        }
//    }
//    for(int i=3000;i>=0;i--)
//    {
//        for(int j=3000;j>=0;j--)
//        {
//            maxRight[i][j]=(maxRight[i][j+1]+1)*h[i][j];
//            maxDown[i][j]=(maxDown[i+1][j]+1)*s[i][j];
//        }
//    }
//    for(int i=0;i<=3000;i++)
//    {
//        for(int j=0;j<=3000;j++)
//        {
//            for(int k=1;k<=3000;k++)
//            {
//                if(k>maxDown[i][j]) break;
//                if(k>maxRight[i][j]) break;
//                if(a[i+k-1][j+k-1]-(i?a[i-1][j+k-1]:0)-(j?a[i+k-1][j-1]:0)+((i && j)?a[i-1][j-1]:0)!=k*k) break;
//                if(maxUp[i+k][j+k]<k) continue;
//                if(maxLeft[i+k][j+k]<k) continue;
//                print(i,j,k);
//                return 0;
//            }
//        }
//    }
//    puts("NO");
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
using namespace std;
int n;
int a[3005][3005];
int h[3005][3005];
int s[3005][3005];
int maxDown[3005][3005],maxUp[3005][3005],maxLeft[3005][3005],maxRight[3005][3005];
int data[3005][3005];
tuple <int,int,int,int> rect[3005];

inline int getnum()
{
    static int res;
    static char c;
    res=0;
    c=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        res=(res<<3)+(res<<1)+c-'0';
        c=getchar();
    }
    return res;
}

inline void input(int T)
{
    int sx,ex,sy,ey;
    sx=getnum();
    sy=getnum();
    ex=getnum();
    ey=getnum();
    rect[T]=make_tuple(sx,ex,sy,ey);
    for(int i=sx;i<ex;i++)
    {
        for(int j=sy;j<ey;j++)
        {
            a[i][j]++;
        }
    }
    for(int i=sx;i<ex;i++)
    {
        s[i][sy]=true;
        s[i][ey]=true;
    }
    for(int i=sy;i<ey;i++)
    {
        h[sx][i]=true;
        h[ex][i]=true;
    }
}

inline void print(int x,int y,int k)
{
    puts("YES");
    vector <int> res;
    int sx,ex,sy,ey;
    for(int T=0;T<n;T++)
    {
        tie(sx,ex,sy,ey)=rect[T];
        if(sx>=x && ex<=x+k && sy>=y && ey<=y+k) res.push_back(T+1);
    }
    cout<<res.size()<<endl;
    for(auto &id:res)
    {
        printf("%d ",id);
    }
    puts("");
}

int main()
{
    // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        input(i);
    }
    for(int i=0;i<=3000;i++)
    {
        for(int j=0;j<=3000;j++)
        {
            a[i][j]+=(i?a[i-1][j]:0)+(j?a[i][j-1]:0)-((i && j)?a[i-1][j-1]:0);
        }
    }
    for(int i=0;i<=3000;i++)
    {
        for(int j=0;j<=3000;j++)
        {
            maxLeft[i][j]=(j?(maxLeft[i][j-1]+1)*h[i][j-1]:0);
            maxUp[i][j]=(i?(maxUp[i-1][j]+1)*s[i-1][j]:0);
        }
    }
    for(int i=3000;i>=0;i--)
    {
        for(int j=3000;j>=0;j--)
        {
            maxRight[i][j]=(maxRight[i][j+1]+1)*h[i][j];
            maxDown[i][j]=(maxDown[i+1][j]+1)*s[i][j];
        }
    }
    for(int i=0;i<=3000;i++)
    {
        for(int j=0;j<=3000;j++)
        {
            for(int k=1;k<=3000;k++)
            {
                if(k>maxDown[i][j]) break;
                if(k>maxRight[i][j]) break;
                if(a[i+k-1][j+k-1]-(i?a[i-1][j+k-1]:0)-(j?a[i+k-1][j-1]:0)+((i && j)?a[i-1][j-1]:0)!=k*k) break;
                if(maxUp[i+k][j+k]<k) continue;
                if(maxLeft[i+k][j+k]<k) continue;
                print(i,j,k);
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}