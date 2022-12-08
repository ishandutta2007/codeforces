#include <stdio.h>
#include <vector>
using namespace std;

int N, C; bool O[1010];

int main()
{
	scanf ("%d", &N);
	if (N > 3){
		if (N <= 5){
			puts("2 1 3"); fflush(stdout);
			scanf ("%*d");
		}
		else{
			vector<int> cand;

			C = 1;
			while (C * C <= N) C++; C--;

			for (int i = 0; i < N; i++) if (i % C) cand.push_back(i + 1);

			for (int k = 0; k < 10000 && cand.size() >= C; k++){
				printf ("%d", C);
				for (int i = 0; i < C; i++){
					printf (" %d", cand.back());
					O[cand.back()] = 1;
					cand.pop_back();
				}
				puts("");
				fflush(stdout);
				int p; scanf ("%d", &p);

				for (int k = 0; k < C; k++){
					int z = ((p - 1) + k) % N + 1;
					if (O[z]){
						cand.push_back(z);
						O[z] = false;
					}
				}
			}

			if (!cand.empty()){
				printf ("%d", cand.size());
				while (!cand.empty()){
					printf (" %d", cand.back());
					cand.pop_back();
				}
				puts("");
				fflush(stdout);
				scanf ("%*d");
			}
		}
	}

	puts("0");
	fflush(stdout);
	return 0;
}