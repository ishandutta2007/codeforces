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
long long n,f[100];
int main()
{
	Read(n);
	f[1]=2,f[2]=3;
	if(n==2)
		printf("%d\n",1);
	else{
		int i;
		for(i=3;i<=n;i++){
			f[i]=f[i-1]+f[i-2];
			if(f[i]>n){
				printf("%d\n",i-1);
				return 0;
			}
		}
	}
}