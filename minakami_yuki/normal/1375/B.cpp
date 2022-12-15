#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int N=310;
int n,k,m;
int a[N][N];
int main(){
	int T;scanf("%d",&T);bool flag;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&a[i][j]);
		flag=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				if((i==1||i==n)&&(j==1||j==m)){
					if(a[i][j]>2) flag=0;
					a[i][j]=2;
				}
				else if(i==1||i==n||j==1||j==m){
					if(a[i][j]>3) flag=0;
					a[i][j]=3;
				}
				else {
					if(a[i][j]>4) flag=0;
					a[i][j]=4;
				}
			}
		if(!flag) printf("NO\n");
		else {
			printf("YES\n");
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					printf("%d ",a[i][j]);
				}
				puts("");
			}
		}
	} 
	return 0;
}