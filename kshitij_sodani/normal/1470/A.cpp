//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;
llo aa[300001];
llo bb[300001];
llo co[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
		}
		for(llo i=0;i<m;i++){
			cin>>bb[i];
			co[i]=1;
		}
		for(llo i=0;i<n;i++){
			co[aa[i]-1]++;
		}
		llo ind=0;
		sort(aa,aa+n);
		llo ans=0;
		for(llo i=0;i<n;i++){
			if(ind<aa[i]){
				ans+=bb[ind];
				co[ind]--;
				if(co[ind]==0){
					ind++;
				}
			}
			else{
				ans+=bb[aa[i]-1];
			}
		}
		cout<<ans<<endl;
	}





 
	return 0;
}