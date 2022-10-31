#include<cstdio>
template<class T>
bool Read(T &x){
	char c;
	bool f=0;
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
			return 1;
		}
	}
	return 0;
}
int n,m;
char s[20];
bool flag=0;
int main()
{
	Read(n),Read(m);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%s",s);
			flag|=(*s!='B'&&*s!='W'&&*s!='G');
		}
	if(flag)
		puts("#Color");
	else
		puts("#Black&White");
}