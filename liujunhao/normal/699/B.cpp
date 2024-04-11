#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 1000
int n,m,row[MAXN+10],col[MAXN+10],tot;
char s[MAXN+10][MAXN+10];
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
	Read(n),Read(m);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j]=='*')
				row[i]++,col[j]++,tot++;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			int sum=row[i]+col[j]-(s[i][j]=='*');
			if(sum==tot){
				printf("YES\n%d %d\n",i,j);
				return 0;
			}
		}
	puts("NO");
}