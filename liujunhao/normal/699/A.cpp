#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 200000
using namespace std;
int n,a[MAXN+10],ans=0x7fffffff;
char s[MAXN+10];
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
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int main()
{
	Read(n);
	int i;
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		Read(a[i]);
	for(i=1;i<n;i++){
		if(s[i]=='R'&&s[i+1]=='L')
			ans=min(ans,(a[i+1]-a[i])>>1);
	}
	if(ans==0x7fffffff)
		puts("-1");
	else
		printf("%d\n",ans);
}