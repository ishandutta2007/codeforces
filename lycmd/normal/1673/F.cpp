#include<bits/stdc++.h>
using namespace std;
int const N=55;
int n,q,x,y,p[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1,w=0;i<=n;w^=i&-i,i++)
		p[w]=i;
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<n;j++)
			cout<<(j&-j)*(j&-j)<<" ";
	for(int i=1;i<n;i++,cout<<"\n")
		for(int j=1;j<=n;j++)
			cout<<(i&-i)*(i&-i)*2<<" ";
	while(q--){
		int k;cin>>k;
		for(int i=0;i<10;i++)
			(i&1?x:y)^=(k>>i&1)<<(i/2);
		cout<<p[x]<<" "<<p[y]<<"\n";
	}
}