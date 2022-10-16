/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
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
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,v,tmp;
string ans="";
int anscnt=inf;
inline void upd(string t){
	int cnt=0;
	for(int i=0;i<(int)t.size()-1;i++){
		if(t[i]==t[i+1])cnt++;
	}
	if(cnt<anscnt){
		anscnt=cnt;
		ans=t;
	}
}
inline void f(int x){
	int step=0;tmp=v;int TMP=x;
	while(x>1||v>1){
		if(x<1||v<1){
			v=tmp;return;
		}
		step++;
		if(x>v)x-=v;
		else v-=x;
	}
	step++;
	if(step==n){
		string now="";
		v=tmp;x=TMP;
		while(x>1||v>1){
			now.push_back(x>v?'B':'T');
			if(x>v)x-=v;
			else v-=x;
		}
		now.push_back('T');
		reverse(now.begin(),now.end());
		upd(now);
		for(char &c:now)if(c=='T')c='B';else c='T';
		now[0]='T';
		upd(now);
	}v=tmp;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n>>v; 
	if(n==1&&v==1){
		cout<<0<<endl;
		cout<<"T"<<endl;
		return 0;
	}
	if(n==1){
		puts("IMPOSSIBLE");
		return 0;
	}
	for(int i=1;i<v;i++){
		f(i);
	}
	if(ans==""){
		puts("IMPOSSIBLE");
		return 0;
	}
	cout<<anscnt<<endl;
	cout<<ans<<endl;
	return 0;
}