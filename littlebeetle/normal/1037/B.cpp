#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=200020;
int n,s,a[N],i;
long long p;
int main(){
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n/2;i++)
		if(a[i]>s)
			p+=a[i]-s;
	if(a[i]!=s)
		p+=a[i]>s?a[i]-s:s-a[i];
	for(i++;i<=n;i++)
		if(a[i]<s)
			p+=s-a[i];
	cout<<p;
}