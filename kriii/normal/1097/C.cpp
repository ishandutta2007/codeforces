#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> P,Q;
char S[500500];

int main()
{
	int N; scanf ("%d",&N); while (N--){
		scanf ("%s",S);
		int b = 0, m = 0;
		for (int i=0;S[i];i++){
			if (S[i] == '(') b++;
			else b--;
			if (m > b) m = b;
		}

		if (m == 0) P[b]++;
		else if (m == b) Q[-b]++;
	}

	int ans = P[0] / 2;
	for (auto &p : P) ans += min(p.second,Q[p.first]);

	printf ("%d\n",ans);

	return 0;
}