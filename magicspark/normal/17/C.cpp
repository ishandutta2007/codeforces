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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=51123987;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,mx;
string s;
int dp[155][52][52][52];
inline void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
void init(string &s){
	string t="";
	for(int i=0;i<s.size();i++){
		if(t.size()==0||s[i]!=t[(int)t.size()-1]){
			t+=s[i];
		}
	}
	s=t;
}
int nxt[155][3];
int main(){
	cin>>n;mx=(n+2)/3;
	cin>>s;init(s);int nn=s.size();s=" "+s;
	for(int i=0;i<=nn;i++){
		for(int j=0;j<3;j++){
			nxt[i][j]=nn+1;
			for(int x=i;x<=nn;x++){
				if(s[x]=='a'+j){
					nxt[i][j]=x;
					break;
				}
			}
		}
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<=nn;i++){
		for(int a=0;a<=mx;a++){
			for(int b=0;b<=mx;b++){
				for(int c=0;c<=mx&&a+b+c<=n;c++){
					if(nxt[i][0]!=nn+1)add(dp[nxt[i][0]][a+1][b][c],dp[i][a][b][c]);
					if(nxt[i][1]!=nn+1)add(dp[nxt[i][1]][a][b+1][c],dp[i][a][b][c]);
					if(nxt[i][2]!=nn+1)add(dp[nxt[i][2]][a][b][c+1],dp[i][a][b][c]);
				}
			}
		}
	}
	int ans=0;
	for(int l=1;l<=nn+1;l++)
	for(int a=0;a<=mx;a++){
		for(int b=0;b<=mx;b++){
			int c=n-a-b;
			if(c>=0&&c<=51&&abs(a-b)<=1&&abs(b-c)<=1&&abs(a-c)<=1){
				add(ans,dp[l][a][b][c]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}