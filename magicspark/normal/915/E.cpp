/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment(" -Wl,--stack=1024000000")
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
    void putint(int x){
        if(x<0){
            put('-');
            putint(-x);
            return;
        }
        if(x==0){
            put('0');
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
    void putln(int x){
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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
struct range{
	int l,r,c;
	range(int L,int R,int C){l=L;r=R;c=C;}
};
inline bool operator<(range a,range b){
	return a.l<b.l;
}
multiset<range>S;
inline int func(multiset<range>::iterator &itr){
	return itr->c?(itr->r-itr->l+1):0;
}
int main(){
	scanf("%d%d",&n,&m);
	S.insert(range(1,n,1));
	int ans=n;
	while(m--){
		int l,r,c;scanf("%d%d%d",&l,&r,&c);c--;
		ans+=(r-l+1)*c;
//		show_set();
		multiset<range>::iterator itr=S.lower_bound(range(l+1,r,c)),p=itr;p--;
		if(p->l<l)S.insert(range(p->l,l-1,p->c)),ans+=p->c?(l-p->l):0;
		if(p->r>r)S.insert(range(r+1,p->r,p->c)),ans+=p->c?(p->r-r):0;
		ans-=func(p);S.erase(p);
		if(p->r>r){
			S.insert(range(l,r,c));
			printf("%d\n",ans);
			continue;
		}
		while(itr!=S.end()&&itr->r<=r){
			ans-=func(itr);S.erase(itr++);
		}
		if(itr!=S.end()&&itr->r>r&&itr->l<=r){
			S.insert(range(r+1,itr->r,itr->c));
			ans+=itr->c?(itr->r-r):0;ans-=func(itr);S.erase(itr);
		}
		S.insert(range(l,r,c));
		printf("%d\n",ans);
	}
	clear();
	return 0;
}