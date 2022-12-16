#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b){
	if(a<b)swap(a,b);
	if(!b)return a;
	return gcd(b,a%b);
}
int main(){
	LL a,b,x,y;
	cin>>a>>b>>x>>y;
	LL g=gcd(x,y);
	x/=g,y/=g;
	cout<<min(a/x,b/y);
	return 0;
}