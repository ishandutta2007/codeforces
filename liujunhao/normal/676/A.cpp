#include<cstdio>
#define MAXN 100
#define max(a,b) (a)>(b)?(a):(b)
int a[MAXN+10],n,ans;
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
	int i;
	for(i=1;i<=n;i++){
		Read(a[i]);
		if(a[i]==1||a[i]==n)
			ans=max(max(i-1,n-i),ans);
	}
	printf("%d\n",ans);
}