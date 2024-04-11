#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void ask(int k){
	cout<<"? "<<k<<endl;
}
int read(){int x;cin>>x;return x;}

void solve(){
	int l=1,r=1e9,res=r;
	int n;cin>>n;
	while(l<=r){
		int mid=((l+r)>>1);
		ask(mid);
		if(read()==1)res=mid,r=mid-1;
		else l=mid+1;
	}
	for(int i=2;i<=n;i++){
		int k=(res-1)/i;
		ask(k);
		int x=read();
		if(x==0)break;
		if(x<=i)res=k*i;
	}
	cout<<"! "<<res<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}