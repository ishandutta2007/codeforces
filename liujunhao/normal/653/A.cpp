#include<cstdio>
#include<algorithm>
using namespace std;
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
int n,a[100];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=2;i<n;i++)
		if(a[i]==a[i-1]+1&&a[i]+1==a[i+1]){
			puts("YES");
			return 0;
		}
	puts("NO");	
}