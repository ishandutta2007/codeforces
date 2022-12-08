#include <stdio.h>
#include <bitset>
using namespace std;

char S[100100];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%s", S + 2);

		int d[2][2] = { 0, };
		for (int i = 2; S[i]; i++){
			int p[2][2] = { 0, };
			for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) p[j][k] = 1e9;
			for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++){
				int s = 0;
				if (j == 0 && S[i - 2] == S[i]) s = 1;
				if (k == 0 && S[i - 1] == S[i]) s = 1;
				for (int l = s; l < 2; l++){
					if (p[k][l] > d[j][k] + l){
						p[k][l] = d[j][k] + l;
					}
				}
			}
			for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) d[j][k] = p[j][k];
		}

		int ans = 1e9;
		for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) if (ans > d[j][k]) ans = d[j][k];
		printf ("%d\n", ans);
	}

	return 0;
}