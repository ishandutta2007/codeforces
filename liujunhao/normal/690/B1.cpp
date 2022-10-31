#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 50
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
int n,a[MAXN+10][MAXN+10];
char s[MAXN+10][MAXN+10];
int vis[MAXN+10][MAXN+10];
int main()
{
	Read(n);
	int i,j,ans=0,k,l;
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(s[i][j]=='4')
			vis[i][j]=1;
		}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			if(vis[i][j]){
				for(k=j;k<=n;k++)
					if(!vis[i][k])
						break;
				int r=k-1;
				for(k=i;k<=n;k++)
					if(!vis[k][j])
						break;
				int b=k-1;
				for(k=i;k<=b;k++)
					for(l=j;l<=r;l++)
						if(vis[k][l])
							vis[k][l]=0;
						else{
							puts("No");
							return 0;
						}
				ans++;
			}
	}
	if(ans!=1)
		puts("No");
	else{
		memset(vis,0,sizeof vis);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(s[i][j]=='4')
					vis[i][j]=vis[i][j+1]=vis[i+1][j]=vis[i+1][j+1]=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				a[i][j]=vis[i][j]+vis[i+1][j]+vis[i][j+1]+vis[i+1][j+1];
				if(a[i][j]!=s[i][j]-'0'){
					puts("No");
					return 0;
				}
			}
		puts("Yes");
	}
}