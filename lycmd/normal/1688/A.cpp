#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	for(cin>>t;t--;)
		cin>>n,cout<<(n<2?3:!(n&(n-1))+(n&-n))<<"\n";
}