#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo t;
llo it[5001];
llo cc[5001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		for(llo i=0;i<n;i++){
			cc[i]=0;

		}
		llo ans=0;
		for(llo i=n-2;i>=0;i--){
			llo su=0;
			for(llo j=i-1;j>=0;j--){
				if(it[j]>it[i+1]){
					cc[j]++;
				}
				if(j<i-1){
					if(it[j]<it[i]){
						ans+=su;
					}
				}
				su+=cc[j];
			}
		}
		cout<<ans<<endl;
	}







	return 0;
}