#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	if(n<3)cout<<"-1",exit(0);
	for(int i=1;i<n-1;i++)cout<<i<<" ";
	cout<<n*n<<" "<<n*n-2<<"\n";
	for(int i=2;i<=n;i++){
		for(int j=1;j<n;j++)
	       	cout<<(n-1)*(i-1)+j-1<<" ";
		if(i<n)cout<<n*n-i-1<<"\n";
		else cout<<n*n-1<<"\n";
	}
}