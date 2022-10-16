#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> board(8);
	for (int i = 0; i < 8; ++i)
		cin >> board[i];

	int A = 8, B = 8;
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if (board[i][j] == 'B'){
				bool ok = true;
				for (int k = i + 1; k < 8 && ok; ++k)
					if (board[k][j] != '.') ok = false;
				if (ok) B = min(B, 7 - i);
			}
			else if (board[i][j] == 'W'){
				bool ok = true;
				for (int k = 0; k < i && ok; ++k)
					if (board[k][j] != '.') ok = false;
				if (ok) A = min(A, i);
			}
		}
	}

	if (A <= B) cout << "A" << endl;
	else cout << "B" << endl;

	return 0;
}