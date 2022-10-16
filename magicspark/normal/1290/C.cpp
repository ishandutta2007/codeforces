/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
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
int par[600005],sz0[600005],sz1[600005];
void init(){
	for(int i=0;i<600005;i++)par[i]=i;
	for(int i=0;i<300002;i++)sz0[i]=1;
	for(int i=300002;i<600005;i++)sz1[i]=1;
}
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
int n,k,ans=0;
string s;
vector<int>hv[300005];
int use[600005];
const int md=3e5+2;
void merge(int x,int y,bool dif){
	cerr<<"merge "<<x<<" "<<y<<" "<<dif<<endl;
	int xx,yy;
	if(dif){
		pair<int,int>tmp(inf,inf);
		xx=find(x);yy=find(y+3e5+2);
		if(xx==yy)return;
		if(xx==0||xx==3e5+2)swap(xx,yy);
		if(use[xx])ans-=sz1[xx];
		if(use[yy])ans-=sz1[yy];
		use[xx]=use[yy]=0;
		par[xx]=yy;sz1[yy]+=sz1[xx];sz0[yy]+=sz0[xx];
		if(yy!=3e5+2)tmp=min(tmp,make_pair(sz1[yy],yy));
		if(yy==0)tmp=min(tmp,make_pair(-inf,yy));
		xx=find(x+3e5+2);yy=find(y);
		if(xx==0||xx==3e5+2)swap(xx,yy);
		if(use[xx])ans-=sz1[xx];
		if(use[yy])ans-=sz1[yy];
		use[xx]=use[yy]=0;
		par[xx]=yy;sz1[yy]+=sz1[xx];sz0[yy]+=sz0[xx];
		if(yy!=3e5+2)tmp=min(tmp,make_pair(sz1[yy],yy));
		if(yy==0)tmp=min(tmp,make_pair(-inf,yy));
		ans+=sz1[tmp.second];use[tmp.second]=1;
	}else{
		pair<int,int>tmp(inf,inf);
		xx=find(x);yy=find(y);
		if(xx==yy)return;
		if(xx==0||xx==3e5+2)swap(xx,yy);
		if(use[xx])ans-=sz1[xx];
		if(use[yy])ans-=sz1[yy];
		use[xx]=0;use[yy]=0;
		par[xx]=yy;sz1[yy]+=sz1[xx];sz0[yy]+=sz0[xx];
		if(yy!=3e5+2)tmp=min(tmp,make_pair(sz1[yy],yy));
		if(yy==0)tmp=min(tmp,make_pair(-inf,yy));
		xx=find(x+3e5+2);yy=find(y+3e5+2);
		if(xx==0||xx==3e5+2)swap(xx,yy);
		if(use[xx])ans-=sz1[xx];
		if(use[yy])ans-=sz1[yy];
		use[xx]=0;use[yy]=0;
		par[xx]=yy;sz1[yy]+=sz1[xx];sz0[yy]+=sz0[xx];
		if(yy!=3e5+2)tmp=min(tmp,make_pair(sz1[yy],yy));
		if(yy==0)tmp=min(tmp,make_pair(-inf,yy));
		ans+=sz1[tmp.second];use[tmp.second]=1;
	}
	if(use[md]||use[0]==0){
		cout<<"error"<<endl;
		exit(0);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	cin>>s;s=" "+s;
	init();
	for(int i=0;i<=3e5;i++)use[i]=1;
	for(int i=1;i<=k;i++){
		int t;cin>>t;
		while(t--){
			int x;cin>>x;
			hv[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(hv[i].size()==1){
			merge(hv[i][0],0,s[i]=='0');
		}
		if(hv[i].size()==2){
			merge(hv[i][0],hv[i][1],s[i]=='0');
		}
		cout<<ans<<endl;
	}
	return 0;
}