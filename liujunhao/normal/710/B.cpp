#include<cstdio>
#include<algorithm>
#define MAXN 300000
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
int n,a[MAXN+10];
int main()
{
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]);
	sort(a+1,a+n+1);
	printf("%d\n",a[(n+1)/2]);
}