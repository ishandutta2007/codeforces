#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N],b[N]; 
void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>b[i]){
			cout<<"NO"<<endl;
			return ;
		}
		if(a[i]==b[i]){
			continue;
		}
		if(b[i]>b[(i+1)%n]+1){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
	return ;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}