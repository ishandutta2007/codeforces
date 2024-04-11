#include<cstdio>
const int N=100002;
int n,i,j,k,a,s[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(i<=n/2)
			j=i;
		else
			j=n-i+1;
		if(a>=j)
			s[a-j]++;
	}
	for(i=0;i<N;i++)
		if(s[i]>k)
			k=s[i];
	printf("%d\n",n-k);
	//while(1);
}