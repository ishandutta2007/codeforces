#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 100000
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
int x,y,ans;
int main()
{
	Read(x),Read(y);
	if(y>x/2)
		puts("3");
	else{
		int a[3]={y,y,y};
		while(1){
			sort(a,a+3);
			if(a[0]==x)
				break;
			a[0]=min(x,a[1]+a[2]-1);
			ans++;
		}
		printf("%d\n",ans);
	}
}