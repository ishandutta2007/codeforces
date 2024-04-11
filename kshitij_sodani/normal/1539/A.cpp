#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	llo k;
	cin>>k;
	while(k--){
		llo n,x,t;
		cin>>n>>x>>t;
		if(t<x){
			cout<<0<<endl;
			continue;
		}
		llo xx=t/x;
		xx=min(xx,n-1);
		llo ans=n*xx;
		llo ans2=((xx*(xx+1)))/2;
		cout<<ans-ans2<<endl;

	}










	return 0;
}