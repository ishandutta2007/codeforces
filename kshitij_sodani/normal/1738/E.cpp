#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=998244353; 

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
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}

llo it[100001];
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

	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		vector<pair<llo,llo>> aa;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(it[i]!=0){
				aa.pb({it[i],i});
			}
		}
		if(aa.size()==0){
			llo ans=1;
			for(llo i=2;i<=n;i++){
				ans=(ans*2)%mod;
			}
			cout<<ans<<endl;
			continue;
		}
		llo i=0;
		llo j=aa.size()-1;
		llo su=0;
		llo su2=0;
		vector<pair<llo,llo>> kk;
		while(i<j){
			if(su+aa[i].a<su2+aa[j].a){
				su+=aa[i].a;
				i++;
				if(su==su2){
					kk.pb({i-1,j+1});
				}
				continue;
			}
			if(su+aa[i].a>su2+aa[j].a){
				su2+=aa[j].a;
				j--;
				if(su2==su){
					kk.pb({i-1,j+1});
				}
				continue;
			}
			su+=aa[i].a;
			su2+=aa[j].a;
			kk.pb({i,j});
			i++;
			j--;
		}
		llo ans=1;
		llo cc=aa[0].b;
		llo dd=n-aa.back().b-1;
		llo xa=0;
		for(llo j=0;j<=min(cc,dd);j++){
			llo cur=(cal(cc,j)*cal(dd,j))%mod;
			xa=(xa+cur)%mod;
		}
		ans=(ans*xa)%mod;
	//	cout<<cc<<","<<dd<<endl;
		//for(auto j:kk){
	/*		cout<<j.a<<":"<<j.b<<endl;
		}
		cout<<ans<<endl;*/
		for(llo i=0;i<kk.size();i++){
			if(kk[i].b==kk[i].a+1){
				llo ee=aa[kk[i].b].b-aa[kk[i].a].b-1;
				ee+=1;
			//	cout<<ee<<":"<<endl;
				for(llo j=0;j<ee;j++){
					ans=(ans*2)%mod;
				}
			}
			else{
				llo cc=aa[kk[i].a+1].b-aa[kk[i].a].b-1;
				cc+=1;
				llo dd=aa[kk[i].b].b-aa[kk[i].b-1].b-1;
				dd+=1;
				llo ya=0;
				for(llo j=0;j<=min(cc,dd);j++){
					llo cur=(cal(cc,j)*cal(dd,j))%mod;
					ya=(ya+cur)%mod;
				}
				ans=(ans*ya)%mod;
			}
		}
		cout<<ans<<endl;

	}
	



	return 0;
}