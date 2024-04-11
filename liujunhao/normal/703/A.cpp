#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			if(f)
				x=-x;
			ungetc(c,stdin);
			return;
		}
	}
}
int main()
{
	int n,x,y,ca,cb;
	ca=cb=0;
	Read(n);
	while(n--){
		Read(x),Read(y);
		if(x>y)
			ca++;
		else if(x<y)
			cb++;
	}
	if(ca>cb)
		puts("Mishka");
	else if(ca<cb)
		puts("Chris");
	else
		puts("Friendship is magic!^^");
}