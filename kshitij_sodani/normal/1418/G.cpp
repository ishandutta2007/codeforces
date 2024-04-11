//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n;
llo mod=1e9+7;
llo mod2=1e9+9;
mt19937 rng;
llo aa,bb;
vector<llo> pre[500001];
llo pre2[500001];
llo pre3[500001];
llo it[500001];
pair<llo,llo> ac[500001];
llo cot[500001];
llo cot2[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());

	cin>>n;
	aa=(rng()%(mod-2000000))+2000000;
	bb=(rng()%(mod2-2000000))+2000000;
	pre2[0]=1;
	pre3[0]=1;
	for(llo i=1;i<=n;i++){
		pre2[i]=(pre2[i-1]*aa)%mod;
		pre3[i]=(pre3[i-1]*bb)%mod2;
	}
	for(llo i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
		pre[it[i]].pb(i);
	}
	llo cur=0;
	llo cur2=0;
	map<pair<llo,llo>,llo> ss;
	ss[{cur,cur2}]++;
	ac[0]={cur,cur2};
	llo ind=0;
	llo ans=0;
	for(llo i=0;i<n;i++){

		cur=(cur-pre2[it[i]]*cot[it[i]]+3*mod)%mod;
		cur2=(cur2-pre3[it[i]]*cot[it[i]]+3*mod2)%mod2;
		cot[it[i]]=(cot[it[i]]+1)%3;
		cot2[it[i]]++;
		cur=(cur+pre2[it[i]]*cot[it[i]])%mod;
		cur2=(cur2+pre3[it[i]]*cot[it[i]])%mod2;
		if(cot2[it[i]]>3){
			while(ind<pre[it[i]][cot2[it[i]]-4]+1){
				ss[ac[ind]]--;
				ind++;
			}
		}
		ac[i+1]={cur,cur2};
		ss[{cur,cur2}]++;
		ans+=(ss[{cur,cur2}]-1);
	}





	cout<<ans<<endl;
 
	return 0;
}