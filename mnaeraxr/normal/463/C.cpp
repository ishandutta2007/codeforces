#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int64 val[4010][2];

int d0(int x, int y){
	int val = x - y;
	if (val < 0) return -val + 2001;
	else return val;
}

int d1(int x, int y){
	return x + y;
}

int64 M[2010][2010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j){
			cin >> M[i][j];
			val[d0(i,j)][0] += M[i][j];
			val[d1(i,j)][1] += M[i][j];
		}
	}

	pair<int64,pii> a1 = make_pair(0LL,make_pair(0,0));
	pair<int64,pii> a2 = make_pair(0LL,make_pair(0,1));

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			int64 v = val[d0(i,j)][0] + val[d1(i,j)][1] - M[i][j];
			pair<int64,pii> a = make_pair(v,make_pair(i,j));
			if ( (i + j) % 2 == 0)
				a1 = max(a1, a);
			else
				a2 = max(a2, a);
		}
	}

	cout << a1.first + a2.first << endl;
	cout << a1.second.first + 1 << " " << a1.second.second + 1 << " ";
	cout << a2.second.first + 1 << " " << a2.second.second + 1 << endl;

	return 0;
}