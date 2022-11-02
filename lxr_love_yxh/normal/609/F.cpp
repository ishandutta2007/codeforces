/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
namespace fastio{
    char in[100000];
    int itr=0,llen=0;
    char get(){
        if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
        if(llen==0)return EOF;
        return in[itr++];
    }
    char out[100000];
    int itr2=0;
    void put(char c){
        out[itr2++]=c;
        if(itr2==100000){
            fwrite(out,1,100000,stdout);
            itr2=0;
        }
    }
    int clear(){
        fwrite(out,1,itr2,stdout);
        itr2=0;
        return 0;
    }
    int getint(){
        int ret=0;char ch=get();
        if(ch=='-')return -getint();
        while (ch<'0'||ch>'9'){
            ch=get();if(ch=='-')return -getint();
        }
        while ('0'<=ch&&ch<='9'){
            ret=ret*10-48+ch;
            ch=get();
        }
        return ret;
    }
    string getstr(){
        string ret="";
        char ch=get();
        while(ch==' '||ch=='\n')ch=get();
        while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
        return ret;
    }
    void putstr(string s){
        for(int i=0;i<s.size();i++)put(s[i]);
    }
    template<class T>void putint(T x){
        if(x<0){
            put('-');
            putint(-x);
            return;
        }
        if(x==0){
            put('0');put(' ');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put(' ');
    }
    template<class T>void putln(T x){
        if(x<0){
            put('-');
            putln(-x);
            return;
        }
        if(x==0){
            put('0');put('\n');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put('\n');
    }
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
struct SGT{
	#define SIZE 524288
	int f[SIZE<<1];
	SGT(){memset(f,-1,sizeof f);}
	void update(int x,int v){
		x+=SIZE;
		if(f[x]==-1)f[x]=v;
		else f[x]+=v;
		while(x!=1){
			x>>=1;
			f[x]=max(f[x<<1],f[x<<1|1]);
		}
	}
	int query(int x){
		int k=1;
		while(k<SIZE){
			if(f[k<<1]>=x)k<<=1;
			else k=k<<1|1;
		}
		return k-SIZE;
	}
	int Get(int x){
		return f[x+SIZE];
	}
}T;
int n,m;
struct event{
	int x,t,id;
};
event p[500005];
bool cmp(event a,event b){
	return a.x<b.x;
}
int pos[500005],b[500005],ans[500005],cnt[500005];
multiset<pair<int,int> >s;
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=getint();m=getint();
	for(int i=1;i<=n;i++){
		p[i].x=getint();
		p[i].t=getint();
		p[i].id=i;
	}
	T.update(n+1,inf);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
//		cerr<<i<<" "<<p[i].x<<" "<<p[i].t<<endl;
		T.update(i,p[i].x+p[i].t);
	}
	for(int i=1;i<=m;i++){
		pos[i]=getint();b[i]=getint();
		int tar=T.query(pos[i]);
		if(tar>n||p[tar].x>pos[i]){
			s.insert(make_pair(pos[i],b[i]));
			continue;
		}
		T.update(tar,b[i]);
		cnt[p[tar].id]++;
		int val=T.Get(tar);
		auto itr=s.lower_bound(make_pair(p[tar].x,0));
		while(itr!=s.end()&&itr->first<=val){
			T.update(tar,itr->second);val+=itr->second;
			cnt[p[tar].id]++;s.erase(itr++);
		}
	}
	for(int i=1;i<=n;i++){
		ans[p[i].id]=T.Get(i)-p[i].x;
	}
	for(int i=1;i<=n;i++){
		putint(cnt[i]);putln(ans[i]);
	}
	clear();
	return 0;
}