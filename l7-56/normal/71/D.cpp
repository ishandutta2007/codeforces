#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 20;
int num(char ch){
	if(isdigit(ch)) return ch - 48;
	switch(ch){
		case 'A' : return 1;
		case 'T' : return 10;
		case 'J' : return 11;
		case 'Q' : return 12;
		case 'K' : return 13;
	}
	return 0;
}

int col(char ch){
	switch(ch){
		case 'C' : return 1;
		case 'D' : return 2;
		case 'H' : return 3;
		case 'S' : return 4;
	}
	return 0;
}

int n,m,mp[maxn][maxn],J[3][3];
bool f[20][10];
bool ck(int p, int q){
	if(p + 2 > n || q + 2 > m) return 0;
	int ns[9],cs[9];
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			ns[i * 3 + j] = mp[p + i][q + j] / 10,
			cs[i * 3 + j] = mp[p + i][q + j] % 10;
	bool flag = 1;
	for(int i = 0; i < 9 && flag; ++i)
		if(cs[i] != cs[0]) flag = 0;
	if(flag) return 1;
	flag = 1;
	for(int i = 0; i < 9 && flag; ++i)
		for(int j = i + 1; j < 9 && flag; ++j)
			if(ns[i] == ns[j]) flag = 0;
	return flag;
}

char mun(int x){
	if(x <= 9 && x >= 2) return x + 48;
	switch(x){
		case 1 : return 'A';
		case 10 : return 'T';
		case 11 : return 'J';
		case 12 : return 'Q';
		case 13 : return 'K';
	}
	return '?';
}

char loc(int x){
	switch(x){
		case 1 : return 'C';
		case 2 : return 'D';
		case 3 : return 'H';
		case 4 : return 'S';
	}
	return '?';
}

bool fl;
void dfs(int x){
	if(x == 3) {
//		printf("%d %d\n", J[1][2], J[2][2]);
//		for(int i = 1; i <= n; ++i){
//			for(int j = 1; j <= m; ++j)
//				printf("%d ", mp[i][j]);
//			printf("\n");
//		}
//		printf("%d %d\n", ck(1,1), ck(2,4));
//		system("pause");
		int p[3][3];
		bool flag = 0;
		for(p[1][1] = 1; p[1][1] <= n && !flag; ++p[1][1])
			for(p[1][2] = 1; p[1][2] <= m && !flag; ++p[1][2])
				for(p[2][1] = 1; p[2][1] <= n && !flag; ++p[2][1])
					for(p[2][2] = 1; p[2][2] <= m && !flag; ++p[2][2]){
						if((abs(p[1][1] - p[2][1]) >= 3 || abs(p[1][2] - p[2][2]) >= 3) && ck(p[1][1], p[1][2]) && ck(p[2][1], p[2][2]))
							flag = 1;
					}
						
		if(!flag) return;
		fl = 1;
		printf("Solution exists.\n");
		if(J[1][0]){
			if(J[2][0]) printf("Replace J1 with %c%c and J2 with %c%c.\n", mun(J[1][2] / 10), loc(J[1][2] % 10), mun(J[2][2] / 10), loc(J[2][2] % 10));
			else printf("Replace J1 with %c%c.\n", mun(J[1][2] / 10), loc(J[1][2] % 10));
		}
		else if(J[2][0]) printf("Replace J2 with %c%c.\n", mun(J[2][2] / 10), loc(J[2][2] % 10));
		else printf("There are no jokers.\n");
		printf("Put the first square to (%d, %d).\n", --p[1][1], --p[1][2]);
		printf("Put the second square to (%d, %d).\n", --p[2][1], --p[2][2]);
		return;
	}
	if(J[x][0] == 0) dfs(x + 1);
	else {
		for(int i = 1; i <= 13; ++i)
			for(int j = 1; j <= 4; ++j)
				if(!f[i][j]) {
//					printf("i: %d j: %d %d\n", i, j, J[1][2]);
					mp[J[x][0]][J[x][1]] = J[x][2] = i * 10 + j; f[i][j] = 1;
					dfs(x + 1);
					if(fl) return;
					mp[J[x][0]][J[x][1]] = J[x][2] = f[i][j] = 0;
				}
	}
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			string s; cin >> s;
			if(s == "J1") J[1][0] = i, J[1][1] = j;
			else if(s == "J2") J[2][0] = i, J[2][1] = j;
			else mp[i][j] = num(s[0]) * 10 + col(s[1]), f[num(s[0])][col(s[1])] = 1;
		}
	dfs(1);
	if(!fl) printf("No solution.\n");
	return 0;
}