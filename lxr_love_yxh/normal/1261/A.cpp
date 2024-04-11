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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string tar,s;
int n,k,t;
char c[3333];
string read(){
	scanf("%s",c);
	return c;
}
void Swap(int l,int r){
	reverse(s.begin()+l,s.begin()+r+1);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		s=" "+read();
		tar=" ";
		for(int i=1;i<=k-1;i++)tar+="()";
		int tmp=n-(k-1)*2;
		for(int i=1;i<=tmp/2;i++)tar+="(";
		for(int i=1;i<=tmp/2;i++)tar+=")";
		vector<pair<int,int> >opr;opr.clear();
		for(int i=1;i<=n;i++){
			int nxt_dif=n+1;
			for(int j=i+1;j<=n;j++)if(s[j]!=s[i]){nxt_dif=j;break;}
			if(s[i]!=tar[i]){
				if(s[i]=='('){
					int pos=nxt_dif;
					opr.push_back(make_pair(i,pos));
					Swap(i,pos);
				}else{
					int pos=nxt_dif;
					opr.push_back(make_pair(i,pos));
					Swap(i,pos);
				}
			}
		}
		cout<<opr.size()<<endl;
		for(int i=0;i<opr.size();i++){
			cout<<min(opr[i].first,opr[i].second)<<" "<<max(opr[i].first,opr[i].second)<<endl;
		}
	}
	return 0;
}