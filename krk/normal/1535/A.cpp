#include <bits/stdc++.h>
using namespace std;

int T;
int seq[4];

int main()
{
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 4; i++)
			scanf("%d", &seq[i]);
		int my[2] = {max(seq[0], seq[1]), max(seq[2], seq[3])};
		sort(my, my + 2);
		sort(seq, seq + 4);
		printf("%s\n", seq[3] == my[1] && seq[2] == my[0]? "YES": "NO");
	}
    return 0;
}