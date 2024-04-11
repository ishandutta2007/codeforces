#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int t,n,a[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=1,r=n;
		while(l<=n&&a[l])l++;
		while(r>=1&&a[r])r--;
		cout<<max(r-l+2,0)<<"\n"; 
	}
}