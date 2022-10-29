#include <cstdio>
#include <iostream>
using namespace std;

int a[100005];
int rps[100005];
int nk[100005];

int main(){
	int n,s,i,j,k,ps;
	long long int r;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		s+=a[i];
	}
	if(s%3!=0){
		puts("0");return 0;
	}
	k=s/3;
	for(i=n;i>0;i--){
		rps[i]=rps[i+1]+a[i];
		nk[i]=nk[i+1]+(rps[i]==k);
	}
	ps=0;
	r=0;
	for(i=1;i<=n;++i){
		ps+=a[i];
		if(ps==k){
			r+=nk[i+2];
		}
	}
	cout<<r<<endl;
	return 0;
}