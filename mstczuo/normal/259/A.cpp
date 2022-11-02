# include <cstdio>
# define rep(i,n) for(int i=0;i<n;i++)
char a[10]; bool flag=true;
int main(){
	rep(i,8){scanf("%s",a);	rep(j,7)if(a[j]==a[j+1])flag=false;}
	puts(flag?"YES":"NO");
}