#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo aa[200001];
llo bb[200001];
llo pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
		}
		for(llo i=0;i<n;i++){
			cin>>bb[i];
		}
		for(int i=0;i<=n;i++){
			pre[i]=0;
		}
		llo ind=n-1;
		llo ind2=n-1;
		llo stt=0;;
		while(ind>=0 and ind2>=0){
			llo cur=aa[ind];
			llo co=0;
			while(ind>=0){
				if(cur==aa[ind]){
					co++;
					ind--;
				}
				else{
					break;
				}
			}
			llo cur2=bb[ind2];
			llo co2=0;
			while(ind2>=0){
				if(cur==bb[ind2]){
					co2++;
					ind2--;
				}
				else{
					break;
				}
			}
			if(co>co2){
				llo xx=min(pre[cur],co-co2);
				pre[cur]-=xx;
				co-=xx;
				if(co>co2){
					stt=1;
					cout<<"NO"<<endl;
					break;
				}
				pre[cur]+=co2-co;
			}
			else if(co==co2){
				continue;
			}
			else{
				pre[cur]+=co2-co;
				continue;
			}
		}



		if(stt==0){
			cout<<"YES"<<endl;
		}
	}



	return 0;
}