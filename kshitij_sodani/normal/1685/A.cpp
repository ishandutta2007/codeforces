#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[100001];
llo ans[100001];
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
		sort(it,it+n);
		if(n%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		if(n%2==0){
			/*if(it[n/2]==it[(n/2)-1]){
				cout<<"NO"<<endl;
			}
			else{*/
				//cout<<"YES"<<endl;
				llo ind=0;
				llo ind2=n/2;
				for(llo i=0;i<n;i++){
					if(i%2==0){
						ans[i]=it[ind];
						//cout<<it[ind]<<" ";
						ind++;
					}
					else{
						ans[i]=it[ind2];
						//cout<<it[ind2]<<" ";
						ind2++;
					}
				}
				//cout<<endl;
				string ans2="YES";
				for(int i=0;i<n;i++){
					if(ans[i]==ans[(i+1)%n]){
						ans2="NO";
					}
				}
				cout<<ans2<<endl;
				if(ans2=="YES"){
					for(int i=0;i<n;i++){
						cout<<ans[i]<<" ";
					}
					cout<<endl;
				}
			//}
		}
	}









	return 0;
}