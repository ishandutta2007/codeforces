#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 49
int n,c[MAXN+10],r[MAXN+10],cr[2],re,ro;
bool vis[MAXN*MAXN+10];
int a[MAXN+10][MAXN+10];
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		puts("");
	}
}
void dfs(int pos){
	if(pos>n*n){
		if((cr[0]&1)&&(cr[1]&1)){
			print();
			exit(0);
		}
	}
	int x=(pos+n-1)/n,y=pos-(x-1)*n;
	if(ro){
		if(y==n)
			if(r[x])
				goto it;
		if(x==n)
			if(c[y])
				goto it;
		r[x]^=1;
		c[y]^=1;
		if(x==y)
			cr[0]^=1;
		if(x+y==n+1)
			cr[1]^=1;
		a[x][y]=1;
		ro--;
		dfs(pos+1);
		r[x]^=1;
		c[y]^=1;
		if(x==y)
			cr[0]^=1;
		if(x+y==n+1)
			cr[1]^=1;
		ro++;
	}
	it:;
	if(re){
		if(y==n){
			if(!r[x])
				return;
		}
		if(x==n)
			if(!c[y])
				return;
		re--;
		a[x][y]=0;
		dfs(pos+1);
		re++;
	}
}
void solve1(){
	int i,co=0,ce=0,j;
	for(i=1;i<=(n>>1);i++){
		for(j=1;j<=n;j++)
			printf("%d ",(++co)*2-1);
		puts("");
	}
	for(i=n/2+1;i<=n-2;i++){
		printf("%d ",(++co)*2-1);
		for(j=2;j<=n;j++)
			printf("%d ",++ce*2);
		puts("");
	}
	for(i=n-1;i<=n;i++){
		printf("%d ",++ce*2);printf("%d ",++ce*2);
		printf("%d ",(++co)*2-1);
		for(j=4;j<=n;j++)
			printf("%d ",++ce*2);
		puts("");
	}
}
void solve2(){
	int i,co=0,ce=0,j;
	for(i=1;i<(n>>1);i++){
		for(j=1;j<=n;j++)
			printf("%d ",(++co)*2-1);
		puts("");
	}
	for(i=1;i<=2;i++){
		for(j=1;j<=(n+1)/2;j++)
			printf("%d ",(++co)*2-1);
		for(j=1;j<=n/2;j++)
			printf("%d ",++ce*2);
		puts("");
	}
	for(i=1;i<=n/2;i++){
		printf("%d ",++co*2-1);
		for(j=2;j<=n;j++)
			printf("%d ",++ce*2);
		puts("");
	}
}
int main()
{
	scanf("%d",&n);
	if(n==1)
		puts("1");
	else if(n==3)
		printf("2 1 4\n3 5 7\n6 9 8\n");
	else{
		if((n>>1)&1)
			
			solve1();
		else
			solve2();
	}
}