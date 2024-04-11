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
int TT,n,m,a[100005],id[100005];
int sz[100005],sum[100005],pos[100005];
vector<int>b[100005];
struct SGT{
	#define SIZE 131072
	bool f[SIZE<<1];
	void update(int x,int v){
		x+=SIZE;f[x]=v;
		while(x!=1){
			x>>=1;
			f[x]=f[x<<1]&f[x<<1|1];
		}
	}
	bool query(int l,int r,int k,int ql,int qr){
		if(qr<l||r<ql)return true;
		if(ql<=l&&r<=qr)return f[k];
		return query(l,(l+r)/2,k<<1,ql,qr)&query((l+r)/2+1,r,k<<1|1,ql,qr);
	}
}T[3];
bool cmp(int x,int y){
	return sum[x]*sz[y]<sum[y]*sz[x];
}
signed main(){
	TT=getint();
	while(TT--){
		n=getint();m=getint();
		for(int i=1;i<=n;i++)a[i]=getint();
		a[0]=0;sort(a,a+n+1);
		for(int i=0;i<=m;i++)a[i]=a[i+(n-m)];
//		for(int i=0;i<=m;i++)cerr<<a[i]<<" ";cerr<<endl;
		a[m+1]=0;
		for(int i=1;i<=m;i++){
			sz[i]=getint();
			b[i].clear();
			b[i].shrink_to_fit();
			b[i].resize(sz[i]);
			for(int j=0;j<sz[i];j++)b[i][j]=getint();
		}
		for(int i=1;i<=m;i++){
			sum[i]=0;
			for(int j=0;j<sz[i];j++)sum[i]+=b[i][j];
		}
		for(int i=1;i<=m;i++)id[i]=i;
		sort(id+1,id+m+1,cmp);
		for(int i=1;i<=m;i++)pos[id[i]]=i;
		for(int x=1;x<=m;x++){
			int i=id[x];
			T[0].update(x,a[x-1]*sz[i]>=sum[i]);
			T[1].update(x,a[x]*sz[i]>=sum[i]);
			T[2].update(x,a[x+1]*sz[i]>=sum[i]);
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<sz[i];j++){
				if(b[i][j]*sz[i]>=sum[i]){
					//dec
					int l=0,r=m+1;
					while(r-l>1){
						int mid=(l+r)/2;
						if(a[mid]*(sz[i]-1)>=sum[i]-b[i][j])r=mid;
						else l=mid;
					}
					if(r==m+1){
						putchar('0');
						continue;
					}
					int x=pos[i];
					if(T[2].query(0,SIZE-1,1,r,x-1)&&T[1].query(0,SIZE-1,1,1,r-1)&&T[1].query(0,SIZE-1,1,x+1,m))putchar('1');
					else putchar('0');
				}else{
					//inc
					int l=0,r=m+1;
					while(r-l>1){
						int mid=(l+r)/2;
						if(a[mid]*(sz[i]-1)>=sum[i]-b[i][j])r=mid;
						else l=mid;
					}
					if(r==m+1){
						putchar('0');
						continue;
					}
					int x=pos[i];
					if(T[0].query(0,SIZE-1,1,x+1,r)&&T[1].query(0,SIZE-1,1,1,x-1)&&T[1].query(0,SIZE-1,1,r+1,m))putchar('1');
					else putchar('0');
				}
			}
		}
		putchar('\n');
	}
	return 0;
}