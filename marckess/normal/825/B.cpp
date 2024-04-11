#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))


char v[12][12];

bool ver(int x, int y) {
	if (v[x][y] != '.')
		return false;

	int arr = 0, aba = 0;
	for (int i = x + 1; i < 10 && v[i][y] == 'X'; i++)
		arr++;

	for (int i = x - 1; i >= 0 && v[i][y] == 'X'; i--)
		aba++;

	return arr + aba >= 4;
}

bool hor(int x, int y) {
	if (v[x][y] != '.')
		return false;
	
	int izq = 0, der = 0;
	for (int i = y + 1; i < 10 && v[x][i] == 'X'; i++)
		der++;

	for (int i = y - 1; i >= 0 && v[x][i] == 'X'; i--)
		izq++;

	return izq + der >= 4;
}

bool diag(int x, int y) {
	if (v[x][y] != '.')
		return false;

	int ai = 0, ad = 0;
	for (int i = x + 1, j = y + 1; i < 10 && j < 10 && v[i][j] == 'X'; i++, j++)
		ad++;
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0 && v[i][j] == 'X'; i--, j--)
		ai++;
	if (ad + ai >= 4)
		return true;

	ai = 0, ad = 0;
	for (int i = x + 1, j = y - 1; i < 10 && j >= 0 && v[i][j] == 'X'; i++, j--)
		ad++;
	for (int i = x - 1, j = y + 1; i >= 0 && j < 10 && v[i][j] == 'X'; i--, j++)
		ai++;
	return ai + ad >= 4;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 10; i++)
		cin >> v[i];

	for (int i = 0; i < 10; i++) 
		for (int j = 0; j < 10; j++)
			if (ver(i, j) || hor(i, j) || diag(i, j)) {
				cout << "YES" << endl;
				return 0;
			}

	cout << "NO" << endl;

	return 0;
}