#include<bits/stdc++.h>
using namespace std;

signed main() {	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	int n, k;
  	cin >> n >> k;
  	vector <vector <char> > A(n, vector <char> (7));
  	for(int i = 0; i < n; i++)
  	{
  		for(int j = 0; j < 7; j++)
  		{
  			cin >> A[i][j];
		}
	}
	vector <string> ch(10);
	ch[0] = "1110111";
	ch[1] = "0010010";
	ch[2] = "1011101";
	ch[3] = "1011011";
	ch[4] = "0111010";
	ch[5] = "1101011";
	ch[6] = "1101111";
	ch[7] = "1010010";
	ch[8] = "1111111";
	ch[9] = "1111011";
	vector <vector <bool> > post(n, vector <bool> (k + 1));
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j < 10; j++)
		{
			bool flag = true;
			int cnt = 0;
			for(int d = 0; d < 7; d++)
			{
				if(A[i][d] == '1' && ch[j][d] == '0')
				{
					flag = false;
				}
				if(A[i][d] == '0' && ch[j][d] == '1')
				{
					cnt++;
				}
			}
			if(!flag)
			{
				continue;
			}
			for(int p = 0; p + cnt <= k; p++)
			{
				if(i == n - 1)
				{
					post[i][cnt] = true;
				}
				else if(post[i + 1][p])
				{
					post[i][p + cnt] = true;
				}
			}
		}
	}
	string ans = "";
	for(int i = 0; i < n; i++)
	{
		int maxt = -1;
		int cn = 0;
		for(int j = 0; j < 10; j++)
		{
			bool flag = true;
			int cnt = 0;
			for(int d = 0; d < 7; d++)
			{
				if(A[i][d] == '1' && ch[j][d] == '0')
				{
					flag = false;
				}
				if(A[i][d] == '0' && ch[j][d] == '1')
				{
					cnt++;
				}
			}
			if(!flag || cnt > k)
			{
				continue;
			}
			if(i == n - 1 && cnt == k || i != n - 1 && post[i + 1][k - cnt])
			{
				cn = cnt;
				maxt = j;
			}
		}
		if(maxt == -1)
		{
			cout << -1;
			return 0;
		}
		char t = '0' + maxt;
		ans += t;
		k -= cn;
	}
	cout << ans;
    return 0;
}