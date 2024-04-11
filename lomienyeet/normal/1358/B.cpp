#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        sort(a,a+n);
        int ans=1;
        for(int j=n-1;j>=0;j--){
    		if(a[j]<=j+1){
    			ans=j+2;
    			break;
    		}
		 }
		 cout<<ans<<"\n";
    }
}