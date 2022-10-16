#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
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
		while(ch<'0'||ch>'9'){
			if(ch=='-')return -getint();ch=get();
		}
		while('0'<=ch&&ch<='9'){
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
using namespace fastio;
struct add_range_query_max_pos{
	#define SIZE 524288
	pair<ll,ll> f[SIZE<<1]={};
	inline pair<ll,ll> func(pair<ll,ll> x,pair<ll,ll> y){return (x.first==y.first?(x.second<y.second?x:y):(x.first>y.first?x:y));}
	void set(int pos,int v){
		pos+=SIZE-1; 
		f[pos].first=v;f[pos].second=pos-SIZE+1;
		while(pos){
			pos=pos-1>>1;
			f[pos]=func(f[pos+pos+1],f[pos+pos+2]);
		}
	}
	pair<ll,ll> query(int l,int r,int l1=0,int r1=SIZE-1,int k=0){
		if(l<=l1&&r1<=r)return f[k];
		if(r<l1||r1<l)return make_pair(-1e18,-1e18);
		int mid=l1+r1>>1;
		pair<ll,ll>vl=query(l,r,l1,mid,k+k+1);
		pair<ll,ll>vr=query(l,r,mid+1,r1,k+k+2);
		return func(vl,vr);
	}
}Max;
#define maxn (int)5e5+10
//start to do something
int n,ans[maxn],nxt[maxn],from[maxn],q[maxn],deg[maxn];
vector<int>g[maxn],g2[maxn];
void solve(){
	n=getint();
	for(int i=1;i<=n;i++)from[i]=19260817,g[i].clear(),g2[i].clear();
	for(int i=1;i<=n;i++)nxt[i]=getint();
	for(int i=1;i<=n;i++)if(nxt[i]==-1)nxt[i]=i+1; 
	for(int i=1;i<=n;i++)Max.set(i,nxt[i]);
	for(int i=1;i<=n;i++){
		if(nxt[i]!=n+1&&from[nxt[i]]>1e6){
			from[nxt[i]]=i;
		}
		int _;if(nxt[i]-1>i)_=Max.query(i+1,nxt[i]-1).second,g[i].push_back(_),g2[_].push_back(i);
	}
	for(int i=1;i<=n;i++)if(from[i]<1e6)g[i].push_back(from[i]),g2[from[i]].push_back(i);
	int b=0,e=0;
	for(int i=1;i<=n;i++)deg[i]=g[i].size();
	for(int i=1;i<=n;i++)if(!deg[i])q[e++]=i;
	int cnt=0;
	while(b!=e){
		int x=q[b++];ans[x]=++cnt;
		for(auto to:g2[x]){
			if(deg[to]){
				deg[to]--;if(!deg[to])q[e++]=to;
			}
		}
	}
	if(e!=n)return (void)putstr("-1\n");
	for(int i=1;i<n;i++)putint(ans[i]);putln(ans[n]);
}
int main(){
	int t=getint();
	while(t--)solve();
	clear();
	return 0;
}