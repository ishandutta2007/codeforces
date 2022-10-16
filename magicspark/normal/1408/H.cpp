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
int T,n,cnt,a[500005],l[500005],r[500005];
vector<int>occ[500005];
int cl[500005],cr[500005];
#define SIZE 524288
int f[SIZE<<1],tag[SIZE<<1];
void set_v(int x,int v){
	x+=SIZE;f[x]=v;tag[x]=0;
	while(x!=1){
		x>>=1;tag[x]=0;
		f[x]=min(f[x<<1],f[x<<1|1]);
	}
}
void pushdown(int x){
	tag[x<<1]+=tag[x];
	tag[x<<1|1]+=tag[x];
	tag[x]=0;
}
void pushup(int x){
	f[x]=min(f[x<<1]+tag[x<<1],f[x<<1|1]+tag[x<<1|1]);
}
void add(int l,int r,int k,int ql,int qr,int qv){
	if(r<ql||qr<l)return;
	if(ql<=l&&r<=qr){
		tag[k]+=qv;return;
	}
	pushdown(k);
	add(l,(l+r)/2,k<<1,ql,qr,qv);
	add((l+r)/2+1,r,k<<1|1,ql,qr,qv);
	pushup(k);
}
int query(int l,int r,int k,int ql,int qr){
	if(r<ql||qr<l)return 1e9;
	if(ql<=l&&r<=qr){
		return f[k]+tag[k];
	}
	pushdown(k);
	int vl=query(l,(l+r)/2,k<<1,ql,qr);
	int vr=query((l+r)/2+1,r,k<<1|1,ql,qr);
	pushup(k);
	return min(vl,vr);
}
int R[500005];
int getR(int x){
	return lower_bound(R,R+cnt+1,x)-R;
}
int main(){
	T=getint();
	while(T--){
		n=getint();
		memset(cl,0,sizeof cl[0]*(n+2));
		memset(cr,inf,sizeof cr[0]*(n+2));
		for(int i=1;i<=n;i++)a[i]=getint();
		for(int i=0;i<=n;i++)occ[i].clear();
		cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==0)cnt++;
		cnt/=2;
		int ccl=0,ccr=0;
		if(cnt){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					l[++ccl]=i;
					if(ccl==cnt)break;
				}
			}
			for(int i=n;i>=1;i--){
				if(a[i]==0){
					r[++ccr]=i;
					if(ccr==cnt)break;
				}
			}
		}
		memcpy(R,r,sizeof r[0]*(cnt+5));
		reverse(R+1,R+cnt+1);
		for(int i=1;i<=n;i++){
			if(i<=r[cnt]&&a[i]){
				cl[a[i]]=max(cl[a[i]],i);
			}
			if(i>=l[cnt]&&a[i]){
				cr[a[i]]=min(cr[a[i]],i);
			}
		}
		int bs=0,cur=0,ans;
		for(int i=1;i<=n;i++){
			if(cl[i]==cr[i]){
				bs++;continue;
			}
			if(cl[i]!=0||cr[i]!=inf){
				occ[cl[i]].push_back(cr[i]);
				cur++;
			}
		}
		for(int i=0;i<=n;i++)sort(occ[i].begin(),occ[i].end());
		for(int i=0;i<=cnt;i++)set_v(i,i);
		for(int j=0;j<l[1];j++){
			for(auto v:occ[j]){
				add(0,SIZE-1,1,0,cnt-getR(v),1);
				cur--;
			}
		}
		ans=cur+query(0,SIZE-1,1,0,cnt);
		for(int i=1;i<=cnt;i++){
			for(int j=l[i]+1;j<l[i+1];j++){
				for(auto v:occ[j]){
					add(0,SIZE-1,1,0,cnt-getR(v),1);
					cur--;
				}
			}
			ans=min(ans,cur+i+query(0,SIZE-1,1,0,cnt));
		}
		putln(min(cnt,ans+bs));
	}
	clear();
	return 0;
}