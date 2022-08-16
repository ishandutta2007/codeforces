//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,m;
llo it[5001];
vector<llo> pre[5001];
llo cur[5001];
llo cur2[5001];
const llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		cur[it[i]]+=1;
	}
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		pre[aa].pb(bb);
		ss.pb({aa,bb});
	}
	pair<llo,llo> ans={0,1};
	llo aa=0;
	llo bb=1;
	for(llo i=1;i<=n;i++){
		sort(pre[i].begin(),pre[i].end());
		if(pre[i].size()){
			llo dd=0;
			for(auto j:pre[i]){
				if(j<=cur[i]){
					dd++;
				}
			}
			if(dd>0){
				aa++;
				bb=(bb*dd)%mod;
			}
		}
	}
	ans={aa,bb};
//	return 0;
	//cout<<ans.a<<" "<<ans.b<<endl;
	for(auto j:ss){
		for(llo i=1;i<=n;i++){
			cur2[i]=0;
		}
		llo ind=-1;
		for(llo i=0;i<n;i++){
			cur2[it[i]]+=1;
			if(cur2[j.a]>=j.b){
				ind=i;
				break;
			}
		}
		if(ind==-1){
			continue;
		}
		//cout<<j.a<<":"<<j.b<<":"<<ind<<endl;
		pair<llo,llo> cur3={1,1};
		//cur2[i],cur[i]-cur2[i];
		for(llo i=1;i<=n;i++){
			if(pre[i].size()==0){
				continue;
			}
			if(i!=j.a){
				llo co=0;
				llo co2=0;
				llo n1=0;
				llo n2=0;
				llo n3=0;
				for(auto jj:pre[i]){
					if(jj<=cur2[i]){
						co++;	
					}
					if(jj<=cur[i]-cur2[i]){
						co2++;
					}
					if(jj<=cur2[i] and jj<=cur[i]-cur2[i]){
						n1++;
					}
					if(jj<=cur2[i] and jj>cur[i]-cur2[i]){
						n2++;
					}
					if(jj>cur2[i] and jj<=cur[i]-cur2[i]){
						n3++;
					}
				}
				/*if(n1+n2+n3==0){
					continue;
				}
				llo zz=(n1+n2)*(n1+n3)-n1;
				if(zz>0){
					cur3.a+=2;
					cur3.b=(cur3.b*zz)%mod;
				}
				else{
					cur3.a+=1;
					zz=(2*n1+n2+n3);
					cur3.b=(cur3.b*zz)%mod;
				}
				continue;*/
				if(co==0 and co2==0){
					continue;
				}

				if(co==0){
					cur3.a+=1;
					cur3.b=(cur3.b*co2)%mod;
					continue;
				}
				if(co2==0){
					cur3.a+=1;
					cur3.b=(cur3.b*co)%mod;
					continue;
				}
				if(co==1 and co2==1){
					cur3.a+=1;
					cur3.b=(cur3.b*2)%mod;
					continue;
				}
				if(co<co2){
					swap(co,co2);
				}
				
				llo xx=(co-co2)*co2;
				xx%=mod;
				if(co2>=0){
					xx=(xx+((co2*(co2-1))))%mod;
				}
				cur3.a+=2;
				cur3.b=(cur3.b*xx)%mod;
			}
			else{
				llo co=0;
				for(auto jj:pre[i]){
					if(jj!=j.b and jj<=cur[i]-cur2[i]){
						co++;
					}
				}
				if(co>0){
					cur3.a+=1;
					cur3.b=(cur3.b*co)%mod;
				}
				//cur3.a+=co;
			}
		}
		if(ans.a<cur3.a){
			ans=cur3;
		}
		else if(ans.a==cur3.a){
			ans.b=(ans.b+cur3.b)%mod;
		}
	}
	cout<<ans.a<<" "<<ans.b<<endl;







 
 
 
	return 0;
}