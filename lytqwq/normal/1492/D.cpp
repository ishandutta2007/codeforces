#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a,b,k;
int c1[N],c2[N];
int main(){
	scanf("%d%d%d",&a,&b,&k);
	if(k==0){
			printf("Yes\n");
			for(int i=1;i<=b;i++)printf("1");
			for(int i=1;i<=a;i++)printf("0");
			printf("\n");
			for(int i=1;i<=b;i++)printf("1");
			for(int i=1;i<=a;i++)printf("0");
			printf("\n");
			return 0;
		}
	if(a==0){
		if(k!=0)printf("No\n");
		else {
			printf("Yes\n");
			for(int i=1;i<=a+b;i++)printf("1");
			printf("\n");
			for(int i=1;i<=a+b;i++)printf("1");
			printf("\n");
		}
		return 0;
	}
	if(b==1){
		if(k!=0)printf("No\n");
		else {
			printf("Yes\n");
			printf("1");
			for(int i=1;i<=a+b-1;i++)printf("0");
			printf("\n");
			printf("1");
			for(int i=1;i<=a+b-1;i++)printf("0");
			printf("\n");
		}
		return 0;
	}
	for(int i=a+b;i>=a+1;i--){
		c1[i]=1;
	}
	c2[a+b]=1;
	for(int i=a+b-2;i>=a+1;i--){
		c2[i]=1;
	}
	if(a+b-1-k>=1){
		if(a+b-1-k<=a){
			c2[a+b-1-k]=1;
			printf("Yes\n");
			for(int i=a+b;i>=1;i--){
				printf("%d",c1[i]);
			}
			printf("\n");
			for(int i=a+b;i>=1;i--){
				printf("%d",c2[i]);
			}
			printf("\n");
		}
		else{
			c2[a+b-1]=1;
			c2[k+1]=0;
			c2[1]=1;
			printf("Yes\n");
			for(int i=a+b;i>=1;i--){
				printf("%d",c1[i]);
			}
			printf("\n");
			for(int i=a+b;i>=1;i--){
				printf("%d",c2[i]);
			}
			printf("\n");
		}
	}
	else{
		printf("No\n");
		
	}
	return 0;
}
/*
a+b-2 ? 1
? 1
a+b-2-?+1=k
a+b-1-k >=1 <=a

11110
10111
*/