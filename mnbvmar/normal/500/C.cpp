#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 505,
          MaxM = 1005;


int bookWeight[MaxN];
int bookOrder[MaxM];
int N, M;
int firstUse[MaxN];
int bookFirst[MaxN];


void input(){
	scanf("%d%d", &N, &M);

	for(int i = 0; i < N; i++)
		scanf("%d", &bookWeight[i]);

	for(int j = 0; j < M; j++){
		scanf("%d", &bookOrder[j]);
		bookOrder[j]--;
	}
}

bool cmp(int i, int j){
	if(firstUse[i] != firstUse[j]) return firstUse[i] < firstUse[j];
	return i < j;
}

int main(){
	input();

	fill(firstUse, firstUse+N, MaxM);
	for(int j = M-1; j >= 0; j--){
		firstUse[bookOrder[j]] = j;
	}

	for(int i = 0; i < N; i++) bookFirst[i] = i;
	sort(bookFirst, bookFirst+N, cmp);


	int result = 0;
	for(int r = 0; r < M; r++){
		int nowBook = bookOrder[r];

		int where = -1;
		for(int i = 0; i < N; i++)
			if(bookFirst[i] == nowBook) where = i;

		for(int j = where-1; j >= 0; j--){
			result += bookWeight[bookFirst[j]];
			bookFirst[j+1] = bookFirst[j];
		}
		bookFirst[0] = nowBook;
	}

	printf("%d\n", result);
}