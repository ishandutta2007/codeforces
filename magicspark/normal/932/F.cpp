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
int n;
int a[100005],b[100005],ans[100005];
vector<int>g[100005];
set<pair<int,int> >s[100005];
double func(pair<int,int>p1,pair<int,int>p2){
	return 1.0*(p2.second-p1.second)/(p1.first-p2.first);
}
void Insert(set<pair<int,int> >&s,pair<int,int>v){
	auto itr=s.lower_bound(make_pair(v.first,-1e18));
	if(itr!=s.end()&&itr->first==v.first){
		if(v.second<itr->second){
			s.erase(itr);
		}else return;
	}
	itr=s.lower_bound(make_pair(v.first,-1e18));
	if(itr!=s.end()){
		auto it=itr;it++;
		while(it!=s.end()){
			auto p1=*it,p2=*itr;
			if(func(p1,p2)>func(p1,v)){
				s.erase(itr++);it++;
			}else break;
		}
	}
	itr=s.lower_bound(make_pair(v.first,-1e18));
	if(itr!=s.begin()){
		itr--;
		auto it=itr;
		while(it!=s.begin()){
			it--;
			auto p2=*it,p1=*itr;
			if(func(v,p2)<func(v,p1)){
				s.erase(itr--);it=itr;
			}else break;
		}
	}
	itr=s.lower_bound(v);
	if(itr!=s.end()&&itr!=s.begin()){
		auto it=itr;it--;
		if(func(*itr,*it)<func(*itr,v))return;
	}
	s.insert(v);
}
int eval(pair<int,int>f,int x){
	return f.first*x+f.second;
}
int query(set<pair<int,int> >&s,int v){
	if(!s.size())return 0;
	int l=s.begin()->first,r=s.rbegin()->first;
	while(r-l>1){
		int mid=(l+r)/2;
		auto itr=s.lower_bound(make_pair(mid,-1e18));
		if(itr==s.begin()){
			l=mid;
			continue;
		}
		if(next(itr)==s.end()){
			r=mid;
			continue;
		}
		auto it=next(itr);
		if(eval(*it,v)<eval(*itr,v))l=mid;
		else r=mid;
	}
	auto it1=s.lower_bound(make_pair(l,-1e18));
	auto it2=s.lower_bound(make_pair(r,-1e18));
//	cerr<<"query: "<<v<<" "<<l<<" "<<r<<endl;
//	cerr<<"show set"<<endl;
//	int ret=1e18;
//	double prv=1e18;
//	for(set<pair<int,int> >::iterator itr=s.begin();next(itr)!=s.end();itr++){
//		double tmp=func(*itr,*next(itr));
//		if(tmp>prv)assert(0);
//		prv=tmp;
//	}
//	for(auto p:s){
//		ret=min(ret,eval(p,v));
//		cerr<<p.first<<" "<<p.second<<endl;
//	}
//	return ret;
//	cerr<<"------"<<endl;
	return min(eval(*it1,v),eval(*it2,v));
}
void dfs(int x,int par){
	int pos=-1;
	for(auto to:g[x]){
		if(to!=par){
			dfs(to,x);
			if(pos==-1||s[pos].size()<s[to].size())pos=to;
		}
	}
	if(pos!=-1)s[x].swap(s[pos]);
	for(auto to:g[x]){
		if(to!=par&&to!=pos){
			for(auto p:s[to])Insert(s[x],p);
		}
	}
	ans[x]=query(s[x],a[x]);
	Insert(s[x],make_pair(b[x],ans[x]));
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
	return 0;
}