#include<cctype>
#include<cstdio>
inline int gc(){
	char ch;
	while(!isdigit(ch=getchar()));
	return ch;
}
int n;
int main(){
	scanf("%d",&n);
	if(n==1)putchar(gc());
	else{
		putchar(49);
		while(n--)
			if(gc()==48)
				putchar(48);
	}
	return 0;
}