#include <cstdio>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

long long seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
unsigned int rx = seed, ry = seed >> 12, rz = seed >> 24;
inline unsigned int r()
{
	unsigned int t;
	rx ^= rx << 16; rx ^= rx >> 5; rx ^= rx << 1;
	t = rx; rx = ry; ry = rz; rz = t ^ rx ^ ry;
	return t;
}

unsigned long long H[100100];
int N,S[2][100100],E[2][100100]; pair<int, int> I[200200];

vector<unsigned long long> get(int k)
{
	vector<unsigned long long> res;
	int c = 0;
	for (int i=1;i<=N;i++){
		I[c++] = { S[k][i], i };
		I[c++] = { E[k][i] + 1, -i };
	}
	sort(I, I + c);
	bool rem = true;
	unsigned long long h = 0;
	for (int i = 0; i < c; i++){
		if (I[i].second > 0) rem = false;
		else if (!rem){
			res.push_back(h);
			rem = true;
		}
		h ^= H[abs(I[i].second)];
	}
	sort(res.begin(), res.end());
	return res;
}

int main()
{
	scanf ("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int k = 0; k < 2; k++) scanf ("%d %d", S[k] + i, E[k] + i);
	}

	for (int i = 1; i <= N; i++){
		H[i] = r();
		H[i] <<= 32;
		H[i] += r();
	}
	puts(get(0) == get(1) ? "YES" : "NO");
	return 0;
}