#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 100000
using namespace std;
void Read(int &x){
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
char s[MAXN+10];
int n,cnt[2000];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	if(n&1)
		puts("-1");
	else{
		while(n--)
			cnt[s[n]]++;
		printf("%d\n",(abs(cnt['L']-cnt['R'])+abs(cnt['U']-cnt['D']))>>1);
	}
}