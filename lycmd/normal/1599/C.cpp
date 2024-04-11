#include<bits/stdc++.h>
#define int long long
#define s2(x) ((x)*((x)-1)/2)
#define s3(x) ((x)*((x)-1)*((x)-2)/6)
using namespace std;
int const N=1010;
double const EPS=1e-8;
int n;
double p;
int leq(double x,double y){
	return x-y<EPS;
}
int check(int x){
	return leq(p,1.0*(s3(x)+s2(x)*(n-x)+0.5*x*s2(n-x))/s3(n));
}
signed main(){
	cin>>n>>p;
	if(leq(p,0.0))
		cout<<"0\n",exit(0);
	int l=0,r=n;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<r<<"\n";
}