#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,a,b,c,r;
	cin>>n>>a>>b>>c;
	if(a<=b-c){
		r=n/a;
	}
	else {
		r=max(n-b-1,0LL)/(b-c);
		n-=r*(b-c);
		while(b<=n){
			r++;
			n-=b-c;
		}
		r+=n/a;
	}
	cout<<r<<endl;
	return 0;
}