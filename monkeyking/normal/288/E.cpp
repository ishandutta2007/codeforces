//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/modint>
//using namespace std;
//char c1[100005],c2[100005];
//int n;
//#define Int ModInt <mod>
//Int a[100005];
//Int pow10[100005];
//Int pow2[100005];
//Int sum[100005];
//Int sumMut[100005];
//Int l4[100005];
//Int l7[100005];
//
//inline Int merge(Int num,int i)
//{
//    i++;
//    Int t=pow10[i-1]*num;
//    Int res=(t*t*(pow2[i-1]-1)+t*(sum[i-1]*2-l4[i-1]-l7[i-1]))+sumMut[i-1];
//    return res;
//}
//
//inline Int solve(char c[])
//{
//    n=strlen(c);
//    for(int i=0;i<n;i++)
//    {
//        a[i]=c[i]-'0';
//    }
//    reverse(a,a+n);
//    Int res=0;
//    res=sumMut[n-1];
//    Int lastLuckyNumber=l7[n-1];
//    Int prefix=0;
//    for(int i=n-1;i>=0;i--)
//    {
//        if(a[i].x<4) return res;
//        if(a[i].x==4)
//        {
//            prefix=prefix*10+4;
//            continue;
//        }
//        if(a[i].x<7)
//        {
//            // cout<<prefix*10+4<<' '<<i<<endl;
//            res+=merge(prefix*10+4,i);
//            // cout<<merge(prefix*10+4,i)<<endl;
//            res+=lastLuckyNumber*(prefix*pow10[i+1]+l4[i+1]);
//            lastLuckyNumber=(prefix*pow10[i+1]+l4[i+1]);
//            return res;
//        }
//        if(a[i].x==7)
//        {
//            res+=merge(prefix*10+4,i);
//            res+=lastLuckyNumber*(prefix*pow10[i+1]+l4[i+1]);
//            lastLuckyNumber=(prefix*pow10[i+1]+pow10[i]*4+l7[i]);
//            prefix=prefix*10+7;
//            // cout<<"i="<<i<<' '<<lastLuckyNumber<<' '<<prefix<<endl;
//            continue;
//        }
//        assert(a[i].x>7);
//        res+=merge(prefix,i+1);
//        res+=lastLuckyNumber*(prefix*pow10[i+1]+l4[i+1]);
//        lastLuckyNumber=prefix*pow10[i+1]+l7[i+1];
//        return res;
//    }
//    // cout<<res<<' '<<lastLuckyNumber<<endl;
//    res+=lastLuckyNumber*prefix;
//    lastLuckyNumber=prefix;
//    return res;
//}
//
//void init()
//{
//    pow10[0]=1;
//    l4[0]=0;
//    l7[0]=0;
//    for(int i=1;i<=1e5;i++)
//    {
//        pow10[i]=pow10[i-1]*10;
//        l4[i]=l4[i-1]*10+4;
//        l7[i]=l7[i-1]*10+7;
//    }
//    pow2[0]=1;
//    for(int i=1;i<=1e5;i++)
//    {
//        pow2[i]=pow2[i-1]*2;
//    }
//    sum[0]=0;
//    for(int i=1;i<=1e5;i++)
//    {
//        sum[i]=sum[i-1]*2+pow10[i-1]*11*pow2[i-1];
//    }
//    sumMut[0]=0;
//    for(int i=1;i<=1e5;i++)
//    {
//        sumMut[i]=sumMut[i-1]*2;
//        Int t=pow10[i-1]*4;
//        sumMut[i]+=(t*t*(pow2[i-1]-1)+t*(sum[i-1]*2-l4[i-1]-l7[i-1]));
//        t=pow10[i-1]*7;
//        sumMut[i]+=(t*t*(pow2[i-1]-1)+t*(sum[i-1]*2-l4[i-1]-l7[i-1]));
//        sumMut[i]+=(pow10[i-1]*4+l7[i-1])*(pow10[i-1]*7+l4[i-1]);
//    }
//    // cout<<sumMut[3]<<endl;
//}
//
//int findlast(char a[],char b[])//???<a?
//{
//    vector <char> prefix;
//    int n=strlen(a);
//    int res=n-1;
//    for(int i=0;i<res;i++)
//    {
//        b[i]='7';
//    }
//    int last7pos=-1;
//    for(int i=0;i<n;i++)
//    {
//        if(a[i]<'4') return res;
//        if(a[i]=='4')
//        {
//            prefix.push_back('4');
//            continue;
//        }
//        if(a[i]<'7')
//        {
//            res=n;
//            for(int j=0;j<prefix.size();j++)
//            {
//                b[j]=prefix[j];
//            }
//            for(int j=prefix.size();j<res;j++)
//            {
//                b[j]='7';
//            }
//            return res;
//        }
//        if(a[i]=='7')
//        {
//            if(last7pos==-1)
//            {
//                res=n;
//                for(int j=0;j<prefix.size();j++)
//                {
//                    b[j]=prefix[j];
//                }
//                b[prefix.size()]='4';
//                for(int j=(int)prefix.size()+1;j<res;j++)
//                {
//                    b[j]='7';
//                }
//            }
//            else
//            {
//                for(int j=last7pos;j<prefix.size();j++)
//                {
//                    b[j]=prefix[j];
//                }
//                b[prefix.size()]='4';
//            }
//            last7pos=prefix.size();
//            prefix.push_back('7');
//            continue;
//        }
//        assert(a[i]>'7');
//        res=n;
//        for(int j=0;j<prefix.size();j++)
//        {
//            b[j]=prefix[j];
//        }
//        for(int j=prefix.size();j<res;j++)
//        {
//            b[j]='7';
//        }
//        return res;
//    }
//    return res;
//}
//
//char tmp[100005];
//
//void toNext(char c[])
//{
//    int n=findlast(c,tmp);
//    bool all7=true;
//    c[n]=0;
//    for(int i=0;i<n;i++)
//    {
//        c[i]=tmp[i];
//    }
//    // for(int i=0;i<n;i++)
//    // {
//    //     cout<<c[i];
//    // }
//    // cout<<endl;
//    // cout<<n<<endl;
//    // printf("%s\n",c);
//    for(int i=0;i<n;i++)
//    {
//        all7&=(c[i]=='7');
//    }
//    if(all7)
//    {
//        n++;
//        c[0]='4';
//        for(int i=1;i<n;i++)
//        {
//            c[i]='4';
//        }
//        c[n]=0;
//        return;
//    }
//    int tpos=-1;
//    for(int i=n-1;i>=0;i--)
//    {
//        if(c[i]=='4') 
//        {
//            tpos=i;
//            break;
//        }
//    }
//    assert(tpos!=-1);
//    // cout<<tpos<<endl;
//    c[tpos]='7';
//    for(int i=tpos+1;i<n;i++)
//    {
//        c[i]='4';
//    }
//    c1[n]=0;
//    return;
//}
//
//inline bool bigger(char l[],char r[])
//{
//    int n=strlen(l);
//    if(n>strlen(r)) return true;
//    if(n<strlen(r)) return false;
//    for(int i=0;i<n;i++)
//    {
//        if(l[i]!=r[i]) return l[i]>r[i];
//    }
//    return false;
//}
//
//int main()
//{
//    // freopen("input.txt","r",stdin);
//    init();
//    scanf("%s%s",c1,c2);
//    // cout<<solve(c2)<<endl;
//    // scanf("%s",c1);
//    // cout<<solve(c1)<<endl;
//    toNext(c1);
//    // printf("%s\n",c1);
//    if(bigger(c1,c2))
//    {
//        cout<<0<<endl;
//        return 0;
//    }
//    // cout<<solve(c2)<<endl;
//    cout<<solve(c2)-solve(c1)<<endl;
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
template <int mod>
struct ModInt
{
	int x;
	ModInt(){x=0;}
	ModInt(int _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt(ll _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt <mod>& operator ++()// prefix
	{
		++x;
		if(x==mod) x=0;
		return *this;
	}
};

template <int mod>
bool operator == (ModInt <mod> a,ModInt <mod> b)
{
	return a.x==b.x;
}

template <int mod>
bool operator == (ModInt <mod> a,int x)
{
	return (a.x==x);
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,int b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
	return a;
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x+b.x;
	if(tmp>=mod) tmp-=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x-b.x;
	if(tmp<0) tmp+=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,int b)
{
	return a-(ModInt <mod> )b;
}

template <int mod>
void operator -= (ModInt <mod> &a,ModInt <mod> b)
{
	a.x-=b.x;
	a.x+=(a.x>>31&mod);
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,ModInt <mod> b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,int b)
{
	return 1LL*a.x*b%mod;
}

template <int mod>
void operator *= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a*b;
}

template <int mod>
void operator += (ModInt <mod> &a,ModInt <mod> b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod>
inline ModInt <mod> inv(ModInt <mod> x)
{
	int m=mod-2;
	ModInt <mod> basic=x;
	x=1;
	while(m)
	{
		if(m&1) x*=basic;
		m>>=1;
		basic*=basic;
	}
	return x;
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,ModInt <mod> b)
{
	return a*inv(b);
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,int b)
{
	return a*inv((ModInt <mod>)b);
}

template <int mod>
void operator /= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a/b;
}

template <int mod>
istream & operator >> (istream &cin,ModInt <mod> &x)
{
	cin>>x.x;
	return cin;
}

template <int mod>
ostream & operator << (ostream &cout,ModInt <mod> x)
{
	cout<<x.x;
	return cout;
}
using namespace std;
char c1[100005],c2[100005];
int n;
#define Int ModInt <mod>
Int a[100005];
Int pow10[100005];
Int pow2[100005];
Int sum[100005];
Int sumMut[100005];
Int l4[100005];
Int l7[100005];

inline Int merge(Int num,int i)
{
    i++;
    Int t=pow10[i-1]*num;
    Int res=(t*t*(pow2[i-1]-1)+t*(sum[i-1]*2-l4[i-1]-l7[i-1]))+sumMut[i-1];
    return res;
}

inline Int solve(char c[])
{
    n=strlen(c);
    for(int i=0;i<n;i++)
    {
        a[i]=c[i]-'0';
    }
    reverse(a,a+n);
    Int res=0;
    res=sumMut[n-1];
    Int lastLuckyNumber=l7[n-1];
    Int prefix=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i].x<4) return res;
        if(a[i].x==4)
        {
            prefix=prefix*10+4;
            continue;
        }
        if(a[i].x<7)
        {
            // cout<<prefix*10+4<<' '<<i<<endl;
            res+=merge(prefix*10+4,i);
            // cout<<merge(prefix*10+4,i)<<endl;
            res+=lastLuckyNumber*(prefix*pow10[i+1]+l4[i+1]);
            lastLuckyNumber=(prefix*pow10[i+1]+l4[i+1]);
            return res;
        }
        if(a[i].x==7)
        {
            res+=merge(prefix*10+4,i);
            res+=lastLuckyNumber*(prefix*pow10[i+1]+l4[i+1]);
            lastLuckyNumber=(prefix*pow10[i+1]+pow10[i]*4+l7[i]);
            prefix=prefix*10+7;
            // cout<<"i="<<i<<' '<<lastLuckyNumber<<' '<<prefix<<endl;
            continue;
        }
        assert(a[i].x>7);
        res+=merge(prefix,i+1);
        res+=lastLuckyNumber*(prefix*pow10[i+1]+l4[i+1]);
        lastLuckyNumber=prefix*pow10[i+1]+l7[i+1];
        return res;
    }
    // cout<<res<<' '<<lastLuckyNumber<<endl;
    res+=lastLuckyNumber*prefix;
    lastLuckyNumber=prefix;
    return res;
}

