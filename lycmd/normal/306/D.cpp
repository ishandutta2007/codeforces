#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin>>n,cout<<fixed<<setprecision(8);
	if(n<5)cout<<"No solution\n",exit(0);
	double a=acos(-1.0)*2.0/n,x=0.0,y=0.0;
	for(int i=0;i<n-1;i++)
		cout<<(x+=(100.0+i*0.002)*cos(i*a))<<" "
			<<(y+=(100.0+i*0.002)*sin(i*a))<<"\n";
	cout<<x-y/tan(a*(n-1))<<" 0.000\n";
}