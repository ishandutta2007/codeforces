#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double pi=acos(-1);
void Read(int &x){
	static char c;
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
			return;
		}
	}
}
int d,h,v,e;
int main()
{
	Read(d),Read(h),Read(v),Read(e);
	if(pi*d*d*h<(v*4-e*pi*d*d)*10000){
		puts("YES");
		printf("%lf\n",pi*d*d*h/(v*4-e*pi*d*d));
	}
	else
		puts("NO");
}