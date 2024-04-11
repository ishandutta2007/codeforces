#include<cstdio>
const int N=100;
int n,i;
int a[N];
char s[3];
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%1s",s);
		if(*s=='L'){
			for(i=0;a[i];i++);
			a[i]=1;
		}
		if(*s=='R'){
			for(i=9;a[i];i--);
			a[i]=1;
		}
		if(*s!='L'&&*s!='R'){
			a[*s-48]=0;
		}
			
	}
	for(i=0;i<=9;i++)
		printf("%d",a[i]);
}