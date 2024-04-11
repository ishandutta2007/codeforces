#include<cstdio>
#include<iostream>
using namespace std;
const int N=500002;
int n,a[N],i;
long long p,s,u,v;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s+=a[i];
	for(i=1;i<n;i++){
		p+=a[i];
		if(p*3==s*2)
			v+=u;
		if(p*3==s)
			u++;
	}
	cout<<v;
}