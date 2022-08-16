//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,m,k;
llo pre[2001];
llo pre2[2001];
llo co[2001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	vector<pair<llo,pair<llo,llo>>> ss2;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		ss2.pb({aa+bb,{aa,bb}});
	}
	sort(ss2.begin(),ss2.end());
	vector<pair<llo,llo>> ss;
	for(auto j:ss2){
		ss.pb(j.b);
	}
	for(llo i=0;i<m;i++){
		for(llo j=ss[i].a;j<=ss[i].b;j++){
			co[j]++;
		}
		llo ma=0;
		llo su=0;
		for(llo j=0;j<n;j++){
			su+=co[j];
			if(j>=k){
				su-=co[j-k];
			}
			ma=max(ma,su);
		}
		pre[i]=ma;
	}
	for(llo i=0;i<n;i++){
		co[i]=0;
	}
	for(llo i=m-1;i>=0;i--){
		for(llo j=ss[i].a;j<=ss[i].b;j++){
			co[j]++;
		}
		llo ma=0;
		llo su=0;
		for(llo j=0;j<n;j++){
			su+=co[j];
			if(j>=k){
				su-=co[j-k];
			}
			ma=max(ma,su);
		}
		pre2[i]=ma;
	}

	llo ans=pre[m-1];
	for(llo i=0;i<m-1;i++){
		ans=max(ans,pre[i]+pre2[i+1]);
	}
	cout<<ans<<endl;





 
	return 0;
}