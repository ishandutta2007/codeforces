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
const int L=9,N=512;
struct Sparse {
	int a[L][N+5];
	Sparse() {}
	void init(const vector<int>& ar) {
		int n = ar.size();
		for (int i = 0; i < N; ++i) {
			a[0][i] = (i < n) ? ar[i] : 0;
		}
		for (int j = 1; j < L; ++j) {
			for (int i = 0; i + (1 << j) <= N; ++i) {
				a[j][i] = max(a[j - 1][i], a[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
	int query(int l, int r) {
		r++;const int b = 31 - __builtin_clz(r - l);
		return max(a[b][l], a[b][r - (1 << b)]);
	}
}r[505],c[505];
char buf[505];
string read(){
	scanf("%s",buf);return buf;
}
int n,m,q;
string s[505];
int ans[505][505];
int sum[505][505][4];
string pat="RGYB";
int get_sum(int r1,int c1,int r2,int c2,int col){
	return sum[r2][c2][col]-sum[r2][c1-1][col]-sum[r1-1][c2][col]+sum[r1-1][c1-1][col];
}
int solve(int x,int y){
	for(int ret=1;;ret++){
		bool ok=1;
		if(x-ret+1<1||y-ret+1<1||get_sum(x-ret+1,y-ret+1,x,y,0)!=ret*ret)ok=0;
		if(x-ret+1<1||y+ret>m||get_sum(x-ret+1,y+1,x,y+ret,1)!=ret*ret)ok=0;
		if(x+ret>n||y-ret+1<1||get_sum(x+1,y-ret+1,x+ret,y,2)!=ret*ret)ok=0;
		if(x+ret>n||y+ret>m||get_sum(x+1,y+1,x+ret,y+ret,3)!=ret*ret)ok=0;
		if(!ok)return ret-1;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)s[i]=" "+read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int c=0;c<4;c++)sum[i][j][c]=sum[i][j-1][c]+sum[i-1][j][c]-sum[i-1][j-1][c];
			sum[i][j][pat.find(s[i][j])]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=solve(i,j);
//			cerr<<i<<" "<<j<<" "<<ans[i][j]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		vector<int>vec(1,0);
		for(int j=1;j<=m;j++){
			vec.push_back(ans[i][j]);
		}
		r[i].init(vec);
	}
	for(int i=1;i<=m;i++){
		vector<int>vec(1,0);
		for(int j=1;j<=n;j++){
			vec.push_back(ans[j][i]);
		}
		c[i].init(vec);
	}
	while(q--){
		int r1,c1,r2,c2;scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		r2--;c2--;int now=1,ans=0,cur;
		while(1){
			if(r1>r2||c1>c2)break;cur=0;
			cur=max(cur,r[r1].query(c1,c2));
			cerr<<r[r1].query(c1,c2)<<endl;
			cur=max(cur,r[r2].query(c1,c2));
			cerr<<r[r2].query(c1,c2)<<endl;
			cur=max(cur,c[c1].query(r1,r2));
			cerr<<c[c1].query(r1,r2)<<endl;
			cur=max(cur,c[c2].query(r1,r2));
			cerr<<c[c2].query(r1,r2)<<endl;
			r1++;r2--;c1++;c2--;
			cur=min(cur,now++);
			ans=max(ans,cur);
		}
		printf("%d\n",ans*ans*4);
	}
	return 0;
}