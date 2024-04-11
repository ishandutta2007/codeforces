#include <bits/stdc++.h>
using namespace std;

int S, E, T, F;
int D[101][2001];

int main()
{
	cin >> S >> E >> T >> F;
	for (int i=1;i<=T;i++) for (int j=0;j<2001;j++) D[i][j] = -2e9;
	D[1][S] = S;
	for (int i=1;i<T;i++){
		for (int j=0;j<2001;j++){
			for (int k=-F;k<=F;k++) if (j+k >= 0){
				D[i+1][j+k] = max(D[i+1][j+k], D[i][j]+j+k);
			}
		}
	}
	printf("%d\n", D[T][E]);
}