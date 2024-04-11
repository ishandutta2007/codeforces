#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 100
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
int n,a[MAXN+10];
char s[MAXN*5+10];
int main()
{
	int i,j,len,cnt;
	Read(n);
	for(i=1;i<=n;i++)
		Read(a[i]);
	getchar();
	for(i=1;i<=n;i++){
		gets(s);
		len=strlen(s);
		cnt=0;
		for(j=0;j<len;j++)
			if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y')
				cnt++;
		if(cnt!=a[i]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}