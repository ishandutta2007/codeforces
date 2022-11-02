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
int n,q;
int state[3][200005];
int c1,c2;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
void update(int x,int y){
	for(int i=1;i<=2;i++){
		for(int j=max(1,y-1);j<=min(n,y+1);j++){
			if(make_pair(i,j)!=make_pair(x,y)){
				if(abs(x-i)+abs(y-j)==2){
					//c1
					if(1==state[i][j]){
						if(state[x][y]==1)c1--;
						else c1++;
					}
				}else if(y==j){
					if(1==state[i][j]){
						if(state[x][y]==1)c2--;
						else c2++;
					}
				}
			}
		}
	}
	state[x][y]=1-state[x][y];
}
int main(){
	cin>>n>>q;
	while(q--){
		int x,y;cin>>x>>y;
		update(x,y);
//		cerr<<c1<<" "<<c2<<endl;
		if(c1||c2){
			puts("No");
		}else{
			puts("Yes");
		}
	}
	return 0;
}