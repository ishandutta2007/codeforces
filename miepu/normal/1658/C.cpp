#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	int cnt=0,pos=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++,pos=i;
	} 
	int res=1,pr=0;
	if(cnt!=1)res=0;
	for(int i=0,j=pos;i<n;i++,j++,j%=n){
		if(a[j]>pr+1)res=0;
		pr=a[j];
	}
	cout<<(res?"Yes":"No")<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}