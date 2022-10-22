#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,dx[8]={1,1,1,-1,-1,-1,0,0},dy[8]={1,0,-1,1,0,-1,1,-1},ok[1010][1010];
char a[1010][1010];
void work(int x,int y)
{
	for (int i=0;i<8;i++) if (a[x+dx[i]][y+dy[i]]!='#') return;
	for (int i=0;i<8;i++) ok[x+dx[i]][y+dy[i]]=1;
}
int main()
{
    cin>>n>>m;int i,j;
    for (i=1;i<=n;i++) scanf("%s",a[i]+1);
    for (i=2;i<n;i++) for (int j=2;j<m;j++) work(i,j);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (a[i][j]=='#' && ok[i][j]==0) {puts("NO");return 0;}
    puts("YES");
}