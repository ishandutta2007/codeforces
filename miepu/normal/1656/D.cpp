#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

__int128 S(__int128 k){
	return (k)*(k+1)/2;
}

void solve(){
	int k,n;cin>>k,n=k;
	if(k&1){
		cout<<2<<endl;
		return ;
	}else{
		int res=2;
		while(!(k&1))res<<=1,k>>=1;
		if(S(res)<=n)cout<<res<<endl;
		else if(k!=1&&S(k)<=n)cout<<k<<endl;
		else cout<<-1<<endl;
	}
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}