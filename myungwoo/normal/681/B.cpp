#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int A = 1234567, B = 123456, C = 1234;
int N;
bool V[B];

int main()
{
	cin >> N;
	int p = N / A, q = N / B;
	bool ans = 0;
	for (int i=0;i<=p;i++) for (int j=0;j<=q;j++){
		int remain = N - i*A - j*B;
		if (remain < 0) break;
		if (remain % C == 0) ans = 1;
	}
	puts(ans ? "YES" : "NO");
}