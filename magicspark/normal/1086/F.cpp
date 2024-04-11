/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wit1her into the truth.
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
const int mod=998244353;
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
int n,t;
int x[2005],y[2005];
int f0(int x){return x+1;}
int f1(int x){return 1ll*x*(x+1)/2%mod;}
int f2(int x){return 1ll*x*(x+1)%mod*(2*x+1)%mod*166374059%mod;}
int calc(int x,int y){
	if(x<0||y<0)return 0;
	int k=min(x,y)/2;
	return (1ll*x*y%mod*(t+1-f0(k)+mod)%mod*(mod-1)%mod+2ll*(x+y)*f1(k)%mod*(mod-1)%mod+4ll*f2(k))%mod;
}
vector<pair<int,int> >vx,vy;
int get(int a,int b,int c,int d,int len){
	a=vx[a].second;b=vx[b].second;c=vy[c].second;d=vy[d].second;
	return len&1?mod-calc(x[a]-x[b]+t+t+1,y[c]-y[d]+t+t+1):calc(x[a]-x[b]+t+t+1,y[c]-y[d]+t+t+1);
}
int posx[2005],posy[2005];
void run(){
	cin>>n>>t;
	vx.clear();vy.clear();
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		vx.push_back(make_pair(x[i],i));
		vy.push_back(make_pair(y[i],i));
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	for(int i=0;i<n;i++){
		posx[vx[i].second]=i;
		posy[vy[i].second]=i;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		set<int>hv;
		for(int j=i;j<n;j++){
			hv.insert(posy[vx[j].second]);
			auto it1=hv.find(posy[vx[j].second]);
			auto it2=hv.find(posy[vx[i].second]);
			if(it1==it2)(ans+=get(i,i,*it1,*it1,1))%=mod;
			else{
				if(*it1>*it2)swap(it1,it2);
				if(it2!=next(it1))continue;
				ans=(ans+get(i,j,*it1,*it2,2))%mod;
				if(it1!=hv.begin())ans=(ans+get(i,j,*prev(it1),*it2,3))%mod;
				if(next(it2)!=hv.end())ans=(ans+get(i,j,*it1,*next(it2),3))%mod;
				if(it1!=hv.begin()&&next(it2)!=hv.end())ans=(ans+get(i,j,*prev(it1),*next(it2),4))%mod;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T=1;while(T--)run();
	return 0;
}