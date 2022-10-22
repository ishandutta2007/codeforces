//Original Code:
//#pragma GCC optimize(2)
//#include <self/utility>
//#include <self/debug>
//#include <self/ModInt>
//#include <self/string>
//using namespace std;
//using Int=ModInt <mod>;
//int n,q;
//string s0,t;
//char buf[2000005];
//string s[22];
//int kk;
//Int bin[200005][26];
//int k;
//string final;
//const int prime=23333;
//Int hzheng[2000005];
//Int hfan[2000005];
//Int pow2[2000005];
//Int czheng[2000005];
//Int cfan[2000005];
//Int cnt[26];
//Int ppow[2000005];
//StringHash h[26];
//StringHash ch;
//
//inline Int gethash(Int h[],int l,int r)
//{
//	return h[r-1]-(l?h[l-1]*ppow[r-l]:0);
//}
//
//inline void solve()
//{
//	scanf("%d%s",&k,buf);
//	int n=strlen(buf);
//	int kk=0;
//	for(;kk<=k;kk++)
//	{
//		if((int)s[kk].size()>=n) break;
//	}
//	if(kk==k+1)
//	{
//		puts("0");
//		return;
//	}
//	ch.feedString(buf);
//	int m=s[kk].size();
//
//	Int ba=0;
//	for(int i=0;i<=m-n;i++)
//	{
//		if(h[kk].getHash(i,n)==ch.getHash(0,n)) ba++;
//	}
//	memset(cnt,0,sizeof(cnt));
//	for(int i=0;i<n;i++)
//	{
//		cnt[buf[i]-'a']+=(h[kk].getHash(m-i,i)==ch.getHash(0,i) && h[kk].getHash(0,n-i-1)==ch.getHash(i+1,n-i-1));
//	}
//	// cout<<s[kk]<<' '<<buf<<' '<<ba<<endl;
//	Int res=ba*pow2[k-kk];
//	for(int i=0;i<26;i++)
//	{
//		res+=(bin[k][i]-bin[kk][i]*pow2[k-kk])*cnt[i];
//	}
//	printf("%d\n",res.x);
//}
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	cin>>n>>q;
//	ch.init(1e6,prime,mod);
//	pow2[0]=1;
//	ppow[0]=1;
//	for(int i=1;i<=1e6;i++) pow2[i]=pow2[i-1]*2,ppow[i]=ppow[i-1]*prime;
//	cin>>s0;
//	scanf("%s",buf);
//	t=buf;
//	s[0]=s0;
//	for(kk=1;kk<=n;kk++)
//	{
//		s[kk]=s[kk-1]+t[kk-1]+s[kk-1];
//		if(s[kk].size()>1000000) break;
//	}
//	for(int i=0;i<=kk;i++)
//	{
//		h[i].init(s[i].size(),prime,mod);
//		h[i].feedString(s[i].c_str());
//	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<26;j++) 
//		{
//			bin[i][j]=(i?bin[i-1][j]:0)*2+(t[i-1]-'a'==j);
//		}
//	}
//	while(q--)
//	{
//		solve();
//	}
//	return 0;
//}

