#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
void Read(int &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int main()
{
	int n;
	Read(n);
/*	if(n==4)
		puts("0");
	else if(n==6) puts("1");
	else if(n==8) puts("0");
	else if(n==10) puts("1");
	else if(n==12) puts("2");
	else if(n==14) puts("3");
	else if(n==16) puts("0");
	else if(n==18) puts("1");
	else */
	if(n&1)
		printf("%d\n",(n-1)>>1);
	else{
		int t=log2(n+0.5);
		printf("%d\n",(n-(1<<t))>>1);
	}
}