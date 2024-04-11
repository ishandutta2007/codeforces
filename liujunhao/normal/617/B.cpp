#include<cstdio>
#define MAXN 100
int n,a;
long long ans=1;
bool f;
void Read(int &x){
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
int main()
{
	Read(n);
	int i,cnt=0;
	for(i=1;i<=n;i++,cnt++){
		Read(a);
		if(a){
			if(f)
				ans*=cnt;
			else
				f=1;
			cnt=0;
		}
	}
	if(f)
		printf("%I64d\n",ans);
	else
		puts("0");
}