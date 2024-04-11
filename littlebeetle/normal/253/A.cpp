#include<cstdio>
int a,b;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&a,&b);
	if(a>b){
		while(b--)
			a--,printf("BG");
		while(a--)
			printf("B");
	}	
	else{
		while(a--)
			b--,printf("GB");
		while(b--)
			printf("G");
	}
	return 0;
}