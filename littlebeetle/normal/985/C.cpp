#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100002;
int n,k,l,i,j,a[N];
long long s;
int main(){
	scanf("%d%d%d",&n,&k,&l);
	for(i=1;i<=n*k;i++)
		scanf("%d",a+i);
	sort(a+1,a+n*k+1);
	i=1;
	while(i<n*k&&a[i+1]<=a[1]+l)
		i++;
	j=n*k-i;
	while(i){
		if(j>=k-1)
			j-=k-1,s+=a[i];
		else
			j++;
		i--;
	}
	if(j==0)
		cout<<s;
	else
		cout<<0;
}