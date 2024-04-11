#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;
	cin>>n;
	if(n==3){
		cout<<"3 1 2\n1 3 2\n3 2 1\n";
		return ;
	}
	for(int i=n;i>=1;i--){
		for(int j=i,k=1;k<=n;k++,j--){
			if(j==0)j=n;
			cout<<j<<' ';
		}cout<<endl;
	}
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}