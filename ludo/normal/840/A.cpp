#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pii> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].x;
		A[i].y = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i].x;
		B[i].y = i;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	vector<int> Bp(N);
	for (int i = 0; i < N; i++) {
		Bp[B[i].y] = i;
	}
/*
	for (int i = 0; i < N; i++) {
		cerr << Bp[i] << " ";
	}
	cerr << endl;
*/
	for (int i = 0; i < N; i++) {
		int j = Bp[i];
		// B[Bp[i]].y == i;
		cout << A[N - 1 - j].x << " ";
	}
	cout << endl;
}