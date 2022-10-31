#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100
template<class T>
void Read(T &x){
	char c;
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
int n,a[MAXN+10];
int main()
{
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]);
	if(a[n]==0)
		puts("UP");
	else if(a[n]==15)
		puts("DOWN");
	else if(n==1)
		puts("-1");
	else if(a[n-1]<a[n])
		puts("UP");
	else
		puts("DOWN");
}