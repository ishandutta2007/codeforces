/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int T,n,a[505],b[505];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		multiset<pair<int,int> >s1,s2;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<n;i++){
			s1.insert(make_pair(min(a[i],a[i+1]),max(a[i],a[i+1])));
			s2.insert(make_pair(min(b[i],b[i+1]),max(b[i],b[i+1])));
		}
		if(s1!=s2){
			cout<<"NO"<<endl;
			continue;
		}
		if(a[1]!=b[1]||a[n]!=b[n]){
			cout<<"NO"<<endl;
			continue;
		}
		vector<pair<int,int> >opr;
		for(int i=2;i<=n;i++){
			int j=i;while(a[j]!=b[i]||(a[j+1]!=a[i-1]&&a[j-1]!=a[i-1]))j++;
			if(j==i)continue;
//			cerr<<i<<" "<<j<<endl;
//			for(int j=1;j<=n;j++)cerr<<a[j]<<" ";cerr<<endl;
			if(a[j+1]==a[i-1]){
				opr.push_back(make_pair(i-1,j+1));
				reverse(a+i-1,a+j+2);
			}else if(a[j-1]==a[i-1]){
				bool hv=0;
				for(int t=j;t<=n;t++){
					for(int prv=j-1;prv>=i;prv--)if(a[t]==a[prv]){
						opr.push_back(make_pair(prv,t));
						reverse(a+prv,a+t+1);
						hv=1;break;
					}
					if(hv)break; 
				}
//				assert(hv);
				j=i;
				while(a[j]!=b[i]||a[j+1]!=a[i-1])j++;
				opr.push_back(make_pair(i-1,j+1));
				reverse(a+i-1,a+j+2);
			}
		}
		cout<<"YES"<<endl;
		cout<<opr.size()<<endl;
		for(auto p:opr)cout<<p.first<<" "<<p.second<<endl;
	}
	return 0;
}