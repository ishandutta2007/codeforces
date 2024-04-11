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
const double eps=1e-9;
const int mod=998244353;
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
int n,m;
string s[2005];
string t[2005];
vector<int>g[4005];
int par[4005];
int R[2005],C[2005];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void merge(int x,int y){
	par[find(x)]=find(y);
}
vector<int>buc[4005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)s[i]=" "+getstr();
	if(n%2==0&&m%2==0){
		int k=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='?')k++;
		cout<<modpow(2,k)<<endl;
		return 0;
	}
	if(n%2==1&&m%2==0){
		for(int j=1;j<=m;j++)t[j]=" ";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				t[j].push_back(s[i][j]);
			}
		}
		for(int i=1;i<=m;i++)s[i]=t[i];
		swap(n,m);
	}
	if(n%2==0&&m%2==1){
		int ans=0;
		for(int x=0;x<2;x++){
			bool valid=1;
			for(int i=1;i<=n;i++){
				int cur=0,vis=0;
				for(int j=1;j<=m;j++){
					if(s[i][j]=='?'){
						vis=1;
						break;
					}
					cur^=s[i][j]-'0';
				}
				if(vis)continue;
				if(cur!=x){
					valid=0;
					break;
				}
			}
			int k=0;
			if(valid){
				for(int i=1;i<=n;i++){
					int tot=0;
					for(int j=1;j<=m;j++){
						if(s[i][j]=='?')tot++;
					}
					if(tot)k+=tot-1;
				}
				ans=(ans+modpow(2,k))%mod;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=0;i<4005;i++)par[i]=i;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='?'){
		g[i].push_back(j+2001);
		g[j+2001].push_back(i);
		merge(i,j+2001);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]!='?')R[i]^=s[i][j]-'0',C[j]^=s[i][j]-'0';
		}
	}
	for(int i=1;i<=n;i++)buc[find(i)].push_back(i);
	for(int i=1;i<=m;i++)buc[find(i+2001)].push_back(i+2001);
	int ans=0,cc=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='?')cc++;
	for(int x=0;x<2;x++){
		bool valid=1;int cnt=0;
		for(int i=0;i<4005;i++)if(buc[i].size()){
			int s1=0,s2=0;cnt++;
			for(auto u:buc[i]){
				int sum=(u<2001?R[u]:C[u-2001])^x;
				if(u<2001)s1^=sum;
				else s2^=sum;
			}
			if(s1!=s2)valid=0;
		}
//		cerr<<cc<<" "<<cnt<<" "<<n<<" "<<m<<endl;
		if(valid)ans=(ans+modpow(2,cc+cnt-n-m))%mod;
	}
	cout<<ans<<endl;
	return 0;
}