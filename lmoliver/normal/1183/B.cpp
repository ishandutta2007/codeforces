#include<bits/stdc++.h>
using namespace std;
const int N=111;
int a[N];
int main(){
	int q;
	cin>>q;
	while(q--){
		int n,k;
		cin>>n>>k;
		int l=0,r=INT_MAX;
		for(int i=0;i<n;i++){
			cin>>a[i];
			l=max(l,a[i]-k);
			r=min(r,a[i]+k);
		}
		if(l>r)cout<<-1<<endl;
		else cout<<r<<endl;
	}
	return 0;
}