#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1],tot=0,b[n+1],all=0,ok=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<n;i++){
			all+=(a[i]+1)/2;
			if(a[i]%2==0){
				ok=1;
			}
			else if(a[i]/2>0){
				if(!ok) ok=2;
			}
		}
		if((ok==1)||(ok==2&&n>3)) cout<<all<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}