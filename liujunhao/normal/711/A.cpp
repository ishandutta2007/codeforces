#include<cstdio>
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
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
char s[10000][10];
int n;
int main()
{
	Read(n);
	int i;
	bool flag(0);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]);
	for(i=1;i<=n;i++){
		if(s[i][0]=='O'&&s[i][1]=='O'){
			s[i][0]=s[i][1]='+';
			flag=1;
			break;
		}
		if(s[i][3]=='O'&&s[i][4]=='O'){
			s[i][3]=s[i][4]='+';
			flag=1;
			break;
		}
	}
	if(flag){
		puts("YES");
		for(i=1;i<=n;i++)
			puts(s[i]);
	}
	else
		puts("NO");
}