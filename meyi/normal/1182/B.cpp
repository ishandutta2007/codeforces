#include<cstdio>
char a[501][501];
int h,w,s,t=5;
int main(){
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;++i){
		scanf("%s",*(a+i)+1);
		for(int j=1;j<=w;++j)a[i][j]=='*'&&++s;
	}
	if(s<5)return puts("NO"),0;
	for(int i=1;i<=h;++i)
		for(int j=1;j<=w;++j)
			if(a[i-1][j]=='*'&&a[i][j-1]=='*'&&a[i][j]=='*'&&a[i][j+1]=='*'&&a[i+1][j]=='*'){
				for(int k=2;i>k&&a[i-k][j]=='*';++k,++t);
				for(int k=2;j>k&&a[i][j-k]=='*';++k,++t);
				for(int k=2;i+k<=h&&a[i+k][j]=='*';++k,++t);
				for(int k=2;j+k<=w&&a[i][j+k]=='*';++k,++t);
				return puts(s==t?"YES":"NO"),0;
			}
	puts("NO");
	return 0;
}