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
string s; 
vector<pair<char,int> >vec;
bool used[300005];
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(used[i])continue;
		int cnt=0;
		for(int j=i;;j++){
			if(s[i]==s[j])cnt++;
			else break;
			used[j]=1;
		}
		vec.push_back(make_pair(s[i],cnt));
	}
	#ifdef LOCAL
		for(int i=0;i<vec.size();i++)cerr<<vec[i].first<<" "<<vec[i].second<<endl;
	#endif
	if(vec.size()%2==0){
		puts("0");
	}else{
		int mid=(int)vec.size()/2;
		if(vec[mid].second+1<3){
			puts("0");
		}else{
			for(int i=0;i<mid;i++){
				int to=vec.size()-i-1;
				if(vec[i].first!=vec[to].first||vec[i].second+vec[to].second<3){
					puts("0");
					return 0;
				}
			}
			cout<<vec[mid].second+1<<endl;
		}
	}
	return 0;
}