//substituted with C++ Inliner
#pragma GCC optimize(2)
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
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=3;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=2LL*inf*inf;
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
ostream &operator<<(ostream &cout, vector<T> vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
#include <sstream>
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
	for(int i=(int)vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(size_t i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
#ifndef SELF_MODINT
#define SELF_MODINT 1
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
	ModInt <mod> operator ++(int)
	{
		int t=x;
		x++;
		if(x==mod) x=0;
		return t;
	}
	ModInt <mod>& operator --()// prefix
	{
		--x;
		if(x==-1) x+=mod;
		return *this;
	}
	ModInt <mod> operator --(int)
	{
		int t=x;
		x--;
		if(x==-1) x+=mod;
		return t;
	}
	ModInt <mod> operator -()const
	{
		return ModInt <mod>((x==0?0:mod-x));
	}
};

template <int mod>
inline int mabs(const ModInt <mod> &a)
{
	return a.x;
}

template <int mod>
bool operator == (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return a.x==b.x;
}

template <int mod>
bool operator == (ModInt <mod> a,int x)
{
	return (a.x==x);
}

template <int mod>
bool operator != (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return (a.x!=b.x);
}

template <int mod>
bool operator != (ModInt <mod> a,int x)
{
	return (a.x!=x);
}

template <int mod>
inline ModInt <mod> operator + (ModInt <mod> a,int b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
	return a;
}

template <int mod>
inline ModInt <mod> operator + (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x+b.x;
	if(tmp>=mod) tmp-=mod;
	return tmp;
}

template <int mod>
inline ModInt <mod> operator - (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x-b.x;
	if(tmp<0) tmp+=mod;
	return tmp;
}

template <int mod>
inline ModInt <mod> operator - (ModInt <mod> a,int b)
{
	return a-(ModInt <mod> )b;
}

template <int mod>
inline void operator -= (ModInt <mod> &a,ModInt <mod> b)
{
	a.x-=b.x;
	a.x+=(a.x>>31&mod);
}

template <int mod,typename T>
inline void operator -= (ModInt <mod> &a,const T &b)
{
	a.x-=b;
	a.x+=(a.x>>31&mod);
}

template <int mod>
inline ModInt <mod> operator * (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
inline ModInt <mod> operator * (const ModInt <mod> &a,const int &b)
{
	return 1LL*a.x*b%mod;
}

template <int mod>
inline void operator *= (ModInt <mod> &a,const ModInt <mod> &b)
{
	a.x=1LL*a.x*b.x%mod;
}

template <int mod,typename T>
inline void operator *= (ModInt <mod> &a,const T &b)
{
	a=a*b;
}

template <int mod>
inline void operator += (ModInt <mod> &a,const ModInt <mod> &b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod,typename T>
void operator +=(ModInt <mod> &a,const T &b)
{
	a.x+=b;
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
void operator /= (ModInt <mod> &a,int b)
{
	a*=inv(ModInt <mod> (b));
}

template <int mod>
void operator /= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a/b;
}

template <int mod>
inline ModInt <mod> operator ^ (ModInt <mod> basic,int x)
{
	ModInt <mod> res=1;
	while(x)
	{
		if(x&1)	res*=basic;
		basic*=basic;
		x>>=1;
	}
	return res;
}

template <int mod>
istream & operator >> (istream &cin,ModInt <mod> &x)
{
	cin>>x.x;
	x.x%=mod;
	if(x.x<0) x.x+=mod;
	return cin;
}

template <int mod>
ostream & operator << (ostream &cout,ModInt <mod> x)
{
	cout<<x.x;
	return cout;
}
#endif
#ifndef _SELF_STRING
#define _SELF_STRING 1
#ifndef _SELF_RAND
#define _SELF_RAND 1
#if __cplusplus < 201103L
long long _Rand_Gen_Num() {return 1LL*rand()*RAND_MAX+rand();}
int rand(int l,int r) {long long x=_Rand_Gen_Num();return x%(r-l+1)+l;}
#else
#include <time.h>
#include <chrono>
#include <random>
using namespace std; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<long long>(l,r)(rng)
#endif
template <typename Iterator>
void _m_random_shuffle(Iterator begin,Iterator end)
{
    for(Iterator it=begin+1;it!=end;it++)
    {
        iter_swap(begin+rand(0,it-begin),it);
    }
}
#define random_shuffle(a,b) _m_random_shuffle(a,b)
#endif
struct StringHash
{
	template <typename T>
	inline bool checkPrime(T x)
	{
		for(T i=2;i*i<=x;i++)
		{
			if(x%i==0) return false;
		}
		return true;
	}
	inline int nextPrime(int x)
	{
		for(int i=x;;i++)
		{
			if(checkPrime(i)) return i;
		}
	}
	int *hh;
	int n;
	int prime;
	int mod;
	int *e;
	inline void init(int _n,int _prime=-1,int _mod=-1)
	{
		n=_n;
		if(_prime==-1) prime=nextPrime(rand(1e8,3e8));else prime=_prime;
		if(_mod==-1) mod=nextPrime(rand(8e8,1e9));else mod=_mod;
		hh=new int[n+5];
		e=new int[n+5];
		e[0]=1;
		for(int i=1;i<n;i++)
		{
			e[i]=1LL*e[i-1]*prime%mod;
		}
	}
	inline void feedString(const char c[])
	{
		n=strlen(c);
		hh[0]=c[0];
		for(int i=1;i<n;i++)
		{
			hh[i]=(1LL*hh[i-1]*prime+c[i])%mod;
		}
	}
	inline int getHash(int pos,int len)
	{
		assert(pos+len<=n);
		return ((pos+len-1>=0?hh[pos+len-1]:0)-1LL*(pos-1>=0?hh[pos-1]:0)*e[len]%mod+mod)%mod;
	}
	inline bool same(int x,int y,int len)
	{
		if(x+len>n) return false;
		if(y+len>n) return false;
		return (getHash(x,len)==getHash(y,len));
	}
};

template <int P>
struct HashValue
{
	int hashValue[P];
	bool operator == (HashValue x)
	{
		for(int i=0;i<P;i++)
		{
			if(hashValue[i]!=x.hashValue[i]) return false;
		}
		return true;
	}
};

template <int P>
struct MultipleStringHash
{
	StringHash h[P];
	int n;
	inline void init(int _n)
	{
		n=_n;
		for(int i=0;i<P;i++)
		{
			h[i].init(n);
		}
	}
	inline void feedString(char c[])
	{
		for(int i=0;i<P;i++)
		{
			h[i].feedString(c);
		}
	}
	inline HashValue <P> getHash(int x,int len)
	{
		HashValue <P> g;
		for(int i=0;i<P;i++)
		{
			g.hashValue[i]=h[i].getHash(x,len);
		}
		return g;
	}
	inline bool same(int x,int y,int len)
	{
		return (getHash(x,len)==getHash(y,len));
	}
};

template <int P>
struct PalindromeHash
{
	StringHash h[P];
	StringHash rh[P];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<P;i++)
		{
			h[i].init(n);
		}
		for(int i=0;i<P;i++)
		{
			rh[i].init(n,h[i].prime,h[i].mod);
		}
	}
	void feedString(char c[])
	{
		n=strlen(c);
		for(int i=0;i<P;i++)
		{
			h[i].feedString(c);
		}
		reverse(c,c+n);
		for(int i=0;i<P;i++)
		{
			rh[i].feedString(c);
		}
		reverse(c,c+n);
	}
	bool checkOdd(int x,int len)
	{
		for(int i=0;i<P;i++)
		{
			if(h[i].getHash(x,len)!=rh[i].getHash(n-x-1,len)) return false;
		}
		return true;
	}
	inline int maxOdd(int x)
	{
		int l=1,r=min(x+1,n-x),mid,res=1;
		while(l<=r)
		{
			mid=l+r>>1;
			if(checkOdd(x,mid))
			{
				res=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		return res;
	}
};

string tostring(int x)
{
	string res="";
	while(x)
	{
		res.push_back(x%10+'0');
		x/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}

int toint(string c)
{
	int res=0;
	for(auto &x:c)
	{
		res=res*10+x-'0';
	}
	return res;
}

vector <int> toint(vector <string> vec)
{
	vector <int> res;
	for(auto &x:vec)
	{
		res.push_back(toint(x));
	}
	return res;
}

inline vector <string> split(string x,char c)
{
	int l=x.size();
	vector <string> vec;
	int front=0;
	for(int i=0;i<l;i++)
	{
		if(x[i]==c)
		{
			if(i) vec.push_back(x.substr(front,i-front));
			front=i+1;
		}
	}
	if(x.back()!=c) vec.push_back(x.substr(front,(int)x.size()-front));
	return vec;
}

inline bool isPalindrome(string x)
{
	int len=x.size();
	for(int i=0;i<len/2;i++)
	{
		if(x[i]!=x[len-1-i]) return false;
	}
	return true;
}
#endif
using namespace std;
using Int=ModInt <mod>;
int n,q;
string s0,t;
char buf[2000005];
string s[22];
int kk;
Int bin[200005][26];
int k;
string final;
const int prime=23333;
Int hzheng[2000005];
Int hfan[2000005];
Int pow2[2000005];
Int czheng[2000005];
Int cfan[2000005];
Int cnt[26];
Int ppow[2000005];
StringHash h[26];
StringHash ch;

inline Int gethash(Int h[],int l,int r)
{
	return h[r-1]-(l?h[l-1]*ppow[r-l]:0);
}

inline void solve()
{
	scanf("%d%s",&k,buf);
	int n=strlen(buf);
	int kk=0;
	for(;kk<=k;kk++)
	{
		if((int)s[kk].size()>=n) break;
	}
	if(kk==k+1)
	{
		puts("0");
		return;
	}
	ch.feedString(buf);
	int m=s[kk].size();

	Int ba=0;
	for(int i=0;i<=m-n;i++)
	{
		if(h[kk].getHash(i,n)==ch.getHash(0,n)) ba++;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++)
	{
		cnt[buf[i]-'a']+=(h[kk].getHash(m-i,i)==ch.getHash(0,i) && h[kk].getHash(0,n-i-1)==ch.getHash(i+1,n-i-1));
	}
	// cout<<s[kk]<<' '<<buf<<' '<<ba<<endl;
	Int res=ba*pow2[k-kk];
	for(int i=0;i<26;i++)
	{
		res+=(bin[k][i]-bin[kk][i]*pow2[k-kk])*cnt[i];
	}
	printf("%d\n",res.x);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>q;
	ch.init(1e6,prime,mod);
	pow2[0]=1;
	ppow[0]=1;
	for(int i=1;i<=1e6;i++) pow2[i]=pow2[i-1]*2,ppow[i]=ppow[i-1]*prime;
	cin>>s0;
	scanf("%s",buf);
	t=buf;
	s[0]=s0;
	for(kk=1;kk<=n;kk++)
	{
		s[kk]=s[kk-1]+t[kk-1]+s[kk-1];
		if(s[kk].size()>1000000) break;
	}
	for(int i=0;i<=kk;i++)
	{
		h[i].init(s[i].size(),prime,mod);
		h[i].feedString(s[i].c_str());
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<26;j++) 
		{
			bin[i][j]=(i?bin[i-1][j]:0)*2+(t[i-1]-'a'==j);
		}
	}
	while(q--)
	{
		solve();
	}
	return 0;
}