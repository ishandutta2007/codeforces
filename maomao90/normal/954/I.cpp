#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;
#define MAX_FFT 262144
const double PI = acos(-1);

void fft(cd* arr, int n, bool inv) {
	if (n == 1) return;
	cd odd[n / 2], even[n / 2];
	for (int i = 0; i * 2 < n; i++) {
		even[i] = arr[i * 2];
		odd[i] = arr[i * 2 + 1];
	}
	fft(odd, n / 2, inv); fft(even, n / 2, inv);
	double theta = 2 * PI / n * (inv ? -1 : 1);
	cd w(1), wn(cos(theta), sin(theta));
	for (int i = 0; i * 2 < n; i++) {
		arr[i] = even[i] + w * odd[i];
		arr[i + n / 2] = even[i] - w * odd[i];
		if (inv) {
			arr[i] /= 2;
			arr[i + n / 2] /= 2;
		}
		w *= wn;
	}
}

int n, m;
char s[125005], t[125005];
cd ffts[10][MAX_FFT], fftt[10][MAX_FFT], pfft[MAX_FFT];

vector<int> adjList[125005][10];
bool visited[10];
void dfs(int u, vector<int>* cAdjList) {
	for (int v : cAdjList[u]) {
		if (visited[v]) continue;
		visited[v] = true;
		dfs(v, cAdjList);
	}
}

int main() {
	scanf(" %s", s);
	scanf(" %s", t);
	n = strlen(s), m = strlen(t);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < MAX_FFT; j++) ffts[i][j] = cd(0);
		for (int j = 0; j < n; j++) {
			if (s[j] == 'a' + i) {
				ffts[i][j] = cd(1);
			}
		}
		fft(ffts[i], MAX_FFT, false);
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < MAX_FFT; j++) fftt[i][j] = cd(0);
		for (int j = 0; j < m; j++) {
			if (t[j] == 'a' + i) {
				fftt[i][m - j - 1] = cd(1);
			}
		}
		fft(fftt[i], MAX_FFT, false);
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j) continue;
			for (int k = 0; k < MAX_FFT; k++) pfft[k] = ffts[i][k] * fftt[j][k];
			fft(pfft, MAX_FFT, true);
			for (int k = m - 1; k < MAX_FFT; k++) {
				if (k - m + 1 > n - m) break;
				if (round(pfft[k].real()) != 0) {
					adjList[k - m + 1][i].push_back(j);
					adjList[k - m + 1][j].push_back(i);
				}
			}
		}
	}
	for (int i = 0; i < n - m + 1; i++) {
		memset(visited, false, sizeof visited);
		int ans = 6;
		for (int j = 0; j < 6; j++) {
			if (!visited[j]) {
				visited[j] = true;
				dfs(j, adjList[i]);
				ans--;
			}
		}
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}