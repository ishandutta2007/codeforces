#include<cstdio>
#include<iostream>
using namespace std;
const int N=102;
int n,m,i,j,k,a[N],b[N];
long long s;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=m;i++){
		scanf("%d",&j);
		b[j]=1;
	}
	for(i=1;i<=n;i++)
		if(!b[i])
			s+=a[i];
	k=0;
	for(i=1;i<=n;i++)
		if(b[i]&&a[i]>a[k])
			k=i;
	if(a[k]>s)
		s+=a[k],b[k]=0;
	for(i=1;i<=n;i++)
		if(b[i])
			s*=2;
	cout<<s;
}