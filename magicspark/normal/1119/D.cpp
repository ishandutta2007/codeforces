//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,q;
int a[100005],ans[100005];
vector<pair<int,int> >dif;//dif,id
set<int>all;
pair<int,int>qry[100005];
int from[100005],to[100005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];all.insert(a[i]);
	}
	n=0;
	for(set<int>::iterator itr=all.begin();itr!=all.end();itr++){
		a[++n]=*itr;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int L,R;cin>>L>>R;
		qry[i]=make_pair(R-L+1,i);
	}
	sort(qry+1,qry+q+1);
	a[n+1]=8e18;
	for(int i=1;i<=n;i++){
		dif.push_back(make_pair(a[i+1]-a[i],i));
	}
	for(int i=1;i<=n;i++)to[i]=from[i]=i;
	sort(dif.begin(),dif.end());
	int pos=0,add=0,mul=n;
	for(int i=1;i<=q;i++){
		while(pos<dif.size()&&dif[pos].first<=qry[i].first){
			int now=dif[pos].second;
			add+=dif[pos].first;
			mul--;
			pos++;
		}
//		cerr<<qry[i].second<<" "<<mul<<" "<<add<<endl; 
		ans[qry[i].second]=mul*qry[i].first+add;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<" ";
	return 0;
}