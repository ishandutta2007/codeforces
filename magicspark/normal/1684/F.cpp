/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
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
        while(isspace(ch))ch=get();
        while(!isspace(ch))ret.push_back(ch),ch=get();
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
	struct Flusher_ {
		~Flusher_(){clear();}
	}io_flusher_;
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
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
int T,n,m,low,high;
int a[200005],l[200005],r[200005],lst[200005],go[200005],lmt[200005];
//lmt[i]  when r=i llmt[i]
void update_ban(int l,int r){
	if(go[l]<r)return;
	if(l>r)return;
	r--;lmt[r]=min(lmt[r],l);
}
int main(){
	T=getint();
	while(T--){
		memset(lst,inf,sizeof lst);
		memset(go,0,sizeof go);
		memset(lmt,inf,sizeof lmt);
		n=getint();m=getint();
		low=0;high=n+1;
		map<int,vector<int> >mp;
		for(int i=1;i<=n;i++)a[i]=getint();
		for(int i=1;i<=m;i++){
			l[i]=getint();r[i]=getint();
			go[l[i]]=max(go[l[i]],r[i]);
		}
		for(int i=1;i<=n;i++)go[i]=max(go[i],go[i-1]);
		for(int i=n;i>=1;i--){
			if(!mp.count(a[i])){
				mp[a[i]].push_back(-i);
			}else{
				auto &vec=mp[a[i]];
				auto itr=upper_bound(vec.begin(),vec.end(),-go[i]-1);
				auto tmp=-vec.back();
				if(tmp<=go[i])low=max(low,i);
//				cerr<<i<<" "<<go[i]<<" "<<-*itr<<endl;
				if(itr!=vec.end())update_ban(i,-*itr);
				mp[a[i]].push_back(-i);
			}
		}
		mp.clear();
		for(int i=1;i<=n;i++){
			if(!mp.count(a[i])){
				mp[a[i]].push_back(i);
			}else{
				auto tmp=mp[a[i]].back();
				if(go[tmp]>=i)high=min(high,i);
				mp[a[i]].push_back(i);
			}
		}
		cerr<<low<<" "<<high<<endl;
		for(int r=n;r>=1;r--)lmt[r]=min(lmt[r],lmt[r+1]);
		int ans=inf;
		for(int r=low;r<=n;r++)cerr<<r<<" "<<high<<" "<<lmt[r]<<endl;
		for(int r=low;r<=n;r++)ans=min(ans,max(0,r-min(high,lmt[r])+1));
		cout<<ans<<endl;
//		for(int r=1;r<=n;r++)cerr<<r<<" "<<lmt[r]<<endl;
	}
	return 0;
}