#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxN = 100005,
          LogMaxN = 18;

int record[MaxN];
int tnext[MaxN][LogMaxN];
int whereNext[MaxN][3];
int N;


void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &record[i]);
	}
}

void build_next(){
	int last[3] = {N, N, N};
	
	record[N] = -1;
	whereNext[N][0] = whereNext[N][1] = whereNext[N][2] = N;

	for(int i = N-1; i >= 0; i--){
		tnext[i][0] = last[record[i]];
		last[record[i]] = i;
//		printf("%d\n", last[record[i]]);

		for(int u = 0; u < 3; u++){
			if(record[i+1] == u)
				whereNext[i][u] = i+1;
			else
				whereNext[i][u] = whereNext[i+1][u];
		}
	}
	tnext[N][0] = N;
//	for(int i = 0; i <= N; i++)
//		printf("%d %d -> %d\n", i, 0, tnext[i][0]);

	for(int t = 1; t < LogMaxN; t++){
		for(int i = 0; i <= N; i++){
			tnext[i][t] = tnext[tnext[i][t-1]][t-1];
//			printf("%d %d -> %d\n", i, t, tnext[i][t]);
		}
	}
}

int jump(int from, int num){
	for(int i = LogMaxN-1; i >= 0; i--){
		if(num & (1<<i)){
//			printf("jmp from %d to %d by %d\n",
//					from, tnext[from][i], (1<<i));
			from = tnext[from][i];
		}
	}
	return from;
}

int get_range(int from, int num, int who){
	if(record[from] == who)
		return jump(from, num-1);
	else
		return jump(whereNext[from][who], num-1);
}


int check(int t){
	int ptr = 0;

	int result[3] = {0,0,0};
//	printf("%d\n", t);

	int numLast = -1;
	while(ptr < N){
		int whenFirstWins = get_range(ptr, t, 1),
		    whenSecondWins= get_range(ptr, t, 2);

//		printf("ptr=%d, 1=%d, 2=%d\n", ptr, whenFirstWins, whenSecondWins);
		if(whenFirstWins == N && whenSecondWins == N)
			return 0;

		if(whenFirstWins < whenSecondWins){
			ptr = whenFirstWins+1;
			result[1]++;
			numLast = 1;
		}else {
			ptr = whenSecondWins+1;
			result[2]++;
			numLast = 2;
		}
	}

	if(result[1] == result[2]) return 0;
	if(result[1] < result[2]){
		if(numLast != 2) return 0;
		return result[2];
	} else {
		if(numLast != 1) return 0;
		return result[1];
	}

//	return max(result[1], result[2]);
}


vector<pair<int,int>> solution;


int main(){
	input();

	build_next();
//	printf("Y\n");

	for(int t = 1; t <= N; t++){
		int result = check(t);
		if(result > 0) solution.emplace_back(result, t);
	}

	printf("%d\n", (int)solution.size());
	sort(solution.begin(), solution.end());

	for(pair<int,int> P: solution){
		printf("%d %d\n", P.first, P.second);
	}
}