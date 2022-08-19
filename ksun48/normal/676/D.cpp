#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int x[4];
int y[4];
int stuff[1001][1001][4];
int dist[1001][1001][4];
char grid[1001][1001];
pair<pair<int,int>,pair<int,int> > states[6000000];
int s= 0;
int e = 0;
int main(){
	x[0] = -1;
	x[1] = 0;
	x[2] = 1;
	x[3] = 0;
	y[0] = 0;
	y[1] = 1;
	y[2] = 0;
	y[3] = -1;

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", grid[i]);
		for(int j = 0; j < m; j++){
			char a = grid[i][j];
			stuff[i][j][0] = stuff[i][j][1] = stuff[i][j][2] = stuff[i][j][3] = 0;
			if(a == '+'){
				stuff[i][j][0] = stuff[i][j][1] = stuff[i][j][2] = stuff[i][j][3] = 1;
			} else if(a == '-'){
				stuff[i][j][1] = stuff[i][j][3] = 1;
			} else if(a == '|'){
				stuff[i][j][0] = stuff[i][j][2] = 1;
			} else if(a == '^'){
				stuff[i][j][0] = 1;
			} else if(a == '>'){
				stuff[i][j][1] = 1;
			} else if(a == 'v'){
				stuff[i][j][2] = 1;
			} else if(a == '<'){
				stuff[i][j][3] = 1;
			} else if(a == 'L'){
				stuff[i][j][0] = stuff[i][j][1] = stuff[i][j][2] = 1;				
			} else if(a == 'R'){
				stuff[i][j][0] = stuff[i][j][3] = stuff[i][j][2] = 1;				
			} else if(a == 'U'){
				stuff[i][j][3] = stuff[i][j][1] = stuff[i][j][2] = 1;				
			} else if(a == 'D'){
				stuff[i][j][0] = stuff[i][j][1] = stuff[i][j][3] = 1;				
			}

		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 4; k++){
				dist[i][j][k] = 100000000;
			}
		}
	}
	int xt, yt, xm, ym;
	scanf("%d%d%d%d", &xt, &yt, &xm, &ym);
	xt--; yt--; xm--; ym--;
	states[e++] = make_pair(make_pair(0,0),make_pair(xt,yt));
	while(s < e){
		pair<pair<int,int>,pair<int,int> > d = states[s];
		s++;
		int k = d.first.first;
		int dd = d.first.second;
		int i = d.second.first;
		int j = d.second.second;
		if(dd >= dist[i][j][k]) continue;
		dist[i][j][k] = dd;
		//cout << i << " " << j << " " << k << " " << dd << endl;
		if(dd+1 < dist[i][j][(k+1)%4]){
			states[e++] = make_pair(make_pair((k+1)%4,dd+1),make_pair(i,j));
		}
		for(int z = 0; z < 4; z++){
			int ni = i + x[z];
			int nj = j + y[z];
			if(ni >= 0 && ni < n && nj >= 0 && nj < m){
				if(dd + 1 < dist[ni][nj][k]){
					if(stuff[i][j][(z+4-k)%4] && stuff[ni][nj][(z+6-k)%4]){
						states[e++] = make_pair(make_pair(k,dd+1),make_pair(ni,nj));
					}
				}
			}
		}
	}
	int ans = 1000000000;
	for(int k = 0; k < 4; k++){
		ans = min(ans, dist[xm][ym][k]);
	}
	if(ans >= 20000000){
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
}