#include<cstdio>
const int N=103;
int n,a,b,l,r,i,s[N],k;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<n;i++){
		scanf("%d%d",&l,&r);
		s[l]++;
		s[r]--;
	}
	for(i=1;i<N;i++)
		s[i]+=s[i-1];
	for(i=a;i<b;i++)
		if(!s[i])
			k++;
	printf("%d",k);
}