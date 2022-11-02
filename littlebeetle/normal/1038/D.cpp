#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[500002],i,k;
long long s;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i),s-=a[i];
	k=(n+1)/2;
	sort(a,a+n);
	s+=a[n-1]*2;
	for(i=2;i<n;i++){
		if(a[n-i]<0)
			break;
		s+=2*a[n-i];
	}
	cout<<s;
}