#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N];
void solve(){
	cin>>n;
	int fl1=0,fl0=0,fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)fl1=1;
		if(a[i]==0)fl0=1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		if(a[i+1]==a[i]+1)
			fl=1;
	if(fl1&&(fl0||fl))cout<<"No"<<endl;
	else cout<<"Yes"<<endl; 
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}