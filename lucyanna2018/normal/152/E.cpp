#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int h[222],row,col,m;
int x[9],y[9];
int dp[1<<7][222];
priority_queue<pair<int,int> > q;
bool upd(int&x,int y){
	if(x==-1 || x>y){
		x=y;
		return true;
	}
	return false;
}
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
bool ff[111][111];
void output(int X,int Y,int mask){
	if((mask & -mask) == mask){
		int len = 0;
		while((1<<len) != mask)len++;
		if(x[len] == X && y[len] == Y){
			ff[X][Y] = true;
			return;
		}
	}else{
		int B = 0;
		do{
			if(dp[mask][X*col+Y] == dp[B][X*col+Y] + dp[mask-B][X*col+Y] - h[X*col+Y]){
				output(X,Y,B);
				output(X,Y,mask-B);
				return;
			}
		}while(B = (B-mask) & mask);
	}
	for(int i=0; i<4; i++){
		int x2 = X + dx[i], y2 = Y+dy[i];
		if(x2 >=0 && x2 < row && y2 >= 0 && y2 < col && dp[mask][X*col+Y] == dp[mask][x2*col+y2] + h[X*col+Y]){
			ff[X][Y] = true;
			output(x2, y2, mask);
			return;
		}
	}
}
int main(){
	for(int _=1; _--;){
		scanf("%d%d%d",&row,&col,&m);
		for(int i=0; i<row; i++)for(int j=0; j<col; j++)
			scanf("%d",&h[i*col+j]);
		for(int i=0; i<m; i++){
			scanf("%d%d",&x[i],&y[i]);
			--x[i];
			--y[i];
		}
		for(int mask = 1; mask < (1<<m); mask++){
			if((mask & -mask) == mask){
				int len = 0;
				while((1<<len) != mask)len++;
				for(int i=0; i<row; i++)for(int j=0; j<col; j++)
					dp[mask][i*col+j] = -1;
				dp[mask][x[len]*col+y[len]] = h[x[len]*col+y[len]];
				q.push(make_pair(-(h[x[len]*col+y[len]]),x[len]*col+y[len]));
			}else{
				int B = 0;
				memset(dp[mask],-1,sizeof(dp[mask]));
				do{
					if(B == 0 || B == mask)continue;
					for(int i=0; i<row; i++)for(int j=0; j<col; j++)
						upd(dp[mask][i*col+j], dp[B][i*col+j] + dp[mask-B][i*col+j] - h[i*col+j]);
				}while(B = (B-mask) & mask);
				for(int i=0; i<row; i++)for(int j=0; j<col; j++)
					q.push(make_pair(-dp[mask][i*col+j],i*col+j));
			}
			while(!q.empty()){
				int dis = -q.top().first;
				int x = q.top().second / col, y = q.top().second % col;
				q.pop();
				if(dis != dp[mask][x*col+y])continue;
				for(int i=0; i<4; i++){
					int x2 = x + dx[i], y2 = y + dy[i];
					if(x2 >=0 && x2 < row && y2 >= 0 && y2 < col && upd(dp[mask][x2*col+y2],dp[mask][x*col+y] + h[x2*col+y2]))
						q.push(make_pair(-dp[mask][x2*col+y2],x2*col+y2));
				}
			}
		}
		int out = -1, X, Y;
		for(int i=0; i<row; i++)for(int j=0; j<col; j++)
			if(upd(out,dp[(1<<m)-1][i*col+j]))
				X = i, Y = j;
		printf("%d\n",out);
		memset(ff,0,sizeof(ff));
		output(X, Y, (1<<m) - 1);
		for(int i=0; i<row; i++,puts(""))for(int j=0; j<col; j++)putchar(ff[i][j]?'X':'.');
	}
	return 0;
}