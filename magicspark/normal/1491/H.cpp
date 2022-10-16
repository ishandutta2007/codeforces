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
const int b=330;
int n,q,tot;
int a[100005],bel[100005];
int l[444],r[444];
ll cnt[444],tag[444];
int nxt[333][b+5];
void pushdown(int x){
	for(int i=l[x];i<=r[x];i++){
		a[i]=max(1ll,a[i]-tag[x]);
	}
	tag[x]=0;
}
void rebuild(int x){
	assert(tag[x]==0);
	for(int i=l[x];i<=r[x];i++){
		if(i==1)nxt[x][i-l[x]]=1;
		else nxt[x][i-l[x]]=(a[i]<l[x]?a[i]:nxt[x][a[i]-l[x]]);
		if(x!=1&&bel[nxt[x][i-l[x]]]>=x)assert(0);
	}
}
int get_lca(int x,int y){
	for(int i=tot;i>=1;i--){
		if(bel[x]==i&&bel[y]==i){
			int nx=cnt[i]>=400?max(a[x]-tag[i],1ll):nxt[i][x-l[i]];
			int ny=cnt[i]>=400?max(a[y]-tag[i],1ll):nxt[i][y-l[i]];
			if(nx==ny){
				while(x!=y){
					if(x>y)swap(x,y);
					y=max(a[y]-tag[bel[y]],1ll);
				}
				return x;
			}else{
				x=nx;y=ny;
				assert(i==1||(bel[x]<i&&bel[y]<i));
			}
		}else if(bel[x]==i){
			if(cnt[i]>=400)x=max(a[x]-tag[i],1ll);
			else x=nxt[i][x-l[i]];
			assert(i==1||bel[x]<i);
		}else if(bel[y]==i){
			if(cnt[i]>=400)y=max(a[y]-tag[i],1ll);
			else y=nxt[i][y-l[i]];
			assert(i==1||bel[y]<i);
		}
	}
	return 1;
	assert(0);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	memset(l,inf,sizeof l);
	memset(r,0,sizeof r);
	for(int i=1;i<=n;i++){
		if(i==1)a[i]=1;else cin>>a[i];
		bel[i]=(i-1)/b+1;
		l[bel[i]]=min(l[bel[i]],i);
		r[bel[i]]=max(r[bel[i]],i);
		tot=max(tot,bel[i]);
	}
	for(int i=1;i<=tot;i++)rebuild(i);
	while(q--){
		int t;cin>>t;
		if(t==1){
			int l,r,x;cin>>l>>r>>x;
			int cmp=bel[l];
			pushdown(cmp);
			while(l<=r&&bel[l]==cmp)a[l]=max(1,a[l]-x),l++;
			rebuild(cmp);
			cmp=bel[r];
			pushdown(cmp);
			while(r>=l&&bel[r]==cmp)a[r]=max(1,a[r]-x),r--;
			rebuild(cmp);
			if(l>r)continue;
			for(int i=bel[l];i<=bel[r];i++){
				if(cnt[i]>=400){
					tag[i]+=x;
					continue;
				}else{
					pushdown(i);
					for(int j=::l[i];j<=::r[i];j++)a[j]=max(1,a[j]-x);
					rebuild(i);cnt[i]+=x;
				}
			}
		}else{
			int x,y;cin>>x>>y;
			cout<<get_lca(x,y)<<endl;
		}
	}
	return 0;
}