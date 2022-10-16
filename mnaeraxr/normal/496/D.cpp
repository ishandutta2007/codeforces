#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int maxn = 100100;

int v[maxn];
int d[2][maxn];
int l[2][maxn];
int tot[2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	l[0][0] = l[0][1] = 0;
	for (int i = 1; i <= n; ++i){
		cin >> v[i];
		--v[i];
		d[v[i]][++tot[v[i]]] = i;
		l[0][i] = tot[0];
		l[1][i] = tot[1];
	}

	vector<pii> ans;

	for (int t = 1; t <= n; ++t){
		int s0 = 0, s1 = 0;
		int p = 0;
		bool ok = true;
		while (p < n){
			int t0 = l[0][p], t1 = l[1][p];

			if (t0 + t > tot[0]){
				if (t1 + t > tot[1]){
					ok = false;
					p = n;
				}
				else{
					p = d[1][t1 + t];
					s1++;
				}
			}
			else{
				if (t1 + t > tot[1]){
					p = d[0][t0 + t];
					s0++;
				}
				else{
					if (d[0][t0 + t] < d[1][t1 + t]){
						p = d[0][t0 + t];
						s0++;
					}
					else{
						p = d[1][t1 + t];
						s1++;
					}
				}
			}
		}
		if (ok && v[n] == 1 && s1 > s0)
			ans.push_back(pii(s1, t));
		else if (ok && v[n] == 0 && s0 > s1)
			ans.push_back(pii(s0, t));
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto val : ans)
		cout << val.first << " " << val.second << endl;

	return 0;
}