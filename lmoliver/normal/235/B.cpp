#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	double esc=0,el=0,es=0;
	for(int i=1;i<=n+1;i++){
		double p;
		if(i<=n)scanf("%lf",&p);
		else p=0;
		esc+=es*(1-p);
		es=(es+2*el+1)*p;
		el=(el+1)*p;
	}
	printf("%.15f",esc);
}