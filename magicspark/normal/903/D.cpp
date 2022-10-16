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
#pragma comment(" -Wl,--stack=1024000000")
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
int n;
int a[200005];
ll ans=0;
map<int,vector<int> >pos; 
unsigned long long add,sub;
void solve(vector<int>&v1,vector<int>&v2){
	int pos=0;
	for(int i=0;i<v1.size();i++){
		while(pos<v2.size()&&v2[pos]<v1[i])pos++;
		//[0,pos] [pos+1,v2.size()-1]
//		cerr<<i<<" "<<pos<<endl;
		add+=(pos);
		sub+=(v2.size()-pos);
		unsigned long long Min=min(add,sub);add-=Min;sub-=Min;
	}
}
int main(){
	cin>>n;
//	n=2e5;
//	for(int i=1;i<=1e5;i++)a[i]=1e9;for(int i=1e5+1;i<=2e5;i++)a[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if((ll)a[i]*(n-i-i+1)>0)sub+=(ll)a[i]*(n-i-i+1);
		else add-=(ll)a[i]*(n-i-i+1);
		unsigned long long Min=min(add,sub);add-=Min;sub-=Min;
		pos[a[i]].push_back(i);
	}
	for(map<int,vector<int> >::iterator itr=pos.begin(),itr2=itr;itr!=pos.end();itr++,itr2++){
		if(itr==pos.begin())itr++;
		if(itr==pos.end())break;
		if(itr2->first==itr->first-1){
			solve(itr2->second,itr->second);
		}
	}
	unsigned long long Min=min(add,sub);add-=Min,sub-=Min;
	if(sub){
		cout<<"-"<<sub<<endl;
	}else{
		cout<<add<<endl;
	}
	return 0;
}