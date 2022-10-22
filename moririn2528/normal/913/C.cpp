#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	long long int n,m;
	long long int a[35];
	long long int s=0;
	long long int i,j,k;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(i>0)a[i]=min(a[i],a[i-1]*2);
	}
	k=1<<(n-1);
	if(m>k)s=(m/k)*a[n-1],m%=k;
	for(i=0,j=0;i<n;i++){
		k=1<<i;
		if(j>a[i])j=a[i];
		if(m&k)j+=a[i];
	}
	cout<<s+j<<endl;
	return 0;
}