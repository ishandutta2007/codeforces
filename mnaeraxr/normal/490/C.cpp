#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 1000100;

char bn[maxn];
int64 p1[maxn], p2[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> bn;
	int len = strlen(bn);
	int64 a, b;
	cin >> a >> b;

	for (int i = 0; i < len; ++i)
		p1[i] = ((i ? p1[i - 1] : 0) * 10 + (bn[i] - '0')) % a;

	int64 pw = 1;
	for (int i = len - 1; i >= 0; --i){
		p2[i] = (pw * (bn[i] - '0') + p2[i + 1] ) % b;
		pw = pw * 10 % b;
	}

	for (int i = 0; i + 1 < len; ++i){
		if (p1[i] == 0 && p2[i + 1] == 0 && bn[i + 1] != '0'){
			cout << "YES" << endl;
			for (int j = 0; j <= i; ++j)
				cout << bn[j];
			cout << endl;
			for (int j = i + 1; j < len; ++j)
				cout << bn[j];
			cout << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}