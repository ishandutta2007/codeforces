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
int T,n,x,y,van;
int a[100005],ans[100005],cnt[100005];
vector<int>pos[100005];
int main(){
	cin>>T;int tot=0;
	while(T--){
		cin>>n>>x>>y;y-=x;tot++;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n+1;i++)pos[i].clear(),ans[i]=0;
		priority_queue<pair<int,int> >q;
		for(int i=1;i<=n;i++){
			pos[a[i]].push_back(i);
		}
		for(int i=1;i<=n+1;i++){
			if(!pos[i].size())van=i;
			q.push(make_pair(pos[i].size(),i));
		}
		while(x--){
			int id=q.top().second;q.pop();
			cerr<<"type1: "<<pos[id].back()<<endl;
			ans[pos[id].back()]=a[pos[id].back()];
			pos[id].pop_back();
			q.push(make_pair(pos[id].size(),id));
		}
		int mx=0,sum=0;
		for(int i=1;i<=n+1;i++){
			mx=max(mx,(int)pos[i].size());
			sum+=pos[i].size();
		}
		if(y>(sum-mx)*2){
			puts("NO");
		}else{
			puts("YES");
			while(y>3){
				int a=q.top().second;q.pop();
				int b=q.top().second;q.pop();
				int pa=pos[a].back(),pb=pos[b].back();
				ans[pa]=::a[pb];ans[pb]=::a[pa];
//				cerr<<pa<<" "<<pb<<endl;
				y-=2;sum-=2;
				pos[a].pop_back();
				pos[b].pop_back();
				q.push(make_pair(pos[a].size(),a));
				q.push(make_pair(pos[b].size(),b));
			}
			vector<int>vec;
			for(int i=1;i<=n+1;i++){
				if(pos[i].size()){
//					cerr<<i<<" "<<pos[i].back()<<endl;
					vec.push_back(pos[i].back());
					pos[i].pop_back();
				}
			}
			if(vec.size()<y){
			for(int i=1;i<=n+1;i++){
				if(pos[i].size()){
//					cerr<<i<<" "<<pos[i].back()<<endl;
					vec.push_back(pos[i].back());
					pos[i].pop_back();
				}
			}
			}
			for(int i=0;i<y;i++){
//				cerr<<i<<" "<<vec[i]<<" "<<vec[(i+1)%y]<<endl;
				ans[vec[i]]=a[vec[(i+1)%(int)vec.size()]];
			}
			for(int i=1;i<=n;i++)if(ans[i]==0)ans[i]=van;
			for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}