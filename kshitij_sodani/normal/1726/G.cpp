#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;
const llo mod=998244353;
llo it[200001];
llo bb[200001];
llo co[500001];
llo val[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	llo ma=0;
	llo mi=1e9;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		ma=max(ma,it[i]);
		co[it[i]]++;
		mi=min(mi,it[i]);
	}
	if(mi==ma){
		llo ans=1;
		for(llo i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(mi+n-1<ma){
		cout<<0<<endl;
		return 0;
	}
	for(llo i=0;i<n;i++){
		cin>>bb[i];
	}
	for(llo i=2;i<=2*n+2;i++){
		co[i]+=co[i-1];
	}
	llo x=ma;
	for(llo j=0;j<n;j++){
		if(bb[j]==0){
			llo x=co[it[j]-1];
			val[j]=x+it[j];
		}
		else{
			val[j]=it[j]+co[2*n]-co[it[j]];
			x=max(x,val[j]+it[j]);
		}
	}

	for(llo i=mi+n-1;i<=mi+n-1;i++){
		llo st=1;
		//cout<<i<<"::"<<endl;
		vector<pair<llo,pair<llo,llo>>> tt;
		for(llo j=0;j<n;j++){
			//cout<<j<<","<<endl;
			if(bb[j]==0){
				if(val[j]<i){
					st=0;
					break;
				}
				tt.pb({it[j],{0,val[j]-i}});
				//val[j]-i smaller than this aa[j] 
			}
			else{
				if(val[j]>i){
					st=0;
					break;
				}
				if(it[j]==i){
					if(val[j]!=i){
						st=0;
						break;
					}
					else{
						tt.pb({it[j],{2,0}});
					}
					//else place anywhere
				}
				else{
					llo x=i-val[j];
					tt.pb({it[j],{1,x}});
					//x elements less than <= this
				}
			}
		}

		if(st==0){
			cout<<0<<endl;
			return 0;
		}
		sort(tt.begin(),tt.end());
		llo ans=1;
		llo cur=0;
		map<pair<llo,llo>,llo> ss;
		map<pair<llo,llo>,llo> ss2;
		llo ind=0;
		while(ind<tt.size()){
			llo ind2=ind;
			while(ind2+1<tt.size()){
				if(tt[ind2+1].a==tt[ind].a and tt[ind2+1].b.a==tt[ind].b.a and tt[ind2+1].b.b==tt[ind].b.b){
					ind2++;
				}
				else{
					break;
				}
			}

			
			if(tt[ind2].b.a==2){
				for(llo ii=ind;ii<=ind2;ii++){
					ans=(ans*(cur+1+ii-ind))%mod;
				}	
			}
			else if(tt[ind2].b.a==1){
				if(ind2>ind){
					cout<<0<<endl;
					return 0;
				}
				if(tt[ind2].b.b>cur){
					cout<<0<<endl;
					return 0;
				}
				ans=ans;
			}
			else if(tt[ind2].b.a==0){
				if(tt[ind2].b.b>cur){
					cout<<0<<endl;
					return 0;
				}
				for(llo ii=1;ii<=ind2-ind+1;ii++){
					ans=(ans*ii)%mod;
				}
			}
			cur+=(ind2-ind+1);
			ind=ind2+1;
		}
		cout<<ans<<endl;
	}






	return 0;
}