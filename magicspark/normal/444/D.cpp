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
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
map<pair<string,string>,int>ans;
map<string,set<int> >occur;
pair<string,string>qry[100005];
string s;int q;
int solve(string s1,string s2){
	int len1=s1.size(),len2=s2.size();
	if(!occur.count(s1)||!occur.count(s2))return -1;
	set<int>&v1=occur[s1];
	set<int>&v2=occur[s2];
	int best=inf;
	for(auto x:v1){
		auto pos=v2.lower_bound(x);
		if(pos!=v2.end())best=min(best,max(x+len1,*pos+len2)-min(*pos,x));
		if(pos==v2.begin())continue;
		pos--;best=min(best,max(x+len1,*pos+len2)-min(*pos,x));
	}
	return best==inf?-1:best;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<4&&i+j<s.size();j++){
			occur[getstr(s,i,i+j)].insert(i);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>qry[i].first>>qry[i].second;
		if(occur[qry[i].first].size()>occur[qry[i].second].size())swap(qry[i].first,qry[i].second);
		ans[qry[i]];
	}
	for(auto &p:ans)p.second=solve(p.first.first,p.first.second);
	for(int i=1;i<=q;i++){
		cout<<ans[qry[i]]<<endl;
	}
	return 0;
}