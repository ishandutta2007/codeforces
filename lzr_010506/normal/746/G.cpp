#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int N, T, K;
int A[200010];
vector<int> L[200010], P[200010];

int main()
{
	cin >> N >> T >> K;
	for(int i = 0; i < T; i ++)
        cin >> A[i];

	for(int i = 0; i < T - 1; i ++)
		if(A[i + 1] < A[i])
			K -= A[i] - A[i + 1];

	K -= A[T - 1];

	if(K < 0)
	{
		cout << "-1\n";
		return 0;
	}

	int x = 2;
	for(int i = 0; i < T; i ++)
		for(int j = 0; j < A[i]; j++)
			P[i].pb(x), L[i].pb(x ++);

	int i = 0;
	while(i + 1 < T)
	{
		while(P[i].size() > L[i + 1].size()) P[i].pop_back();
		while(K && P[i].size() > 1) P[i].pop_back(), K --;
		i ++;
	}

	if(K != 0)
	{
		cout << "-1\n";
		return 0;
	}

	cout << N << "\n";
	for(int i = 0; i < L[0].size(); i ++)
		cout << "1 " << L[0][i] << "\n";
	for(int i = 0; i + 1 < T; i ++)
		for(int j = 0; j < L[i + 1].size(); j ++)
			cout << P[i][j % P[i].size()] << " " << L[i + 1][j] << "\n";
	return 0;
}