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
struct SegTree{
	#define SIZE 1048576
	ll f[SIZE<<2]={},lazy[SIZE<<2]={};
	void addpoint(int pos,int v){
		pos+=SIZE-1; 
		f[pos]=v;
		while(pos){
			pos=pos-1>>1;
			f[pos]=max(f[pos+pos+1],f[pos+pos+2]);
		}
	}
	ll query(int l,int r,int l1=0,int r1=SIZE-1,int k=0){
		//if(l<=l1&&r1<=r)cerr<<l<<" "<<r<<" "<<l1<<" "<<r1<<" "<<k<<" "<<f[k]<<" "<<lazy[k]<<endl;
		if(l<=l1&&r1<=r)return f[k]+lazy[k];
		if(r<l1||r1<l)return (ll)-1e18;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		ll vl=query(l,r,l1,mid,k+k+1);
		ll vr=query(l,r,mid+1,r1,k+k+2);
		f[k]=max(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		//cerr<<l<<" "<<r<<" "<<l1<<" "<<r1<<" "<<vl<<" "<<vr<<endl;
		return max(vl,vr);
	}
	void addrange(int l,int r,int v,int l1=0,int r1=SIZE-1,int k=0){
		if(l<=l1&&r1<=r){
			//cerr<<l<<" "<<r<<" "<<l1<<" "<<r1<<" "<<k<<" "<<v<<endl;
			lazy[k]+=v;
			return;
		}
		if(l1>r||r1<l)return;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		addrange(l,r,v,l1,mid,k+k+1);
		addrange(l,r,v,mid+1,r1,k+k+2);
		f[k]=max(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		return;
	}
}T;
int n,m,p;
pair<int,int>a[200005],b[200005];
int x[200005],y[200005],z[200005],inv[200005],cost[1000005],tmp[1000005];
vector<pair<int,int> >vec[1000005];//pos,val
map<int,int>mp;
signed main(){
	memset(cost,inf,sizeof cost);
	memset(tmp,inf,sizeof tmp);
	n=getint();m=getint();p=getint();
	for(int i=1;i<=n;i++){
		a[i].first=getint();a[i].second=getint();
		cost[a[i].first]=min(cost[a[i].first],a[i].second);
	}
	for(int i=1;i<=m;i++){
		b[i].first=getint();b[i].second=getint();
	}
	for(int i=1;i<=m;i++){
		tmp[b[i].first]=min(tmp[b[i].first],b[i].second);
	}
	for(int i=1;i<=p;i++){
		x[i]=getint();y[i]=getint();z[i]=getint();
		vec[x[i]].push_back(make_pair(y[i],z[i]));
	}
	ll ans=-1e18;
	for(int i=1;i<=1e6;i++)T.addpoint(i,-tmp[i]);
	for(int i=1;i<=1e6+1;i++){
		for(auto p:vec[i-1]){
			T.addrange(p.first+1,1e6,p.second);
		}
		if(cost[i]<=1e12){
//			cout<<i<<" "<<T.query(1,1e6)<<" "<<cost[i]<<endl;
			ans=max(ans,T.query(1,1e6)-cost[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}