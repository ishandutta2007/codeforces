#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 100000
#define MAXM 100000
int n,u,k;
template<class T>
bool Read(T &x){
	char c;
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
			return 1;
		}
	}
	return 0;
}
int main()
{
	Read(n);
	if(n<3){
		puts("-1");
	}
	else if(n%4==0)
		printf("%I64d %I64d\n",3ll*n/4,5ll*n/4);
	else{
		while(!(n&1))
			u++,n>>=1;
		k=(n-3)/2;
		printf("%I64d %I64d\n",(4+(6ll+2ll*k)*k)*(1ll<<u),(5+(6ll+2ll*k)*k)*(1ll<<u));
	}
}