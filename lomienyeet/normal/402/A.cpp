#include <bits/stdc++.h>
using namespace std;
void solve(){
	int k,a,b,v;
	cin>>k>>a>>b>>v;
	//hmm
	int rem=a,ans=0;
	while(rem>0){
		ans++;
		int e=0;
		if(b>k-1){
			e=k;
			b-=(k-1);
		}
		else{
			e=b+1;
			b=0;
		}
		rem-=v*e;
	}
	cout<<ans<<"\n";
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}