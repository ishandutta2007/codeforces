#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bitset <4096> q[N];
vector <pair <int, int> > v[N];
int n, k, qr, b[20][N];
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n >> k >> qr;
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++){
			cin >> b[i][j];
			v[j].push_back(make_pair(b[i][j], i));
		}
		for(int j = 0; j < 4096; j++)
		{
			q[i][j] = (j >> i) & 1;
		}
	}
	for(int j = 0; j < n; j++)
	{
		sort(v[j].begin(), v[j].end());
	}
	int it = k;
	for(int i = 0; i < qr; i++)
	{
		int type, p1, p2;
		cin >> type >> p1 >> p2;
		p1--;
		p2--;
		if(type == 1)
		{
			q[it++] = q[p1] | q[p2];
		}
		else if(type == 2)
		{
			q[it++] = q[p1] & q[p2];
		}
		else
		{
			int s = 0;
			for(int j = k - 1; j >= 0; j--)
			{
				s |= (1 << v[p2][j].second);
				if(q[p1][s]){
					cout << v[p2][j].first << "\n";
					break;
				}
			}
		}
	}
	return 0;
}