#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

const int MAXN = 200100;

char A[2][MAXN];

void fix(int idx, int b, int e){
	if ( (e - b) & 1) return;
	int mid = (e + b) >> 1;
	fix(idx, b, mid);
	fix(idx, mid, e);
	bool sw = false;

	for (int i = 0; i + b < mid && !sw; ++i){
		if (A[idx][i + b] != A[idx][i + mid]){
			sw = A[idx][i + mid] < A[idx][i + b];
			break;
		}
	}

	if (sw){
		for (int i = 0; i + b < mid; ++i)
			swap(A[idx][i + b], A[idx][i + mid]);
	}
}

int main()
{
	scanf("%s", A[0]);
	scanf("%s", A[1]);

	int len = strlen(A[0]);

	fix(0, 0, len);
	fix(1, 0, len);

	bool ok = true;

	// for (int j = 0; j < 2; ++j){
	// 	for (int i = 0; i < len; ++i)
	// 		putchar(A[i][j]);
	// 	putchar('\n');
	// }

	for (int i = 0; i < len && ok; ++i){
		if (A[0][i] != A[1][i]) ok = false;
	}

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;


	return 0;
}