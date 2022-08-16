#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


llo it[200001];
llo pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		llo ans2=(k*(k-1))/2;
		if(k>n){
			ans2=(k-1+k-n);
			ans2*=n;
			ans2/=2;
		//	cout<<ans2<<":"<<endl;
			k=n;
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
			pre[i+1]=pre[i]+it[i];
		}
		llo ans=0;
		for(llo i=k-1;i<n;i++){
			ans=max(ans,pre[i+1]-pre[i-(k-1)]);
		}
	//	cout<<ans<<endl;
		ans+=ans2;
		cout<<ans<<endl;

	}






	return 0;
}