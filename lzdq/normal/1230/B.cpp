#include<cstdio>
int n,k,cnt;
int main(){
	scanf("%d %d",&n,&k);
	if(n==1){
		char ch;
		while((ch=getchar())<'0'||ch>'9');
		if(k) putchar('0');
		else putchar(ch);
	}
	else
	for(register int i=1;i<=n;i++){
		char ch;
		while((ch=getchar())<'0'||ch>'9');
		if(cnt<k){
			if(i==1){
				putchar('1');
				if(ch!='1') cnt++;
			}
			else{
				putchar('0');
				if(ch!='0') cnt++;
			}
		}
		else putchar(ch);
	}
	putchar('\n');
	return 0;
}