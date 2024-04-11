/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
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
    void putint(int x){
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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
int n;
string s;
const int base=29;
int hsh[1000005],pw[1000005],ans[500005];
void build_hash(){
	hsh[0]=0;
	for(int i=1;i<=n;i++){
		hsh[i]=(hsh[i-1]*base+s[i]-'a'+1)%mod;
	}
}
int get_hash(int l,int r){
	return (hsh[r]-pw[r-l+1]*hsh[l-1]%mod+mod)%mod;
}
bool same(int x,int y,int l){
	if(x+l-1>n||y+l-1>n)return 0;
	if(x<=0||y<=0)return 0;
	if(x==y)return false;
	return get_hash(x,x+l-1)==get_hash(y,y+l-1);
}
signed main(){
	n=getint();s=" "+getstr();
	for(int i=1;i<=n;i++)s+='b';
	build_hash();
	for(int i=1;i<=(n+1)/2;i++){
		ans[i]=s[i]==s[n-i+1]&&i!=n-i+1?1:-1;
	}
	pw[0]=1;
	for(int i=1;i<=1e6;i++)pw[i]=pw[i-1]*base%mod;
	for(int i=(n+1)/2;i>=1;i--){
		if(s[i]!=s[n-i+1]||i==n-i+1)continue;
		int l=0,r=n+1;
		while(r-l>1){
			int mid=(l+r)/2;
			if(same(n-i+2,i+1,mid)&&same(i-mid,n-i+1-mid,mid)){
				l=mid;
			}else r=mid;
		}
		ans[i-l]=max(ans[i-l],l+l+1);
	}
	for(int i=1;i<=(n+1)/2;i++)ans[i]=max(ans[i],ans[i-1]-2);
	for(int i=1;i<=(n+1)/2;i++){
		putint(ans[i]);
	}
	clear();
	return 0;
}