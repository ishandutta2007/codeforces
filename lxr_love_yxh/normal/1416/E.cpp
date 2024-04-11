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
const int inf=0x3f3f3f3f3f3f3f3f;
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
int T,n,ans,mul,add;
int a[500005];
set<pair<int,int> >s;
void reset(){
	mul=1;add=0;s.clear(); 
}
void del(int x){
	//delete all elements >=x
	x-=add;x/=mul;
	if(mul==1){
		while(!s.empty()){
			auto p=*s.rbegin();
			if(p.second<x)break;
			s.erase(p);
			if(p.first>=x)continue;
			p.second=x-1;
			s.insert(p);
			break;
		}
	}else{
		while(!s.empty()){
			auto p=*s.begin();
			if(p.first>x)break;
			s.erase(p);
			if(p.second<=x)continue;
			p.first=x+1;
			s.insert(p);
			break;
		}
	}
}
bool Find(int x){
	x-=add;x/=mul;
	auto itr=s.lower_bound(make_pair(x+1,-inf));
	if(itr==s.begin())return 0;
	itr--;
	cerr<<itr->first<<" "<<itr->second<<" "<<x<<endl;
	if(itr->first>x)assert(0);
	if(itr->second>=x)return 1;
	else return 0;
}
int Min(){
	if(!s.size())return inf;
	if(mul==1){
		auto v=s.begin()->first;
		v+=add;return v;
	}else{
		auto v=s.rbegin()->second;
		v=v*mul+add;return v;
	}
}
void ins(int x){
	if(Find(x))return;
	x-=add;x/=mul;
	s.insert(make_pair(x,x));
}
void lqs(int x){
	mul=-mul;add=-add+x;
}
signed main(){
	T=getint();
	while(T--){
		n=getint();reset();
		for(int i=1;i<=n;i++)a[i]=getint();
		s.insert(make_pair(inf,inf));
		ans=0;
		for(int i=1;i<=n;i++){
//			cerr<<i<<" "<<Min()<<endl;
			if(a[i]%2==0&&Find(a[i]/2)){
				cerr<<2<<endl;
				ans+=2;reset();s.insert(make_pair(a[i]/2,a[i]/2));
				continue;
			}
			if(a[i]%2&&Min()>=a[i]){
				cerr<<0<<endl;
				reset();s.insert(make_pair(1,a[i]-1));
				continue;
			}
			cerr<<1<<endl;
			cerr<<mul<<" "<<add<<" "<<s.begin()->first<<" "<<s.begin()->second<<endl;
			ans+=1;
			del(a[i]);
//			cerr<<"del"<<endl;
			cerr<<mul<<" "<<add<<" "<<s.begin()->first<<" "<<s.begin()->second<<endl;
			if(a[i]%2==0)ins(a[i]/2);
//			cerr<<"ins"<<endl;
			cerr<<mul<<" "<<add<<" "<<s.begin()->first<<" "<<s.begin()->second<<endl;
			lqs(a[i]);
			cerr<<mul<<" "<<add<<" "<<s.begin()->first<<" "<<s.begin()->second<<endl;
//			cerr<<"lqs"<<endl;
		}
		putln(n*2-ans);
	}
	clear();
	return 0;
}