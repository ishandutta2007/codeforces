#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

	int n,a[N],k;
void solve(){
	cin>>n>>k;
map<int,int>A;	for(int i=1;i<=n;i++)cin>>a[i],A[a[i]]=1;
	for(int i=1;i<=n;i++)
		if(A[a[i]+k]){
		cout<<"Yes"<<endl;return ;}cout<<"No"<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}