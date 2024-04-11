#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		vector <vector <int> > A(n, vector <int> (m));
		int cnta = 0, cntb = 0;
		for(int i = 0; i < n; i++){
			bool flag = false;
			for(int j = 0; j < m; j++)
			{
				cin >> A[i][j];
				flag = flag | A[i][j];
			}
			cnta += flag;
		}
		cnta = n - cnta;
		for(int j = 0; j < m; j++)
		{
			bool flag = false;
			for(int i = 0; i < n; i++)
			{
				flag = flag | A[i][j];
			}
			cntb += flag;
		}
		cntb = m - cntb;
		if(min(cnta, cntb) % 2 == 0)
		{
			cout << "Vivek\n";
		}
		else
		{
			cout << "Ashish\n";
		}
    }
	return 0;
}