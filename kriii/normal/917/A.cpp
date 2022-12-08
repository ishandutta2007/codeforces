#include <stdio.h>
#include <vector>
using namespace std;

char S[5050];
int L; bool f[5050][5050],g[5050][5050];

int main()
{
	scanf ("%s",S);
	while (S[L]) L++;

	for (int s=0;s<L;s++){
		int b = 0, v = 1;
		for (int e=s;e<L;e++){
			if (S[e] == ')') b--;
			else b++;
			if (b < 0) v = 0;
			f[s][e] = v;
		}
	}

	for (int e=L-1;e>=0;e--){
		int b = 0, v = 1;
		for (int s=e;s>=0;s--){
			if (S[s] == '(') b--;
			else b++;
			if (b < 0) v = 0;
			g[s][e] = v;
		}
	}

	int ans = 0;
	for (int s=0;s<L;s++){
		int op = 0, cl = 0;
		vector<int> pos;
		for (int e=s;e<L;e++){
			if (S[e] == '?') pos.push_back(e);
			else if (S[e] == '(') op++;
			else cl++;

			if ((e - s) % 2){
				int h = (e - s + 1) / 2;
				if (op <= h && cl <= h){
					if (op == h){
						if (g[s][e]) ans++;
					}
					else if (cl == h){
						if (f[s][e]) ans++;
					}
					else{
						if (f[s][pos[h-op-1]] && g[pos[h-op-1]+1][e]) ans++;
					}
				}
			}
		}
	}

	printf ("%d\n",ans);

	return 0;
}