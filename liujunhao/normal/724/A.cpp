#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int f(char *s){
	if(*s=='m')
		return 1;
	if(*s=='t'){
		if(s[1]=='u')
			return 2;
		return 4;
	}
	if(*s=='w')
		return 3;
	if(*s=='s'){
		if(s[1]=='a')
			return 6;
		return 7;
	}
	return 5;
}
char s[2][40];
int main()
{
	scanf("%s%s",s[0],s[1]);
	int a=f(s[0]),b=f(s[1]);
	if((b-a+7)%7==2||(b-a+7)%7==3||(b-a+7)%7==0)
		printf("YES\n");
	else
		puts("NO");
}