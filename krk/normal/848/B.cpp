#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, w, h;
vector <ii> A, B;
int P[Maxn];
ii res[Maxn];

int main()
{
	scanf("%d %d %d", &n, &w, &h);
	for (int i = 0; i < n; i++) {
		int g, p, t; scanf("%d %d %d", &g, &p, &t);
		P[i] = p;
		if (g == 2) A.push_back(ii(t - p, i));
		else if (g == 1) B.push_back(ii(t - p, i));
	}
	sort(A.begin(), A.end()); sort(B.begin(), B.end());
	int l = 0, r = 0;
	while (l < A.size() || r < B.size())
		if (l < A.size() && (r >= B.size() || A[l].first < B[r].first)) { res[A[l].second] = ii(w, P[A[l].second]); l++; }
		else if (r < B.size() && (l >= A.size() || B[r].first < A[l].first)) { res[B[r].second] = ii(P[B[r].second], h); r++; }
		else {
			vector <ii> tmp1, tmp2;
			int stl = l;
			while (l < A.size() && A[stl].first == A[l].first) {
				tmp1.push_back(ii(P[A[l].second], A[l].second));
				l++;
			}
			int str = r;
			while (r < B.size() && B[str].first == B[r].first) {
				tmp2.push_back(ii(P[B[r].second], B[r].second));
				r++;
			}
			sort(tmp1.begin(), tmp1.end()); sort(tmp2.begin(), tmp2.end());
			vector <ii> poses;
			for (int i = 0; i < tmp1.size(); i++)
				poses.push_back(ii(w, tmp1[i].first));
			for (int i = int(tmp2.size()) - 1; i >= 0; i--)
				poses.push_back(ii(tmp2[i].first, h));
			int pnt = 0;
			for (int i = int(tmp2.size()) - 1; i >= 0; i--)
				res[tmp2[i].second] = poses[pnt++];
			for (int i = 0; i < tmp1.size(); i++)
				res[tmp1[i].second] = poses[pnt++];
		}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}