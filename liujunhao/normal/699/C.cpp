#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 100
int n,f[MAXN+10][3],a[MAXN+10]; //0 1 2
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
	for(i=1;i<=n;i++){
		Read(a[i]);
	}
	memset(f,0x7f,sizeof f);
	f[0][0]=0;
	for(i=1;i<=n;i++){
		f[i][0]=min(min(f[i-1][0],f[i-1][1]),f[i-1][2])+1;
		if(a[i]==1){
			f[i][1]=min(f[i-1][0],f[i-1][2]);
		}
		else if(a[i]==2){
			f[i][2]=min(f[i-1][0],f[i-1][1]);
		}
		else if(a[i]==3){
			f[i][2]=min(f[i-1][0],f[i-1][1]);
			f[i][1]=min(f[i-1][0],f[i-1][2]);
		}
	}
	printf("%d\n",min(min(f[n][0],f[n][1]),f[n][2]));
}