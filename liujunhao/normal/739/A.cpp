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
int n,m,ans;
void read(){
	Read(n),Read(m);
	int i,l,r;
	ans=n;
	for(i=1;i<=m;i++){
		Read(l),Read(r);
		ans=min(ans,r-l+1);
	}
}
void print(){
	int i;
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		printf("%d ",i%ans);
}
int main()
{
	read();
	print();
}