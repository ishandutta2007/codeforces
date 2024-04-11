#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

llo it[400003];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		it[0]=0;
		it[n+1]=0;
		for(llo i=0;i<n;i++){
			cin>>it[i+1];
		}
		n+=2;
		priority_queue<pair<llo,llo>> xx;
		for(llo i=0;i<n;i++){
			if(it[i]>0){
				xx.push({it[i],i});
			}
		}
		llo ans=0;
		while(xx.size()){
			pair<llo,llo> no=xx.top();
			xx.pop();
			if(it[no.b-1]>=it[no.b] or it[no.b+1]>=it[no.b]){
				continue;
			}
			llo mi=max(it[no.b+1],it[no.b-1]);

			it[no.b]=mi;
			ans+=no.a-mi;
			if(it[no.b]>0){
				xx.push({mi,no.b});
			}
			//ans++;
		}
		
		for(llo i=1;i<n;i++){
			ans+=abs(it[i]-it[i-1]);
		}
		/*for(int i=0;i<n;i++){
			cout<<it[i]<<",";
		}
		cout<<endl;*/
		cout<<ans<<endl;




	}






	return 0;
}