#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxDim = 2005;
const int NumDirs = 4,
          DirX[NumDirs] = { 1,  0, -1, 0},
          DirY[NumDirs] = { 0, -1,  0, 1};
const char DirSgn[NumDirs+1] = ">^<v";

int N, M;
char data[MaxDim][MaxDim];
bool vis[MaxDim][MaxDim];

void input(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%s", data[i]);
}

inline bool is_inside(int r, int c){
	return (r >= 0 && r < N && c >= 0 && c < M);
}

queue<pair<int,int>> smallAdj;

int num_adj(int r, int c){
	int res = 0;
	for(int dir = 0; dir < 4; dir++){
		int nr = r + DirY[dir];
		int nc = c + DirX[dir];

		if(is_inside(nr,nc) && data[nr][nc] == '.') res++;
	}
	return res;
}

void set_pos(int r, int c, char val){
	data[r][c] = val;
	for(int dir = 0; dir < 4; dir++){
		int nr = r + DirY[dir],
		    nc = c + DirX[dir];

		if(is_inside(nr,nc) && data[nr][nc] == '.' && num_adj(nr,nc) == 1)
			smallAdj.emplace(nr,nc);
	}
}

void error(){
	printf("Not unique\n");
	exit(0);
}


int main(){
	input();

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			if(data[i][j] == '.'){
				int numAdj = num_adj(i, j);

				if(!numAdj) error();
				if(numAdj == 1) smallAdj.emplace(i, j);
			}
		}

	while(!smallAdj.empty()){
		int r, c;
		tie(r, c) = smallAdj.front(); smallAdj.pop();
		if(data[r][c] != '.') continue;

		bool ok = false;
		for(int dir = 0; dir < 4; dir++){
			int nr, nc;
			nr = r + DirY[dir];
	 		nc = c + DirX[dir];
			if(is_inside(nr,nc) && data[nr][nc] == '.'){
				set_pos(r, c, DirSgn[dir^2]);
				set_pos(nr, nc, DirSgn[dir]);
				ok = true;
			}	
		}
		if(!ok) error();
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(data[i][j] == '.') error();


	for(int i = 0; i < N; i++)
		printf("%s\n", data[i]);
	return 0;
}