/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
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
	struct Flusher_ {
		~Flusher_(){clear();}
	}io_flusher_;
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
int n,q;
string t;
string s[55];
vector<int>z_function(const string& s){
    int n=(int)s.size();
    vector<int>z(n);
    int l=0,r=1;
    for(int i=1;i<n;++i){
        if(i<r){
            z[i]=min(z[i-l],r-i);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            ++z[i];
        }
        if (i+z[i]>=r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}
int pw2[1000005];
int sum[100005][26];
int main(){
	pw2[0]=1;
	for(int i=1;i<=1e6;i++)pw2[i]=pw2[i-1]*2%mod;
	n=getint();q=getint();
	s[0]=getstr();t=getstr();
	for(int i=1;i<n&&s[i-1].size()<=1e6;i++){
		s[i]=s[i-1]+t[i-1]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			if(i)sum[i][j]=sum[i-1][j]*2%mod;
			if(t[i-1]=='a'+j){
				sum[i][j]++;
				sum[i][j]%=mod;
			}
		}
	}
	while(q--){
		int ind=getint();string ss=getstr();
		int pos=0;
		while(s[pos].size()<ss.size()&&pos<ind)pos++;
		vector<int>z1=z_function(ss+"#"+s[pos]);
		reverse(s[pos].begin(),s[pos].end());
		reverse(ss.begin(),ss.end());
		vector<int>z2=z_function(ss+"#"+s[pos]);
//		cerr<<ss+"#"+s[pos]<<endl;
		reverse(s[pos].begin(),s[pos].end());
		reverse(ss.begin(),ss.end());
		int ans=0;
		for(int i=ss.size()+1;i<z1.size();i++){
			if(z1[i]==ss.size())ans++;
		}
		if(pos==ind){
			putln(ans);
			continue;
		}
		ans=1ll*ans*pw2[ind-pos]%mod;
//		cerr<<s[pos]<<endl;
		for(int i=0;i<=s[pos].size();i++){
			int ed=i+ss.size(),len=s[pos].size()*2-ed+1;
			int l1=s[pos].size()-i,l2=ss.size()-l1-1;
			if(ed<=s[pos].size())continue;
			int tmp=s[pos].size()-i;
			int count=sum[ind][ss[tmp]-'a']-1ll*sum[pos][ss[tmp]-'a']*pw2[ind-pos]%mod;
			count+=mod;count%=mod;
			if(i<s[pos].size()&&z1[ss.size()+i+1]<l1)continue;
			if(len<s[pos].size()&&z2[ss.size()+len+1]<l2)continue;
//			cerr<<i<<" "<<count<<endl;
			ans+=count;ans%=mod;
		}
		putln(ans);
	}
	return 0;
}