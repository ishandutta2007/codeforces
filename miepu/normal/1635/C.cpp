#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	int pr=-1e9,fl=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<pr)fl=0;
		pr=a[i];
	}
	if(fl){
		cout<<0<<endl;
		return ;
	}
	if(a[n-1]>=0&&a[n-2]<=a[n-1]){
		cout<<n-2<<endl;
		for(int i=1;i<=n-2;i++)
			cout<<i<<' '<<n-1<<' '<<n<<endl;
	}else{
		cout<<-1<<endl; 
	}
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}