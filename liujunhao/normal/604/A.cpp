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
int n,a[10]={0,500,1000,1500,2000,2500},m[10],w[10],ans;
int main()
{
	int i;
	for(i=1;i<=5;i++)
		Read(m[i]);
	for(i=1;i<=5;i++)
		Read(w[i]);
	for(i=1;i<=5;i++)
		ans+=max(a[i]/10*3,1*a[i]-a[i]/250*m[i]-50*w[i]);
	Read(i);
	ans+=100*i;
	Read(i);
	ans-=50*i;
	printf("%d\n",ans);
}