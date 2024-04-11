#include<cstdio>
#include<cstring>
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
#define MAXN 100000
int n,a[MAXN+10];
int main()
{
	Read(n);
	for(int i=1;i<=n;i++)
		Read(a[i]);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]+a[i+1]);
}