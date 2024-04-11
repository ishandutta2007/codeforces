#include<cstdio>
#include<cstring>
using namespace std;
const int N=52;
int n,i,f[N][N][N][N];
char s[N][N];
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
int dfs(int lx,int rx,int ly,int ry){
	if(f[lx][rx][ly][ry]!=-1)return f[lx][rx][ly][ry];
	if(lx==rx&&ry==ly)return f[lx][rx][ly][ry]=s[lx][ly]=='#';
	f[lx][rx][ly][ry]=max(rx-lx,ry-ly)+1;
	for(int i=lx;i<rx;i++)f[lx][rx][ly][ry]=min(f[lx][rx][ly][ry],dfs(lx,i,ly,ry)+dfs(i+1,rx,ly,ry));
	for(int i=ly;i<ry;i++)f[lx][rx][ly][ry]=min(f[lx][rx][ly][ry],dfs(lx,rx,ly,i)+dfs(lx,rx,i+1,ry));
	return f[lx][rx][ly][ry];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(f,-1,sizeof(f));
	printf("%d",dfs(1,n,1,n));
}