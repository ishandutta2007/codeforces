#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
main(){
	double n,r;
	cin>>n>>r;
	printf("%.7lf",n*r*r*sin(pi/n)*sin(pi/2/n)/sin(pi-pi*3/2/n));
}