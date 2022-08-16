#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=1e9+7;
vector<llo> adj[200001];
llo ss[200001];
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
llo fac[200001];
llo fac2[200001];
llo cal(llo x,llo y){
 	if(x<y){
 		return 0;
 	}
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}
llo ans=0;
llo n,k;
void dfs(llo no,llo par=-1){
	ss[no]=1;
	vector<pair<llo,pair<llo,llo>>> tt;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			tt.pb({j,{ss[j],cal(ss[j],k)}});
			ss[no]+=ss[j];
		}
	}
	llo su=0;
	
	

	tt.pb({-1,{n-ss[no],cal(n-ss[no],k)}});
	for(auto j:tt){
		su=(su+j.b.b)%mod;
	}
	for(auto j:tt){
		llo le=n-j.b.a;
		//cout<<le<<endl;
		//cout<<k<<endl;
		//cout<<cal(le,k)<<endl;
		llo cur=cal(le,k);
		cur=(cur-su+mod)%mod;
		cur=(cur+j.b.b+mod)%mod;
		//cout<<no<<":"<<j.a<<":"<<j.b.a<<":"<<((cur*j.b.a)%mod)<<endl;
		cur=(cur*j.b.a)%mod;
		cur=(cur*(n-j.b.a))%mod;
		//cout<<cur<<endl;
		ans=(ans+cur)%mod;
	}
	llo cur2=cal(n,k);
	
	cur2=(cur2-su+mod)%mod;
	//cout<<no<<":"<<cur2<<":"<<su<<endl;
	ans=(ans+cur2*n)%mod;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		fac[0]=1;
	llo ma=200000;
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

	
	cin>>n>>k;
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);



	cout<<ans<<endl;



	return 0;
}