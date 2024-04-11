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
int n,k,t;
string s;
int c[55];
int d[55][55],nxt[200005][26];
ll cost[1<<22],del[1<<22],lg[1<<22];
int main(){
	cin>>n>>k>>t>>s;
	lg[1]=0;
	for(int i=2;i<(1<<k);i++)lg[i]=lg[i/2]+1;
	for(int i=0;i<k;i++)cin>>c[i];
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			cin>>d[i][j];
		}
	}
	memset(nxt,-1,sizeof nxt);
	for(int i=n-2;i>=0;i--){
		memcpy(nxt[i],nxt[i+1],sizeof nxt[i]);
		nxt[i][s[i+1]-'A']=i+1;
	}
	for(int i=0;i<n;i++){
		vector<pair<int,char> >occ;
		for(int j=0;j<k;j++){
			if(nxt[i][j]!=-1){
				occ.push_back(make_pair(nxt[i][j],j));
			}
		}
		sort(occ.begin(),occ.end());
		int mask=0;
		for(auto p:occ){
			int pos=p.first,add=1<<p.second,val=d[s[i]-'A'][p.second];
			cost[mask]+=val;
			cost[mask|(1<<(s[i]-'A'))]-=val;
			cost[mask|add]-=val;
			cost[mask|(1<<(s[i]-'A'))|add]+=val;
			mask|=add;
		}
	}
	for(int i=0;i<k;i++){
		for(int mask=0;mask<(1<<k);mask++)if(mask&(1<<i)){
			cost[mask]+=cost[mask^(1<<i)];
		}
	}
	ll ans=0;
	for(int mask=1;mask<(1<<k);mask++){
		int van=mask&-mask;
		del[mask]=del[mask-van]+c[lg[van]];
	}
	int full=0;
	for(char c:s)full|=(1<<(c-'A'));
	for(int mask=0;mask<(1<<k);mask++){
		if((mask|full)==full)if(mask!=full){
//			cerr<<mask<<" "<<cost[mask]<<" "<<del[mask]<<endl;
			if(cost[mask]+del[mask]<=t)ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}