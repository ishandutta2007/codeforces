#include<cstdio>
#include<algorithm>
#define MAXN 100000
using namespace std;
long long ans;
int n,a[MAXN+10],mina=0x7fffffff;
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
int main()
{
	Read(n);
	for(int i=1;i<=n;i++){
		Read(a[i]);
		if(a[i]&1)
			mina=min(mina,a[i]);
		ans+=a[i];
	}
	if(ans&1)
		ans-=mina;
	printf("%I64d",ans);
}