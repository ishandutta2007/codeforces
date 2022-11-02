#include<cstdio>
const int N=100002;
int n,k,i;
char s[N];
void work1(){
	while(k>1)
	printf("LEFT\n"),k--;
	for(i=1;i<=n;i++){
		printf("PRINT %c\n",s[i]);
		if(i!=n)
			printf("RIGHT\n");
	}
}
void work2(){
	while(k<n)
	printf("RIGHT\n"),k++;
	for(i=n;i;i--){
		printf("PRINT %c\n",s[i]);
		if(i!=1)
			printf("LEFT\n");
	}
}
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	if(k-1<n-k)
	work1();
	else
	work2();
}