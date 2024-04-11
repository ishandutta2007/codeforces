#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n&&n<4)cout<<"N\n";
		else cout<<"Y "<<fixed<<setprecision(9)<<(n-sqrt(n*n-4*n))/2<<" "<<(n+sqrt(n*n-4*n))/2<<"\n";
	}
}