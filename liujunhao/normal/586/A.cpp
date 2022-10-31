#include<cstdio>
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
#define MAXN 100
int n,a[MAXN+10],ans;
int main()
{
	int i;
	Read(n);
	for(i=1;i<=n;i++)
		Read(a[i]);
	i=1;
	while(!a[i])
		i++;
	while(!a[n])
		n--;
	for(;i<=n;i++)
		if(a[i])
			ans++;
		else if(a[i-1]&&a[i+1])
				ans++;
	printf("%d\n",ans);
}