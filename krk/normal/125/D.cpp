#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 30005;

int n;
int a[Maxn];
bool tk[Maxn];
vector <int> seq1, seq2;
bool taken;

void Print(const vector <int> &V)
{
	for (int i = 0; i < V.size(); i++)
		printf("%d%c", V[i], i + 1 < V.size()? ' ': '\n');
}

bool Check(const vector <int> &V)
{
	if (V.empty()) return false;
	if (V.size() <= 2) return true;
	int d = V[1] - V[0];
	for (int i = 2; i < V.size(); i++)
		if (d != V[i] - V[i - 1]) return false;
	return true;
}

bool Get(int l, int r)
{
	seq1.clear(); seq2.clear();
	int nd = a[l], delt = a[r] - a[l];
	int ind = -1;
	for (int i = 0; i < n; i++)
		if (nd == a[i]) { seq1.push_back(a[i]); ind = i; tk[i] = true; nd += delt; }
		else tk[i] = false;
	for (int i = 0; i < n; i++)
		if (!tk[i]) seq2.push_back(a[i]);
	if (Check(seq2)) { Print(seq1); Print(seq2); return true; }
	tk[ind] = false; seq1.pop_back();
	seq2.clear();
	for (int i = 0; i < n; i++)
		if (!tk[i]) seq2.push_back(a[i]);
	if (Check(seq2)) { Print(seq1); Print(seq2); return true; }
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (n == 2) printf("%d\n%d\n", a[0], a[1]);
	else if (!Get(0, 1) && !Get(0, 2) && !Get(1, 2)) printf("No solution\n");
	return 0;
}