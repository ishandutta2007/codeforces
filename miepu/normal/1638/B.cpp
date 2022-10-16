#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,mx0=0,mx1=0,fl=1;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x&1){
			if(x<mx1)fl=0;
			mx1=max(mx1,x);
		}else{
			if(x<mx0)fl=0;
			mx0=max(mx0,x);
		}
	}
	cout<<(fl?"YEs":"No")<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}