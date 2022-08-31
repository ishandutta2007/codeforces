//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


 const llo mod=998244353;
//llo pre[200001];
llo ee(llo aa,llo bb){
	if(bb==0){
		return 1;
	}
	llo ac=ee(aa,bb/2);
	ac=(ac*ac)%mod;
	if(bb%2==1){
		ac=(ac*aa)%mod;
	}
	return ac;
}
llo fac[400002];
llo fac2[400002];
llo cal(llo x,llo y){
 	if(y>x){
 		return 0;
 	}
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<llo,null_type,less<llo>,rb_tree_tag,tree_order_statistics_node_update>
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0]=1;
	llo ma=400001;
	for(llo i=1;i<=ma;i++){
		fac[i]=(fac[i-1]*i)%mod;
		//cout<<fac[i]<<":";
	}
//	cout<<endl;
 
	for(llo i=ma;i>=0;i--){
		if(i==ma){
			fac2[i]=ee(fac[i],mod-2);
		}
		else{
			fac2[i]=(fac2[i+1]*(i+1))%mod;
		}
		//cout<<fac2[i]<<":";
	}
	llo t;
	cin>>t;
	ord ss;
	for(llo i=0;i<=200000;i++){
		ss.insert(i);
	}
	while(t--){
		llo n,m;
		cin>>n>>m;
		vector<pair<llo,llo>> qq;
		for(llo i=0;i<m;i++){
			llo aa,bb;
			cin>>aa>>bb;
			qq.pb({aa,bb});
		}
		set<llo> cur;
		vector<llo> xx;
		while(qq.size()){
			pair<llo,llo> no=qq.back();
			qq.pop_back();
			llo ac=*ss.find_by_order(no.b-1);
			llo cc=*ss.find_by_order(no.b);
			cur.insert(cc);
			xx.pb(ac);
			ss.erase(ac);
		}
		llo cot=cur.size();
		for(auto j:xx){
			ss.insert(j);
		}
		//cout<<cot<<":"<<endl;
		//n-1-cot in n+1 compartments
		cout<<cal(2*n-cot-1,n)<<endl;

	}
 
 
 
 
 
 
 
 
	return 0;
}