void init()
{
    pow10[0]=1;
    l4[0]=0;
    l7[0]=0;
    for(int i=1;i<=1e5;i++)
    {
        pow10[i]=pow10[i-1]*10;
        l4[i]=l4[i-1]*10+4;
        l7[i]=l7[i-1]*10+7;
    }
    pow2[0]=1;
    for(int i=1;i<=1e5;i++)
    {
        pow2[i]=pow2[i-1]*2;
    }
    sum[0]=0;
    for(int i=1;i<=1e5;i++)
    {
        sum[i]=sum[i-1]*2+pow10[i-1]*11*pow2[i-1];
    }
    sumMut[0]=0;
    for(int i=1;i<=1e5;i++)
    {
        sumMut[i]=sumMut[i-1]*2;
        Int t=pow10[i-1]*4;
        sumMut[i]+=(t*t*(pow2[i-1]-1)+t*(sum[i-1]*2-l4[i-1]-l7[i-1]));
        t=pow10[i-1]*7;
        sumMut[i]+=(t*t*(pow2[i-1]-1)+t*(sum[i-1]*2-l4[i-1]-l7[i-1]));
        sumMut[i]+=(pow10[i-1]*4+l7[i-1])*(pow10[i-1]*7+l4[i-1]);
    }
    // cout<<sumMut[3]<<endl;
}

