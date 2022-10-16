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
string s;
int dif[2000005];
int least[11][11][22];
int solve(int x,int y){
	if(x==0&&y==0){
		for(char c:s)if(c!='0')return -1;
		return 0;
	}
	for(int i=1;i<s.size();i++){
		if(least[x][y][dif[i]]==inf)return -1;
	}
	int ret=0;
	for(int i=1;i<s.size();i++){
		ret+=least[x][y][dif[i]]-1; 
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	memset(least,inf,sizeof least);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int x=0;x<=100;x++){
				for(int y=0;y<=100;y++){
					if(x||y)least[i][j][(i*x+j*y)%10]=min(least[i][j][(i*x+j*y)%10],x+y);
				}
			}
		}
	}
	for(int i=1;i<s.size();i++)dif[i]=(s[i]-s[i-1]+10)%10;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d%c",solve(i,j),j==9?'\n':' ');
		}
	}
	return 0;
}