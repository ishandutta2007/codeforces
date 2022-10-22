#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, char> llc;

char tmp[20];
int n, m;
vector <llc> A, B;
vector <llc> C;
vector <int> Z;

int toInt(const string &s)
{
	stringstream ss(s);
	int num; ss >> num;
	return num;
}

llc Read()
{
	scanf("%s", tmp);
	string s = tmp;
	int p = s.find('-');
	return llc(toInt(s.substr(0, p)), s[p + 1]);
}

void Add(vector <llc> &S, const llc &p)
{
	if (!S.empty() && S.back().second == p.second) S.back().first += p.first;
	else S.push_back(p);
}

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		Add(A, Read());
	n = A.size();
	for (int i = 0; i < m; i++)
		Add(B, Read());
	m = B.size();
	if (m == 1) {
		ll res = 0;
		for (int i = 0; i < n; i++)
			if (A[i].first >= B[0].first && A[i].second == B[0].second)
				res += A[i].first - B[0].first + 1;
		printf("%I64d\n", res);
	} else if (m == 2) {
		ll res = 0;
		for (int i = 0; i + 1 < n; i++)
			if (A[i].first >= B[0].first && A[i].second == B[0].second &&
				A[i + 1].first >= B[1].first && A[i + 1].second == B[1].second)
				res++;
		printf("%I64d\n", res);
	} else {
		ll res = 0;
		for (int i = 1; i + 1 < m; i++)
			C.push_back(B[i]);
		C.push_back(llc(-1, '?'));
		for (int i = 0; i < n; i++)
			C.push_back(A[i]);
		Z = vector<int>(C.size(), 0);
		int l = -1, r = -1;
		for (int i = 1; i < C.size(); i++) {
			if (i <= r) Z[i] = min(Z[i - l], r - i);
			while (i + Z[i] < C.size() && C[i + Z[i]] == C[Z[i]]) Z[i]++;
			if (Z[i] == m - 2) {
				int ind = i - m, ind2 = i + m - 2 - (m - 1);
				if (ind >= 0 && A[ind].first >= B[0].first && A[ind].second == B[0].second &&
					ind2 < n && A[ind2].first >= B[m - 1].first && A[ind2].second == B[m - 1].second)
					res++;
			} 
			if (i + Z[i] - 1 > r) {
				r = i + Z[i] - 1; l = i;
			}
		}
		printf("%I64d\n", res);
	}
    return 0;
}