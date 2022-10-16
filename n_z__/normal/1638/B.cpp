#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1],b[n+1],bk=0,c[n+1],ck=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]&1){
				bk++;
				b[bk]=a[i];
			}
			else{
				ck++;
				c[ck]=a[i];
			}
		}
		int ok=1;
		for(int i=1;i<bk;i++){
			if(b[i]>b[i+1]){
				ok=0;
			}
		}
		for(int i=1;i<ck;i++){
			if(c[i]>c[i+1]){
				ok=0;
			}
		}
		if(ok) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}