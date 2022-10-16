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
int n,m,a[100005],b[100005],pos[100005];
vector<int>to[100005];
int dist[100005],cnt[100005],ans;
int get(int x,int y){
	return abs(a[x]-b[y]);
}
int main(){
	n=getint();m=getint();getint();getint();
	for(int i=1;i<=n;i++)a[i]=getint();
	for(int i=1;i<=m;i++)b[i]=getint();
	pos[0]=1;b[0]=-inf;b[m+1]=inf;
	for(int i=1;i<=n;i++){
		pos[i]=pos[i-1];
		while(pos[i]<=m&&b[pos[i]]<=a[i])pos[i]++;
	}
	for(int i=1;i<=n;i++){
		int mn=min(a[i]-b[pos[i]-1],b[pos[i]]-a[i]);
		if(a[i]-b[pos[i]-1]==mn)to[i].push_back(pos[i]-1);
		if(b[pos[i]]-a[i]==mn)to[i].push_back(pos[i]);
	}
	memset(dist,inf,sizeof dist);
	ans=0;
	for(int i=1;i<=n;i++){
		if(to[i].size()==1){
			if(get(i,to[i][0])<dist[to[i][0]]){
				dist[to[i][0]]=get(i,to[i][0]);
				ans-=cnt[to[i][0]];
				cnt[to[i][0]]=1;
				ans+=cnt[to[i][0]];
			}else if(get(i,to[i][0])==dist[to[i][0]]){
				cnt[to[i][0]]++;
				ans++;
			}
		}else{
			int l=to[i][0],r=to[i][1];
			if(dist[l]!=get(i,l)&&dist[l]!=inf){
				assert(dist[r]>get(i,r));
				dist[r]=get(i,r);
				ans-=cnt[r];
				cnt[r]=1;
				ans+=cnt[r];
			}else{
				dist[l]=min(dist[l],get(i,l));
				cnt[l]++;ans++;
			}
		}
	}
	for(int i=1;i<=m;i++)cerr<<dist[i]<<" ";cerr<<endl;
	for(int i=1;i<=m;i++)cerr<<cnt[i]<<" ";cerr<<endl;
	cout<<n-ans<<endl;
	return 0;
}