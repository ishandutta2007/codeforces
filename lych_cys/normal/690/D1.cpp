#include<iostream>
#include<cstdio>
using namespace std;
int n,a[105][105]; char s[105]; int m,head,tail,h[500005][2];
void add(int x,int y){a[x][y]=0;h[++tail][0]=x;h[tail][1]=y;}
int main(){
	scanf("%d%d",&m,&n); int i,j;
	for (i=1; i<=m; i++){
		scanf("%s",s+1);
		for (j=1; j<=n; j++) if (s[j]!='.') a[i][j]=1;
	}int cnt=0;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++) if (a[i][j]){
			cnt++;head=0;tail=1;h[1][0]=i;h[1][1]=j;
			while (head<tail){
				int x=h[++head][0];int y=h[head][1];
				if (a[x-1][y]) add(x-1,y);
				if (a[x+1][y]) add(x+1,y);
				if (a[x][y-1]) add(x,y-1);
				if (a[x][y+1]) add(x,y+1);
			}
		}
	cout<<cnt<<endl;
	return 0;
}