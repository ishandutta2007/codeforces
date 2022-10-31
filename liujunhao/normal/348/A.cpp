#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MAXN 100000
using namespace std;
int n,mxa;
long long sum;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
void read(){
	Read(n);
	int a,i;
	for(i=1;i<=n;i++){
		Read(a);
		mxa=max(mxa,a);
		sum+=a;
	}
}
int main()
{
	read();
	printf("%I64d\n",max((sum+n-2)/(n-1),(long long)mxa));
}