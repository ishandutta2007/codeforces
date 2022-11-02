/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m,x,y,z,a,b;
int h[3005][3005];
int mn[3005][3005];//j col,start=i
int row[3005][3005];
deque<pair<int,int> >q;
void get_col(){
	for(int j=1;j<=m;j++){
		q.clear();
		for(int i=1;i<=n;i++){
			while(!q.empty()&&q.front().second<=i-a)q.pop_front();
			while(!q.empty()&&q.back().first>=h[i][j])q.pop_back();
			q.push_back(make_pair(h[i][j],i));
			mn[i][j]=q.front().first;
		}
	}
}
void get_row(){
	for(int i=1;i<=n;i++){
		q.clear();
		for(int j=1;j<=m;j++){
			while(!q.empty()&&q.front().second<=j-b)q.pop_front();
			while(!q.empty()&&q.back().first>=mn[i][j])q.pop_back();
			q.push_back(make_pair(mn[i][j],j));
			row[i][j]=q.front().first;
		}
	}
}
inline int func(int t){
	return (t*x+y)%z;
}
signed main(){
	cin>>n>>m>>a>>b;
	cin>>h[1][1]>>x>>y>>z;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i-1||j-1)h[i][j]=(j==1?func(h[i-1][m]):func(h[i][j-1]));
		}
	}
	get_col();
	get_row();
	int ans=0;
	for(int i=a;i<=n;i++){
		for(int j=b;j<=m;j++){
			ans+=row[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}