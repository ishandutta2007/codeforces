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
inline int Rand(){return rand()*32768+rand();}
int n,ans[200005],val[200005];
map<int,int>mp;
set<pair<int,int> >hv;
pair<int,int>find_range(int x,int cnt,int pos){
	int y,f;
	if(pos!=1){
		printf("? %d %d\n",max(1,pos-cnt),max(1,pos-1));
//		cout<<"? "<<max(1,pos-cnt)<<" "<<max(1,pos-1)<<endl;
		fflush(stdout);
		scanf("%d%d",&y,&f);
		if(y==x)return make_pair(pos-f,pos+cnt-f-1);
	}
	printf("? %d %d\n",pos,min(n,pos+cnt-1));
//	cout<<"? "<<pos<<" "<<min(n,pos+cnt-1)<<endl;
	fflush(stdout);
	scanf("%d%d",&y,&f);
	if(y!=x)assert(0);
	return make_pair(pos-cnt+f,pos+f-1);
}
void calc(int &l,int &r,set<pair<int,int> >&s,int go){
	auto itr=s.lower_bound(make_pair(go,-1));itr--;
	l=itr->second;r=next(itr)->second;
}
void solve(int l,int r){
//	cerr<<"show: "<<l<<" "<<r<<endl;
	if(l>r)return;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x,f;scanf("%d%d",&x,&f);
	int van=x,cnt=f;
	if(mp.find(x)!=mp.end()){
		pair<int,int>p=find_range(x,f,mp[x]);
//		cerr<<"set_v: "<<x<<" "<<p.first<<" "<<p.second<<endl;
		for(int i=p.first;i<=p.second;i++)ans[i]=x;
		solve(l,p.first-1);
		solve(p.second+1,r);
		return;
	}
	int lb,rb;
	calc(lb,rb,hv,van);
	lb=max(l-1,lb);rb=min(r+1,rb);
//	cerr<<"show: "<<lb<<" "<<rb<<endl;
	for(int i=lb+1;i<rb;i+=cnt){
		printf("? %d %d\n",i,i);
//		cout<<"? "<<i<<" "<<i<<endl;
		fflush(stdout);
		scanf("%d%d",&x,&f);val[i]=x;
		mp[x]=i;hv.insert(make_pair(x,i));
	}
	pair<int,int>p=find_range(van,cnt,mp[van]);
//	cerr<<"set_v: "<<p.first<<" "<<p.second<<" "<<van<<endl;
	for(int i=p.first;i<=p.second;i++)ans[i]=van;
	solve(l,p.first-1);
	solve(p.second+1,r);
}
int main(){
	hv.insert(make_pair(0,0));
	hv.insert(make_pair(inf,inf));
	scanf("%d",&n);
	solve(1,n);
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}