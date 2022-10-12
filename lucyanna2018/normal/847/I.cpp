#include<stdio.h>
int row,col,Q,inf;
void addto(int&x,int y){
	x+=y;
	if(x>inf)x=inf;
}
int res[255][255];
char s[255][255];
int vis[255][255],Z;
int q[255*255*3],op,cl;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
void bfs(int x,int y,int now){
	op=cl=0;
	q[op++] = x;
	q[op++] = y;
	q[op++] = now;
	vis[x][y] = Z;
	while(op!=cl){
		x = q[cl++];
		y = q[cl++];
		now = q[cl++];
		addto(res[x][y], now);
		if(now == 1)continue;
		for(int k=0; k<4; k++){
			int xx = x+dx[k],yy=y+dy[k];
			if(xx>=0 && xx<row && yy>=0 && yy<col && s[xx][yy]!='*' && vis[xx][yy]!=Z){
				vis[xx][yy] = Z;
				q[op++] = xx;
				q[op++] = yy;
				q[op++] = now/2;
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&row,&col,&Q,&inf);
	++inf;
	for(int i=0; i<row; i++){
		scanf("%s",s[i]);
	}
	for(int i=0; i<row; i++)for(int j=0; j<col; j++)
		if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
			Z++;
			bfs(i,j,(s[i][j]-'A'+1)*Q);
		}
	int out = 0;
	for(int i=0; i<row; i++)for(int j=0; j<col; j++)
		if(res[i][j] == inf)
			out++;
	printf("%d\n",out);
	return 0;
}