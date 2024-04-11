//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[100001];
const llo mod=998244353;
llo le[100001];
vector<llo> pre;
vector<llo> cc;
llo co[100001];
llo co2[100001];
llo vis[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			
		}

		llo ans=0;
		pre.clear();		
		for(llo i=n-1;i>=0;i--){
			if(i==n-1){
				pre.pb(it[i]);
				co[it[i]]++;
			}
			else{
				for(auto j:pre){
					co2[j]=co[j];
				}
				for(auto j:pre){
					co[j]=0;
				}
				vector<llo> pre2;
				for(auto j:pre){
					llo xx=((it[i]+j-1)/j);
					ans=(ans+(i+1)*(xx-1)*co2[j])%mod;
					xx=it[i]/xx;
					if(vis[xx]==0){
						pre2.pb(xx);
						vis[xx]=1;
					}
					co[xx]+=co2[j];
				}
				//handle it[i] case
				co[it[i]]++;
				if(vis[it[i]]==0){
					vis[it[i]]=1;
					pre2.pb(it[i]);
				}
				for(auto j:pre2){
					vis[j]=0;
				}
				pre=pre2;
			}
			/*for(auto j:pre){
				cout<<j<<",";
			}
			cout<<endl;*/
			
		}
		for(auto j:pre){
			co[j]=0;
		}
		cout<<ans<<endl;
		/*le[0]=0;
		for(llo i=1;i<=n;i++){
			pre[i]=pre[i-1]+i*(it[i-1]-1);
		}
		for(llo i=1;i<n;i++){
			if(it[i]<it[i-1]){
				le[i]=i;
			}
			else{
				le[i]=le[i-1];
			}
		}*/
		/*for(llo i=0;i<n;i++){
			llo ind=i;
			llo cur=it[i];
			while(ind>=1){
				if(cur==1){
					ans=(pre[ind]+ans)%mod;
					//handle previous values
					break;
				}
				if(cur>=it[ind-1]){
					ind=le[ind-1];
					cur=it[ind];
				}
				else{
					llo xx=((it[ind-1]+cur-1)/cur);
					ans=(ans+(xx-1)*(ind))%mod;
					cur=(it[ind-1]/xx);
					ind--;
				}
			}
			//cout<<ans<<":"<<endl;
		}*/
	}





 
	return 0;
}