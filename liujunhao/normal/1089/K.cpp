#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 100000000000000000ll
#define gc getchar()
#define abs(x) ((x)>0?(x):(-(x)))
#define X first
#define Y second
#define mp(x,y) make_pair((x),(y))
#define eps (1e-8)
#define pb push_back
#define pf(x) ((x)*(x))
#define il inline

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;

#define int ll

il ll read()
{
	char c=gc;ll u=0,f=1;
	while(c!='-' && (c<'0' || '9'<c))c=gc;
	if(c=='-'){
		f=-1;
		c=gc;
	}
	while('0'<=c && c<='9'){
		u=u*10+c-'0';
		c=gc;
	}
	return u*f;
}
il char readc()
{
	for(;;){
		char c=gc;
		if('A'<=c && c<='Z' || 'a'<=c && c<='z')return c;
	}
}
il int read_digit()
{
	for(;;){
		char c=gc;
		if('0'<=c && c<='9')return c-'0';
	}
}
il char reads()
{
    for(;;){
        char c=gc;
        if(c=='?' || c=='+' || c=='-')return c;
    }
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
template <typename T>inline void updmax(T &a,T b){if(b>a)a=b;}
template <typename T>inline void updmin(T &a,T b){if(b<a)a=b;}
inline void swap(int &a,int &b){int t=a;a=b;b=t;}

inline void fileio(string s){
	if(s=="txt"){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	else{
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

class answer{
public:
    ll pre,nxt;
    answer(){}
    answer(ll x,ll y){pre=x;nxt=y;}
    answer operator+(answer that)const{
        answer ans=answer(0,0);
        ll u=nxt-that.pre;
        if(u>0){
            ans.pre=pre;
            ans.nxt=that.nxt+u;
        }
        else{
            ans.pre=pre-u;
            ans.nxt=that.nxt;
        }
        return ans;
    }
}val[4000010];

bool haven[1000010];

void build_tree(int k,int l,int r)
{
    if(l==r){
        val[k]=answer(1,0);
        return;
    }
    int mid=(l+r)>>1;
    build_tree(k*2,l,mid);
    build_tree(k*2+1,mid+1,r);
    val[k]=val[k*2]+val[k*2+1];
    //cout<<k<<' '<<l<<','<<r<<' '<<val[k].pre<<' '<<val[k].nxt<<endl;
}

void add(int k,int l,int r,int p,ll x)
{
    if(l==r){
        val[k].nxt+=x;
        if(val[k].pre>0){
            val[k].nxt-=val[k].pre;
            val[k].pre=0;
        }
        else if(val[k].nxt<0){
            val[k].pre-=val[k].nxt;
            val[k].nxt=0;
        }
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid)add(k*2,l,mid,p,x);
    else add(k*2+1,mid+1,r,p,x);
    val[k]=val[k*2]+val[k*2+1];
}

answer query(int k,int l,int r,int s,int t)
{
    if(s>t)return answer(0,0);
    if(l==s && r==t)return val[k];
    int mid=(l+r)>>1;
    if(t<=mid)return query(k*2,l,mid,s,t);
    else if(s>mid)return query(k*2+1,mid+1,r,s,t);
    else return query(k*2,l,mid,s,mid)+query(k*2+1,mid+1,r,mid+1,t);
}

const int N=1000000;

struct Request{
    int st,d;
    Request(){}
    Request(int x,int y){st=x;d=y;}
}a[300010];

void insert(int st,int d)
{
    haven[st]=true;
    add(1,1,N,st,d);
}

void remove(int k)
{
    int st=a[k].st,d=a[k].d;
    haven[st]=false;
    add(1,1,N,st,-d);
}

ll query(int k)
{
    if(haven[k]){
        answer ans=query(1,1,N,1,k);
        return max(ans.nxt+1,0);
    }
    else{
        answer ans=query(1,1,N,1,k-1);
        return ans.nxt;
    }
}

main()
{
    build_tree(1,1,N);
    int n=read();
    for(int i=1;i<=n;i++){
        char c=reads();
        if(c=='?'){
            int u=read();
            cout<<query(u)<<'\n';
        }
        else if(c=='+'){
            a[i].st=read();
            a[i].d=read();
            insert(a[i].st,a[i].d);
        }
        else{
            int u=read();
            remove(u);
        }
    }
    return 0;
}