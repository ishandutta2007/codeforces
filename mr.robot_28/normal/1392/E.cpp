#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  //  ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    //cout.tie(NULL);
    int n;
    cin >> n;
    vector <vector <int> > a(n, vector <int> (n, 0));
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++)
    	{
    		if((j - i + n) & 2LL)
    		{
    			a[i][j] = (1LL << (i + j));
			}
			else
			{
				a[i][j] = 0;
			}
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	fflush(stdout);
	int q;
	cin >> q;
	while(q--)
	{
		long long sum;
		cin >> sum;
		int stx = 0, sty = 0;
		cout << 1 << " " << 1 <<  " ";
		for(int i = 0; i < 2 * n - 2; i++)
		{
			long long num = (sum & (1LL << (stx + sty + 1)));
			if(stx + 1 < n && a[stx + 1][sty] == num)
			{
				stx++;
			}
			else
			{
				sty++;
			}
			cout << stx + 1 << " " << sty + 1 << " ";
		}
		cout << endl;
		fflush(stdout);
	}
    return 0;
}