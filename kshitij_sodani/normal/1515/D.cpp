//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo co[200001];
llo co2[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,l,r;
		cin>>n>>l>>r;
		vector<llo> aa;
		vector<llo> bb;
		for(llo i=0;i<=n;i++){
			co[i]=0;
			co2[i]=0;
		}
		for(llo i=0;i<l;i++){
			llo cc;
			cin>>cc;
			aa.pb(cc);
		}
		for(llo i=0;i<r;i++){
			llo cc;
			cin>>cc;
			bb.pb(cc);
		}
		if(l>r){
			swap(l,r);
			swap(aa,bb);
		}
		llo ans=(n/2)-l;
		for(auto j:aa){
			co[j]++;
		}
		for(auto j:bb){
			co2[j]++;
		}
		llo le=ans;
		for(llo i=0;i<=n;i++){
			if(co2[i]>co[i]){
				llo x=min((co2[i]-co[i])/2,le);
				le-=x;
				co2[i]-=x;
				co[i]+=x;
			}
		}
		for(llo i=0;i<=n;i++){
			if(co2[i]>co[i]){
				llo x=min((co2[i]-co[i]+1)/2,le);
				le-=x;
				co2[i]-=x;
				co[i]+=x;
			}
		}

		for(llo i=0;i<=n;i++){
			if(le>0){
				if(co[i]>0){
					llo x=min(co[i],le);
					le-=x;
					co[i]-=x;
					co2[i]+=x;
				}
			}
		}
		llo ans2=0;
		for(llo i=0;i<=n;i++){
		//	ans2+=
			ans2+=max(co[i],co2[i])-min(co[i],co2[i]);
		}
		ans+=(ans2/2);
		cout<<ans<<endl;





	}










	return 0;
}