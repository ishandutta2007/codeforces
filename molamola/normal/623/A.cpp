#include<stdio.h>

int n, m;
int E[505][505];
char ans[510];
int chk[510];
int ok = 1;

void dfs(int x,int w){
	chk[x] = w+1;
	ans[x] = (w == 0 ? 'a' : 'c');
	for(int i=1;i<=n;i++){
		if(!E[x][i] && !chk[i])dfs(i, w^1);
		if(!E[x][i] && chk[i] == chk[x])ok = 0;
	}
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
    	int x, y;
    	scanf("%d%d", &x, &y);
    	E[x][y] = E[y][x] = 1;
    }
    for(int i=1;i<=n;i++){
    	E[i][i] = 1;
    	int c = 0;
    	for(int j=1;j<=n;j++)if(E[i][j] == 0)c = 1;
    	if(c == 0)ans[i] = 'b';
    }
    for(int i=1;i<=n;i++){
    	if(ans[i] != 'b' && !chk[i])dfs(i, 0);
    }
    for(int i=1;i<=n;i++){
    	if(chk[i] == 1){
    		for(int j=1;j<=n;j++){
    			if(chk[j] == 2){
    				if(E[i][j] == 1)ok = 0;
    			}
    		}
    	}
    }
    if(ok == 0)printf("No");
    else{
    	puts("Yes");
    	puts(ans+1);
    }
    return 0;
}