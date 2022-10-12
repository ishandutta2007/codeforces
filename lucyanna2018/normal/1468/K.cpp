#include<bits/stdc++.h>
using namespace std;
#define ran 5555
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
char s[ran];
int n,x[ran],y[ran],d[ran];
bool chk(int X,int Y){
	int x = 0, y = 0;
	for(int i=1; i<=n; i++){
		x += dx[d[i]];
		y += dy[d[i]];
		if(x == X && y == Y){
			x -= dx[d[i]];
			y -= dy[d[i]];
		}
	}
	return x==0 && y==0;
}
int main(){
	int _;
	for(scanf("%d",&_); _--;){
		scanf("%s",s);
		n = strlen(s);
		x[0] = y[0] = 0;
		for(int i=1; i<=n; i++){
			switch(s[i-1]){
			case 'L': d[i] = 0; break;
			case 'R': d[i] = 1; break;
			case 'D': d[i] = 2; break;
			case 'U': d[i] = 3; break;
			}
			x[i] = x[i-1] + dx[d[i]];
			y[i] = y[i-1] + dy[d[i]];
		}
		bool sol = false;
		for(int i=0; i<=n && !sol; i++){
			if(x[i] == 0 && y[i] == 0)continue;
			int X = x[i], Y = y[i];
			if(chk(X, Y)){
				sol = true;
				printf("%d %d\n",X,Y);
			}
		}
		if(!sol)puts("0 0");
	}
	return 0;
}