int findlast(char a[],char b[])//???<a?
{
    vector <char> prefix;
    int n=strlen(a);
    int res=n-1;
    for(int i=0;i<res;i++)
    {
        b[i]='7';
    }
    int last7pos=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]<'4') return res;
        if(a[i]=='4')
        {
            prefix.push_back('4');
            continue;
        }
        if(a[i]<'7')
        {
            res=n;
            for(int j=0;j<prefix.size();j++)
            {
                b[j]=prefix[j];
            }
            for(int j=prefix.size();j<res;j++)
            {
                b[j]='7';
            }
            return res;
        }
        if(a[i]=='7')
        {
            if(last7pos==-1)
            {
                res=n;
                for(int j=0;j<prefix.size();j++)
                {
                    b[j]=prefix[j];
                }
                b[prefix.size()]='4';
                for(int j=(int)prefix.size()+1;j<res;j++)
                {
                    b[j]='7';
                }
            }
            else
            {
                for(int j=last7pos;j<prefix.size();j++)
                {
                    b[j]=prefix[j];
                }
                b[prefix.size()]='4';
            }
            last7pos=prefix.size();
            prefix.push_back('7');
            continue;
        }
        assert(a[i]>'7');
        res=n;
        for(int j=0;j<prefix.size();j++)
        {
            b[j]=prefix[j];
        }
        for(int j=prefix.size();j<res;j++)
        {
            b[j]='7';
        }
        return res;
    }
    return res;
}

