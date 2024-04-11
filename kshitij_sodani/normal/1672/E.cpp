#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back

llo it[200001];
llo ask(llo i){
	if(i<=0){
		return 0;
	}
	cout<<"? "<<i<<endl;
	llo x;
	cin>>x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t=1;
	
	while(t--){
		llo n;
		cin>>n;
		/*for(llo i=0;i<n;i++){
			cin>>it[i];
		}*/
		llo low=1e9;
		for(llo j=29;j>=0;j--){
			if(low-(1<<j)>=1){
				if(ask(low-(1<<j))==1){
					low-=(1<<j);
				}
			}
		}
		//sum is low+1
		llo ans=low;
		for(llo i=1;i<=n;i++){
			llo z=((low+1-i)+i-1)/i;
			llo y=ask(z);
			if(y==0){
				continue;
			}
			ans=min(ans,((y*z)));
		}
		cout<<"! "<<ans<<endl;


	}








	return 0;
}