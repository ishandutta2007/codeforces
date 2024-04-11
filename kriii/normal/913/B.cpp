#include <stdio.h>
#include <vector>
using namespace std;

vector<int> g[1010];
int N;

int main()
{
	scanf ("%d",&N);
	for (int i=2;i<=N;i++){
		int p; scanf ("%d",&p);
		g[p].push_back(i);
	}

	bool gd = 1;
	for (int i=1;i<=N;i++) if (!g[i].empty()){
		int ch = 0;
		for (auto &y : g[i]) if (g[y].empty()) ch++;
		if (ch < 3) gd = 0;
	}
	puts(gd?"Yes":"No");

	return 0;
}