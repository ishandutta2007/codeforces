#include<cstdio>
#include<algorithm>
using namespace std;
void Read(long long &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
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
long long x,y,m,ans;
int main()
{
	Read(x),Read(y),Read(m);
	if(x>=m||y>=m){
		puts("0");
		return 0;
	}
	if(x<=0&&y<=0){
		puts("-1");
		return 0;
	}
	if(x>y)
		swap(x,y);
	ans+=(y-x+y-1)/y;
	x+=ans*y;
	while(max(x,y)<m){
		if(x<y)
			x+=y;
		else
			y+=x;
		ans++;
	}
	printf("%I64d\n",ans);
}