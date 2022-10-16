#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char strs[1005][1005];
int N, M;

void input(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%s", strs[i]);
}

set<int> stops;


int main(){
	input();

	stops.insert(N);

	int numRemove = 0;

	for(int c = 0; c < M; c++){
		char previous = 0;
		bool ok = true;

		for(int r = 0; r < N; r++){
			if(strs[r][c] < previous){
				ok = false;
				break;
			}
			previous = strs[r][c];
			if(stops.find(r) != stops.end()) previous = 0;
		}

		if(!ok){
			numRemove++;
		} else {
			for(int r = 0; r < N-1; r++){
				if(strs[r][c] < strs[r+1][c])
					stops.insert(r);
			}
		}
	}

	printf("%d\n", numRemove);
}