#include<cstdio>
#include<algorithm>
using namespace std;
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
int a[3];
int main()
{
	Read(a[0]),Read(a[1]),Read(a[2]);
	sort(a,a+3);
	printf("%d\n",a[2]-a[0]);
}