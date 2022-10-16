/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
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
int n,a[200005],nxt[200005],to[200005];
int f[200005],fl[200005],fr[200005];
int nxt1[200005],nxt2[200005],prv1[200005],prv2[200005];
void add(int x,int y){
	while(x<=n){
		f[x]=min(f[x],y);
		x+=x&-x;
	}
}
int query(int x){
	int ret=inf;
	while(x){
		ret=min(ret,f[x]);
		x-=x&-x;
	}
	return ret;
} 
void get_nxt(){
	memset(f,inf,sizeof f);
	for(int i=n;i>=1;i--){
		nxt[i]=query(a[i]-1);
		add(a[i],i);
	}
}
int dat[20][200005],lg[200005];
int rmq(int l,int r){
	int lvl=lg[r-l+1];
	return min(dat[lvl][l],dat[lvl][r-(1<<lvl)+1]);
}
void run(){
	get_nxt();
	memcpy(to,nxt,sizeof to);
	memcpy(nxt1,nxt,sizeof nxt1);
	for(int i=1;i<=n;i++)a[i]=n+1-a[i];
	get_nxt();
	for(int i=1;i<=n;i++)a[i]=n+1-a[i];
	memcpy(nxt2,nxt,sizeof nxt2);
	for(int i=1;i<=n;i++)to[i]=max(to[i],nxt[i]);
	for(int i=1;i<=n;i++)dat[0][i]=to[i];
	for(int i=1;i<20;i++)for(int j=1;j+(1<<i-1)<=n;j++)dat[i][j]=min(dat[i-1][j],dat[i-1][j+(1<<i-1)]);
//	for(int i=1;i<=n;i++)cerr<<i<<" "<<to[i]<<endl;
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(r-l>1){
			int mid=(l+r)/2;
			if(rmq(mid,i)<=i)l=mid;
			else r=mid;
		}
		fl[i]=r;
//		cerr<<i<<" "<<r<<" "<<rmq(r,i)<<" "<<rmq(r-1,i)<<endl;
	}
}
int pos[200005];
int main(){
	lg[1]=0;
	for(int i=2;i<=2e5;i++)lg[i]=lg[i/2]+1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	reverse(a+1,a+n+1);
	run();
	for(int i=1;i<=n;i++)prv1[i]=n-nxt1[n-i+1]+1;
	for(int i=1;i<=n;i++)prv2[i]=n-nxt2[n-i+1]+1;
	for(int i=1;i<=n;i++)fr[i]=n-fl[n-i+1]+1;
	reverse(a+1,a+n+1);
	run();
	for(int i=1;i<n;i++){
		bool can=0;
		for(int o1=0;o1<2;o1++){
			for(int o2=0;o2<2;o2++){
				pair<int,int>p1,p2;
				//dec,inc
				if(o1==0){
					p1=make_pair(a[i],prv1[i]>=fl[i]?a[prv1[i]]:-inf);
				}else{
					p1=make_pair(prv2[i]>=fl[i]?a[prv2[i]]:inf,a[i]);
				}
				if(o2==0){
					p2=make_pair(a[i+1],nxt2[i+1]<=fr[i+1]?a[nxt2[i+1]]:inf);
				}else{
					p2=make_pair(nxt1[i+1]<=fr[i+1]?a[nxt1[i+1]]:-inf,a[i+1]);
				}
				if(p1.first>=p2.first&&p1.second<=p2.second)can=1;
			}
		}
		cerr<<i<<" "<<can<<" "<<fl[i]<<" "<<fr[i+1]<<endl;
		if(can)pos[fl[i]]=max(pos[fl[i]],fr[i+1]);
	}
	for(int i=2;i<=n;i++)pos[i]=max(pos[i],pos[i-1]);
	ll fans=0;
	for(int i=1;i<=n;i++)fans+=(pos[i]-i+1);
	cout<<fans<<endl;
	return 0;
}