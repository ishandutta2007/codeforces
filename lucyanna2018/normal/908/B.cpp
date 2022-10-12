#include<stdio.h>
#include<algorithm>
using namespace std;
int row,col,sx,sy;
char s[55][55],a[111];
int d[4];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int main(){
	scanf("%d%d",&row,&col);
	for(int i=0; i<row; i++){
		scanf("%s",s[i]);
		for(int j=0; j<col; j++)
			if(s[i][j] == 'S'){
				sx = i;
				sy = j;
				s[i][j] = '.';
			}
	}
	scanf("%s",a);
	for(int i=0; i<4; i++)d[i] = i;
	int res=0;
	do{
		int x = sx, y = sy;
		int ff = 0;
		for(int i=0; a[i]; i++){
			x += dx[d[a[i]-'0']];
			y += dy[d[a[i]-'0']];
			if(!(x >= 0 && x < row && y >= 0 && y < col)){
				ff = -1;
				break;
			}else
			if(s[x][y] == 'E'){
				ff = 1;
				break;
			}else
			if(s[x][y] == '#'){
				ff = -1;
				break;
			}
		}
		if(ff == 1)res++;
	}while(next_permutation(d,d+4));
	printf("%d\n",res);
	return 0;
}