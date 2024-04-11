/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define int long long
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
inline int Rand(){return rand()*32768+rand();}
int n,a[200005],b[200005],q,c[200005],lvl[200005],sum1[200005],sum2[200005],ans[200005],cnt[200005];
vector<pair<int,int> >qry[200005];
pair<int,int>arr[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].second>>arr[i].first;
		arr[i].first=-arr[i].first;
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		a[i]=arr[i].second;
		b[i]=arr[i].first;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j))lvl[i]=j;
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)cin>>c[i];
	for(int i=30;i>=0;i--){
		memset(sum1,0,sizeof sum1);
		memset(sum2,0,sizeof sum2);
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=n;j++){
			sum1[j]=sum1[j-1];
			sum2[j]=sum2[j-1];
			cnt[j]=cnt[j-1];
			if(lvl[j]<=i)sum1[j]+=a[j];
			if(lvl[j]<i)sum2[j]+=a[j];
			if(lvl[j]==i)cnt[j]++;
		}
		sum1[n+1]=1e18;
		for(int j=1;j<=n;j++)qry[j].clear();
		for(int j=1;j<=q;j++){
			int pos=lower_bound(sum1+1,sum1+n+1,c[j]+1)-sum1-1;
			ans[j]+=cnt[pos];c[j]-=sum1[pos]-sum2[pos];
			qry[pos+1].push_back(make_pair(c[j],j));
		}
		priority_queue<pair<int,int>  >q;
		for(int j=1;j<=n;j++){
			for(auto p:qry[j])q.push(p);
			if(lvl[j]==i){
				while(!q.empty()&&q.top().first>=sum2[j]+a[j]){
					int x=q.top().second;
					ans[x]++;c[x]-=a[j];
					q.pop();
				}
			}
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<" ";
	return 0;
}