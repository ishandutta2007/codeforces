//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
const llo mod=1e9+7;
llo it[100001];
llo n;

llo pre[100001];
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
llo fac[100001];
llo fac2[100001];
//llo pre2[301][301];
llo cal(llo x,llo y){
	llo cur=(fac[x]*fac2[y])%mod;
	//cout<<x<<":"<<y<<":"<<cur<":"<<fac[x]<<":"<<fac2[y]<<endl;
	cur=(cur*fac2[x-y])%mod;
//	cout<<x<<":"<<y<<":"<<cur<<endl;

	return cur;
}
llo solve(vector<llo> aa){
	map<llo,llo> zz;
	llo le=aa.size();
	for(auto j:aa){
		
		zz[j]++;
	}
	llo cur=1;
	for(auto j:zz){
		cur=(cur*cal(le,j.b))%mod;
		le-=j.b;
	}
	return cur;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	fac[0]=1;
	for(llo i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
	fac2[n]=ee(fac[n],mod-2);
	for(llo i=n-1;i>=0;i--){
		fac2[i]=(fac2[i+1]*(i+1))%mod;
	}
	//cout<<fac2[2]<<endl;



	llo su=0;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		su+=it[i];
	}
	if(su%n==0){
		llo aa=su/n;
		llo ans=1;
		llo co=0;
		vector<llo> ss;
		for(llo i=0;i<n;i++){
			if(it[i]==aa){
				co++;
			}
			else{
				ss.pb(it[i]);
			}
		}
		for(llo i=0;i<ss.size();i++){
			it[i]=ss[i];
		}
		llo xx=ss.size();
		//split co in xx+1
		//
		ans=(ans*cal(co+xx+1-1,xx))%mod;
		/*for(llo i=1;i<=co;i++){
			ans=(ans*(xx+i))%mod;
		}*/
		n=xx;
		if(n==0){
			cout<<ans<<endl;
			return 0;
		}
		llo bb=0;
		llo cc=0;
		vector<llo> dd;
		vector<llo> ee;
		for(llo i=0;i<n;i++){
			if(it[i]<aa){
				bb++;
				dd.pb(it[i]);
			}
			else{
				cc++;
				ee.pb(it[i]);
			}
		}

		if(bb==1){
			ans=(ans*solve(ee))%mod;
			ans=(ans*n)%mod;
			/*for(llo i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}*/
		}
		else if(cc==1){
			ans=(ans*solve(dd))%mod;
			ans=(ans*n)%mod;
			/*for(llo i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}*/
		}
		else{
			ans=(ans*solve(dd))%mod;
			ans=(ans*solve(ee))%mod;

			/*for(llo i=1;i<=bb;i++){
				ans=(ans*i)%mod;
			}
			for(llo i=1;i<=cc;i++){
				ans=(ans*i)%mod;
			}*/
			ans=(ans*2)%mod;
		}

		cout<<ans<<endl;


	}
	else{
		cout<<0<<endl;
	}



 
 
	return 0;
}