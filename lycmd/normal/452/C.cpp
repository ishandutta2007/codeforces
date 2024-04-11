#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	cout<<fixed<<setprecision(8)<<1.0/n+(n*m<2?0:(n-1.0)/n*(m-1)/(n*m-1))<<"\n";
}