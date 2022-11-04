#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int x,y,l,r;
};
int n,m,ml,mr,sx,sy,chk[2010][2010],cnt,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char s[2010][2010];
deque<node> q;
int main(){
	scanf("%d %d %d %d %d %d",&n,&m,&sx,&sy,&ml,&mr);
	q.push_back({sx,sy,ml,mr}),chk[sx][sy] = 1;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);

	while(!q.empty()){
		int x=q.front().x,y=q.front().y,l=q.front().l,r=q.front().r;
		q.pop_front();
		++cnt;

		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1 || yy<1 || xx>n || yy>m || chk[xx][yy] || s[xx][yy] == '*' || l-(i==2)<0 || r-(i==3)<0) continue;
			chk[xx][yy] = 1;
			if(i<2) q.push_front({xx,yy,l,r});
			else q.push_back({xx,yy,l-(i==2),r-(i==3)}); 
		}
	}
	printf("%d",cnt);
}