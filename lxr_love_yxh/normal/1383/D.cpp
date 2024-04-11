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
int n,m,x,y;
int a[255][255],ans[255][255];
int main(){
	cin>>n>>m;
	set<int>r,c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=1;j<=m;j++){
			mx=max(mx,a[i][j]);
		}
		r.insert(mx);
	}
	for(int j=1;j<=m;j++){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i][j]);
		}
		c.insert(mx);
	}
	int x=0,y=0;
	r.insert(-inf);c.insert(-inf);
	memset(ans,-1,sizeof ans);
	set<int>hv;
	for(int i=1;i<=n*m;i++)hv.insert(i);
	for(auto v:r)hv.erase(v);for(auto v:c)hv.erase(v);
	vector<pair<int,int> >vec;
	while(x+y!=n+m){
		int vr=*r.rbegin(),vc=*c.rbegin();
		if(vr==vc){
			x++;y++;
			ans[x][y]=vr;
			vec.push_back(make_pair(x,y));
			r.erase(vr);
			c.erase(vc);
		}else if(vr>vc){
			x++;ans[x][y]=vr;
			vec.push_back(make_pair(x,y));
			r.erase(vr);
		}else{
			y++;ans[x][y]=vc;
			vec.push_back(make_pair(x,y));
			c.erase(vc);
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(auto p:vec){
		int x=p.first,y=p.second;
		cerr<<x<<" "<<y<<endl;
		if(ans[x-1][y]!=-1){
			//first up
			for(int j=x-1;j>=1;j--)if(ans[j][y]==-1){
				int v=*hv.rbegin();
				ans[j][y]=v;hv.erase(v);
			}
			for(int j=y-1;j>=1;j--)if(ans[x][j]==-1){
				int v=*hv.rbegin();
				ans[x][j]=v;hv.erase(v);
			}
		}else{
			//first left
			for(int j=y-1;j>=1;j--)if(ans[x][j]==-1){
				int v=*hv.rbegin();
				ans[x][j]=v;hv.erase(v);
			}
			for(int j=x-1;j>=1;j--)if(ans[j][y]==-1){
				int v=*hv.rbegin();
				ans[j][y]=v;hv.erase(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}