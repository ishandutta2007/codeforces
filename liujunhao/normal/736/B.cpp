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
int n;
inline bool isprime(int n){
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	Read(n);
	if(isprime(n))
		puts("1");
	else if(isprime(n-2))
		puts("2");
	else if(n&1)
		puts("3");
	else
		puts("2");
}