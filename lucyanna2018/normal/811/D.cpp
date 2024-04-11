#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int X,Y,ex,ey,row,col;
char s[111][111];
int step[111][111],mv[111][111];
int q[111*111*2],op,cl;
void query(char c,int&x2,int&y2){
	printf("%c\n",c);
	fflush(stdout);
	scanf("%d%d",&x2,&y2);
}

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

bool all_empty(int sx,int sy,int ex,int ey){
	for(int i=sx; i<=ex; i++)
	for(int j=sy; j<=ey; j++)
		if(s[i][j] != '.')
			return false;
	return true;
}

void bfs(int sx,int sy,char L,char R,char U,char D){
	op=cl=0;
	q[op++] = ex;
	q[op++] = ey;
	memset(step,-1,sizeof(step));
	step[ex][ey] = 0;
	while(op != cl){
		int xx = q[cl++];
		int yy = q[cl++];
		if(xx == sx && yy == sy)break;
		for(int k=0; k<4; k++){
			int xx2 = xx + dx[k], yy2 = yy + dy[k];
			if(xx2 > 0 && xx2 <= row && yy2 > 0 && yy2 <= col && s[xx2][yy2] == '.' && step[xx2][yy2] == -1){
				step[xx2][yy2] = step[xx][yy]+1;
				mv[xx2][yy2] = k;
				q[op++] = xx2;
				q[op++] = yy2;
			}
		}
	}
	while(1){
		if(sx == ex && sy == ey)break;
		char o;
		if(mv[sx][sy] == 0)o = D;else
		if(mv[sx][sy] == 1)o = R;else
		if(mv[sx][sy] == 2)o = U;else
			o = L;
		query(o,sx,sy);
	}
}

void process(){

	X = Y = 1;if(X == ex && Y == ey)return;

	int x2,y2;
	if(ex == 1 && all_empty(1,1,ex,ey)){
		char c = 'R';
		query(c, x2, y2);
		if(X == x2 && Y == y2)
			c = 'L';
		else{
			X = x2;
			Y = y2;
		}

		while(1){
			if(X == ex && Y == ey)break;
			query(c, x2, y2);
			X = x2;
			Y = y2;
		}
		return;
	}

	if(ey == 1 && all_empty(1,1,ex,ey)){
		char c = 'D';
		query(c, x2, y2);
		if(X == x2 && Y == y2)
			c = 'U';
		else{
			X = x2;
			Y = y2;
		}

		while(1){
			if(X == ex && Y == ey)break;
			query(c, x2, y2);
			X = x2;
			Y = y2;
		}
		return;
	}

	char L = 'L', R = 'R', U = 'U', D = 'D';
	if(s[X][Y+1] == '.'){
		query(R, x2, y2);
		if(X == x2 && Y == y2)
			swap(L, R);
		else{
			X = x2;
			Y = y2;
		}

		int toy = -1;
		for(int j=1; j<=col; j++)
			if(s[X+1][j] == '.'){
				toy = j;
				break;
			}

		while(Y != toy){
			if(Y > toy){
				query(L, x2, y2);
				X = x2;
				Y = y2;
			}else{
				query(R, x2, y2);
				X = x2;
				Y = y2;
			}
		}

		query(D, x2, y2);
		if(X == x2 && Y == y2)
			swap(U, D);
		else{
			X = x2;
			Y = y2;
		}

		bfs(X,Y,L,R,U,D);
	}else{
		query(D, x2, y2);
		if(X == x2 && Y == y2)
			swap(U, D);
		else{
			X = x2;
			Y = y2;
		}

		int tox = -1;
		for(int i=1; i<=row; i++)
			if(s[i][Y+1] == '.'){
				tox = i;
				break;
			}

		while(X != tox){
			if(X > tox){
				query(U, x2, y2);
				X = x2;
				Y = y2;
			}else{
				query(D, x2, y2);
				X = x2;
				Y = y2;
			}
		}

		query(R, x2, y2);
		if(X == x2 && Y == y2)
			swap(L, R);
		else{
			X = x2;
			Y = y2;
		}

		bfs(X,Y,L,R,U,D);
	}
}
int main(){
	scanf("%d%d",&row,&col);
	for(int i=1; i<=row; i++){
		scanf("%s",s[i]+1);
		for(int j=1; j<=col; j++){
			if(s[i][j] == 'F'){
				ex = i;
				ey = j;
				s[i][j] = '.';
			}
		}
	}
	process();
	return 0;
}