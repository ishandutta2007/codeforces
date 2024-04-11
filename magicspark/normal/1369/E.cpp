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
int n,m;
int w[200005];
vector<pair<int,int> >g[200005];
bool used[200005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i));
		w[x]--;w[y]--;
	}
	queue<int>q;
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(w[i]>=0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto p:g[x]){
			int to=p.first,id=p.second;
			if(!used[id])ans.push_back(id),used[id]=1;
			if(w[to]>=0){
				continue;
			}
			w[to]++;
			if(w[to]>=0){
				q.push(to);
			}
		}
	}
	if(ans.size()<m){
		puts("DEAD");
	}else{
		puts("ALIVE");
		reverse(ans.begin(),ans.end());
		for(auto x:ans)cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}