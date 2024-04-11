#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N, T;
vector<int> antsCount;
queue<pair<int,int>> moreThanFour;

const int Size = 1000;

int tarray[Size*2][Size*2];

void input(){
	scanf("%d%d", &N, &T);
}


const int dirr[4] = {1, 0, -1, 0},
          dirc[4] = {0, 1,  0,-1};

int main(){
	input();
	antsCount.push_back(N);

//	bool changed = true;
	tarray[Size][Size] = N;
	if(tarray[Size][Size] >= 4)
		moreThanFour.push(make_pair(Size,Size));

	int count = 0;
	while(!moreThanFour.empty()){
/*		changed = false;
		vector<int> newAntsCount(antsCount.size()+1);

		for(int i = 0; i < antsCount.size(); i++){
			if(antsCount[i] < 4){
				newAntsCount[i] = antsCount[i];
			} else {
				newAntsCount[i] = antsCount[i-1];
			}
		}*/

		int r, c;
		tie(r,c) = moreThanFour.front(); moreThanFour.pop();
		if(tarray[r][c] < 4) continue;

		count++;

		int num = tarray[r][c];
		tarray[r][c] %= 4;

		for(int d = 0; d < 4; d++){
			int nr = r + dirr[d],
				nc = c + dirc[d];

			bool good = (tarray[nr][nc] < 4);

			tarray[nr][nc] += num/4;

			if(good && tarray[nr][nc] >= 4)
				moreThanFour.push(make_pair(nr,nc));
		}
/*		array[r-1][c] += num/4;
		array[r][c-1] += num/4;
		array[r+1][c] += num/4;
		array[r][c+1] += num/4;*/
	}

/*	printf("%d\n", count);

	for(int i = Size-8; i <= Size+8; i++){
		for(int j = Size-8; j <= Size+8; j++)
			printf("%6d", tarray[i][j]);
		printf("\n");
	}*/

	while(T--){
		int x, y;
		scanf("%d%d", &x, &y);
		if(abs(x) >= Size || abs(y) >= Size){
			printf("0\n");
		} else {
			printf("%d\n", tarray[x+Size][y+Size]);
		}
	}
}