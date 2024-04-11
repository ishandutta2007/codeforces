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
int T,n,m;
string s[105];
int a[105][105];
vector<pair<int,int> >X,Y,Z;
void update(int a,int b,int c,int d,int e,int f){
	X.push_back(make_pair(a,b));
	Y.push_back(make_pair(c,d));
	Z.push_back(make_pair(e,f));
	::a[a][b]^=1;
	::a[c][d]^=1;
	::a[e][f]^=1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		X.clear();
		Y.clear();
		Z.clear();
		for(int i=1;i<=n;i++)cin>>s[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=s[i][j-1]-'0';
			}
		}
		for(int i=n;i>=3;i--){
			for(int j=1;j<=m;j++){
				if(a[i][j]){
					update(i,j,i-1,j,i-1,(j==1?j+1:j-1));
				}
			}
		}
		n=2;
		for(int i=m;i>=3;i--){
			for(int j=1;j<=n;j++){
				if(a[j][i]){
					update(j,i,1,i-1,2,i-1);
				}
			}
		}
		m=2;
		for(int x=0;x<2;x++){
			for(int y=0;y<2;y++){
				for(int z=0;z<2;z++){
					for(int w=0;w<2;w++){
						if(x^y^z^a[1][1])continue;
						if(x^y^w^a[1][2])continue;
						if(x^z^w^a[2][1])continue;
						if(y^z^w^a[2][2])continue;
						if(w)update(1,2,2,1,2,2);
						if(z)update(1,1,2,1,2,2);
						if(y)update(1,1,1,2,2,2);
						if(x)update(1,1,1,2,2,1);
						break;
					}
				}
			}
		}
		cout<<X.size()<<endl;
		for(int i=0;i<X.size();i++){
			cout<<X[i].first<<" "<<X[i].second<<" "<<Y[i].first<<" "<<Y[i].second<<" "<<Z[i].first<<" "<<Z[i].second<<endl;
		}
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				assert(!a[i][j]);
			}
		} 
	}
	return 0;
}