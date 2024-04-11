#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,a[N];
int calc(int x,int y){
	double d=y?1.0*y/x:0.0,b=x;
	int cnt=0;
	for(int i=1;i<=n;i++)
		b==a[i]?b*=d:cnt++;
	return min(cnt,2);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3)
		cout<<(!a[1]&&a[2])<<"\n",exit(0);
	cout<<min(calc(a[1],a[2]),min(calc(a[2],a[3]),calc(a[1],a[3])))<<"\n";
}