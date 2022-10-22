#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 4005;

int n;
int V[Maxn];
int D[Maxn];
int P[Maxn];
bool rem[Maxn];
vector <int> res;

void Decrease(int ind)
{
	rem[ind] = true;
	for (int i = ind + 1; i < n; i++) {
		if (P[i] >= 0) P[i] -= D[ind];
		if (P[i] < 0 && !rem[i]) Decrease(i);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &V[i], &D[i], &P[i]);
	for (int i = 0; i < n; i++) if (P[i] >= 0) {
		res.push_back(i + 1);
		for (int j = i + 1, d = V[i]; j < n && d > 0; j++, d--)
			if (rem[j]) d++;
			else P[j] -= d;
		for (int j = i + 1; j < n; j++)
			if (P[j] < 0 && !rem[j]) Decrease(j);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}