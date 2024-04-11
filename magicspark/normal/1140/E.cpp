#include<bits/stdc++.h>
#define int long long
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
    	int r=0; bool ng=0; char c; c=get();
    	while (c!='-'&&(c<'0'||c>'9')) c=get();
   		if (c=='-') ng=1, c=get();
    	while (c>='0'&&c<='9') r=r*10+c-'0', c=get();
    	return ng?-r:r;
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
		put('\n');
	}
}
using fastio::getint;
using fastio::getstr;
using fastio::putint;
using fastio::putstr;
using fastio::clear;
using fastio::putln;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k;
int a[111111],b[111111];
inline int inv(int x){
	return modpow(x,mod-2,mod);
}
int calc(int *f,int len){
	vector<pair<int,int> >v;
	int l=-1,r=0;
	for(int i=0;i<len-1;i++)if(f[i]!=-1&&f[i]==f[i+1])return 0;
	while(l<len){
		r=l+1;while(r<len&&f[r]==-1)r++;
		if(r-l>1)v.push_back(make_pair(l==-1||r==len?0:f[l]==f[r]?1:2,r-l-1));l=r;
	}
	int ret=1;
	for(auto p:v){
		int type=p.first,ln=p.second;
		if(type==0){
			ret=ret*modpow(k-1,ln)%mod;
		}else if(type==1){
			int mul=1;
			if(ln&1){
				mul=(modpow(k-1,ln)+1)*inv(k)-1;
			}else{
				mul=(modpow(k-1,ln)-1)*inv(k)+1;
			}
			mul%=mod;mul=(modpow(k-1,ln)-mul+mod)%mod;
			ret=ret*mul%mod;
		}else{
			int mul=1;
			if(ln%2==1){
				mul=(modpow(k-1,ln)+1)*inv(k);
			}else{
				mul=(modpow(k-1,ln)-1)*inv(k);
			}
			mul%=mod;mul=(modpow(k-1,ln)-mul+mod)%mod;
			ret=ret*mul%mod;
		}
	}
//	cerr<<"ret:"<<(v.size()==1&&v[0].second==len?modpow(k-1,len-1)*k%mod:ret)<<endl;
	if(v.size()==1&&v[0].second==len)return modpow(k-1,v[0].second-1)*k%mod;
	return ret;
}
signed main(){
	n=getint();k=getint();
	for(int i=0;i<n;i++){
		if(i&1)b[i/2]=getint();
		else a[i/2]=getint();
	}
	cout<<calc(b,n/2)*calc(a,(n+1)/2)%mod<<endl;
	return 0;
}