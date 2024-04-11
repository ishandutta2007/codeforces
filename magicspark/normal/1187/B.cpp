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
int n,m;
int cntt[26];
int cnts[200005][26];
string s,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>s>>m;
	for(int i=0;i<n;i++){
		if(i)memcpy(cnts[i],cnts[i-1],sizeof cnts[i-1]);
		cnts[i][s[i]-'a']++;
	}
	while(m--){
		cin>>t;
		memset(cntt,0,sizeof cntt);
		for(char c:t)cntt[c-'a']++;
		int l=-1,r=s.size();
		while(r-l>1){
			int mid=l+r>>1;
			bool ok=true;
			for(int i=0;i<26;i++){
				if(cnts[mid][i]<cntt[i]){
					ok=false;
				}
			}
			if(ok)r=mid;
			else l=mid;
		}
		cout<<r+1<<endl;
	}
	return 0;
}