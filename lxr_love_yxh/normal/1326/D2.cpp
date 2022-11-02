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
int cnt, len, ans = 0;
#define N 1000005
char S[N],ss[N*2];
int p[N*2];
void init(){
    len = strlen(S); cnt = 1;
    ss[0]='#';
	for (int i=0;i<len;i++)ss[cnt++]=S[i],ss[cnt++]='#';
}
void manacher(){
    int mx=0,id=0;
	for (int i=0;i<cnt;i++){
		if (i<mx) p[i]=min(p[2*id-i],mx-i);
		else p[i]=0;
		while(i+p[i]+1<cnt && i-p[i]-1>=0 && ss[i+p[i]+1]==ss[i-p[i]-1])p[i]++;
		if (i+p[i]>mx){
			mx=i+p[i];
			id=i;
		}
	}
}
string solve(string s){
	if(s=="")return "";
	for(int i=0;i<s.size();i++)S[i]=s[i];S[s.size()]='\0';
	init();manacher();
	pair<int,int>best(-1,-1);
	for(int i=0;i<cnt;i++){
		if(i-p[i]<=0||i+p[i]>=cnt-1){
			best=max(best,make_pair(min(p[i],min(i,cnt-1-i)),i));
		}
	}
	if(best.first==-1)return "";
	string ret="";
	for(int i=best.second-p[best.second]+1;i<=best.second+p[best.second]-1;i++){
		if(ss[i]!='#')ret+=ss[i];
	}
	return ret;
}
int main(){
	int T;string s;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>s;int n=s.size();
		int pos=0;
		while(pos<=n-1-pos&&s[pos]==s[n-1-pos])pos++;pos--;
		if(pos>=n-1-pos){
			cout<<s<<endl;
			continue;
		}
		string ans=getstr(s,0,pos);
		ans+=solve(getstr(s,pos+1,n-1-pos-1));
		ans+=getstr(s,n-pos-1,n-1);
		cout<<ans<<endl;
	}
	return 0;
}