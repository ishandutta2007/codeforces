#include<cstdio>
#include<cstring>
char dig[15];
int T,mx1,mx0;
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%s",dig+1);
		mx1=mx0=10;
		for(int i=1;dig[i];i++){
			int c=dig[i]-'0';
			if(c<mx1) mx1=c;
		}
		if(strlen(dig+1)==2) putchar(dig[2]);
		else putchar(mx1+48);
		putchar('\n');
	}
	return 0;
}