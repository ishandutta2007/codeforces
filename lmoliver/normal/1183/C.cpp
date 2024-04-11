#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=111;
int a[N];
int main(){
	int q;
	cin>>q;
	while(q--){
		LL k,n,a,b;
		cin>>k>>n>>a>>b;
		if(n*b>=k){
			puts("-1");
			continue;
		};
		LL ans=k>n*a?n:n-((n*a-k)/(a-b)+1);
		cout<<ans<<endl;
	}
	return 0;
}