char tmp[100005];

void toNext(char c[])
{
    int n=findlast(c,tmp);
    bool all7=true;
    c[n]=0;
    for(int i=0;i<n;i++)
    {
        c[i]=tmp[i];
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<c[i];
    // }
    // cout<<endl;
    // cout<<n<<endl;
    // printf("%s\n",c);
    for(int i=0;i<n;i++)
    {
        all7&=(c[i]=='7');
    }
    if(all7)
    {
        n++;
        c[0]='4';
        for(int i=1;i<n;i++)
        {
            c[i]='4';
        }
        c[n]=0;
        return;
    }
    int tpos=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(c[i]=='4') 
        {
            tpos=i;
            break;
        }
    }
    assert(tpos!=-1);
    // cout<<tpos<<endl;
    c[tpos]='7';
    for(int i=tpos+1;i<n;i++)
    {
        c[i]='4';
    }
    c1[n]=0;
    return;
}

inline bool bigger(char l[],char r[])
{
    int n=strlen(l);
    if(n>strlen(r)) return true;
    if(n<strlen(r)) return false;
    for(int i=0;i<n;i++)
    {
        if(l[i]!=r[i]) return l[i]>r[i];
    }
    return false;
}

int main()
{
    // freopen("input.txt","r",stdin);
    init();
    scanf("%s%s",c1,c2);
    // cout<<solve(c2)<<endl;
    // scanf("%s",c1);
    // cout<<solve(c1)<<endl;
    toNext(c1);
    // printf("%s\n",c1);
    if(bigger(c1,c2))
    {
        cout<<0<<endl;
        return 0;
    }
    // cout<<solve(c2)<<endl;
    cout<<solve(c2)-solve(c1)<<endl;
    return 0;
}