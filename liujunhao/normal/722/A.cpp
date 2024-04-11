#include<cstdio>
#include<algorithm>
#include<cstring>
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
int n,a,b;
int main()
{
	Read(n),Read(a),Read(b);
	if(n==12){
		if(a>12)
			a%=10;
		if(!a)
			a+=10;
		if(b>=60)
			b%=10;
		printf("%02d:%02d\n",a,b);
	}
	else{
		if(a>23)
			a%=10;
		if(b>=60)
			b%=10;
		printf("%02d:%02d\n",a,b);
	}
}