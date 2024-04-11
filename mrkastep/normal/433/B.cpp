#include <stdio.h>
#include <algorithm>

long long int s1[100001],sa1[100001];
int s[100000],sa[100000];

int main(){
	#pragma comment(linker, "/STACK:16777216")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int t,l,r,n,m,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
		sa[i]=s[i];
	}
	s1[0]=0;
	s1[1]=(long long int)s[0];
	std::sort(sa,sa+n);
	sa1[0]=0;
	sa1[1]=(long long int)sa[0];
	for(i=1;i<n+1;i++){
		s1[i]=s1[i-1]+(long long int)s[i-1];
		sa1[i]=sa1[i-1]+(long long int)sa[i-1];
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			printf("%I64d\n",s1[r]-s1[l-1]);
		}
		else{
			printf("%I64d\n",sa1[r]-sa1[l-1]);
		}
	}
}