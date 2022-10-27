#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	int k = log2(n) + 1;
	vector <int> LOG2(n + 1), POW(k + 1);
	LOG2[1] = 0;
	for(int i= 2; i <= n; i++)
	{
		LOG2[i] = LOG2[i / 2] + 1;
	}
	POW[0] = 1;
	for(int i= 1; i <= k; i++)
	{
		POW[i] = POW[i - 1] * 2;
	}
	vector <vector <vector <int> > > left(k, vector <vector <int> > (k, vector <int> (n, 1e9)));
	vector <vector <vector <int> > > right(k, vector <vector <int> > (k, vector <int> (n, -1e9)));
	for(int p = 0; p < k; p ++)
	{
		for(int pw = 0; pw < k; pw++)
		{
			for(int i = 0; i + POW[pw] <= n; i++)
			{
			//	cout << p << " " << pw << " " << i << "\n";
					if(p == 0 && pw == 0)
					{
						left[pw][p][i] = i - A[i];
						right[pw][p][i] = i + A[i];
					}
					else if(p == 0)
					{
						left[pw][p][i] = min(left[pw - 1][p][i], left[pw - 1][p][i + POW[pw - 1]]);
						right[pw][p][i] = max(right[pw - 1][p][i], right[pw - 1][p][i + POW[pw - 1]]); 
					}
					else
					{
						int l1 = left[pw][p - 1][i];
						int r1 = right[pw][p - 1][i];
					//	cout << l1 << " " << r1 << "\n";
						if(r1 - l1 + 1 >= n)
						{
							left[pw][p][i] = -n;
							right[pw][p][i] = n - 1;
						}
						else
						{
							if(l1 < 0)
							{
								int ln1 = LOG2[-l1];
								int ln2 = LOG2[r1 + 1];	
								int k1 = min(left[ln1][p - 1][n + l1], left[ln1][p - 1][n - POW[ln1]]);
								left[pw][p][i] = - (n - k1);
								int k2 = min(left[ln2][p - 1][0], left[ln2][p - 1][r1 - POW[ln2] + 1]);
								left[pw][p][i] = min(left[pw][p][i], k2);
								k1 = max(right[ln1][p - 1][n + l1], right[ln1][p - 1][n - POW[ln1]]);
									right[pw][p][i] = k1 - n;
								k2 = max(right[ln2][p - 1][0], right[ln2][p - 1][r1 - POW[ln2] + 1]);
								right[pw][p][i] = max(right[pw][p][i], k2);
							}
							else if(r1 >= n)
							{
								int ln1 = LOG2[r1 - n + 1];
								int ln2 = LOG2[n - l1];
								int k1 = min(left[ln2][p - 1][l1], left[ln2][p - 1][n - POW[ln2]]);
								int k2 = min(left[ln1][p - 1][0], left[ln1][p - 1][r1 - n - POW[ln1] + 1]);
								left[pw][p][i] = min(k1, k2 + n);
								k1 = max(right[ln1][p - 1][0], right[ln1][p - 1][r1 - n -POW[ln1] + 1]);
								k2 = max(right[ln2][p - 1][l1], right[ln2][p - 1][n - POW[ln2]]);
								right[pw][p][i] = max(k1 + n, k2);
							}
							else
							{
								int ln = LOG2[r1 - l1 + 1];
								left[pw][p][i] = min(left[ln][p  - 1][l1], left[ln][p - 1][r1 - POW[ln] + 1]);
								right[pw][p][i] = max(right[ln][p - 1][l1], right[ln][p - 1][r1 - POW[ln] + 1]);
							}
						}
					}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		int l = i, r = i;
		int cnt = 0;
		for(int j = k - 1; j >= 0; j--)
		{
			int l1 = l, r1 = r;
			if(l < 0)
			{
				int ln1 = LOG2[-l];
				int ln2 = LOG2[r + 1];
				l1 = min(l1, - n + min(left[ln1][j][n + l], left[ln1][j][n - POW[ln1]]));
				l1 = min(l1, min(left[ln2][j][0], left[ln2][j][r - POW[ln2] + 1]));
				r1 = max(r1, max(right[ln1][j][n + l], right[ln1][j][n - POW[ln1]]) - n);
				r1 = max(r1, max(right[ln2][j][0], right[ln2][j][r - POW[ln2] + 1]));
				if(r1 - l1 + 1 < n)
				{
					l = l1;
					r = r1;
					cnt += POW[j];
				}
			}
			else if(r >= n)
			{
				int ln1 = LOG2[n - l];
				int ln2 = LOG2[r - n + 1];
				l1 = min(l1, min(left[ln1][j][l], left[ln1][j][n - POW[ln1]]));
				l1 = min(l1, n + min(left[ln2][j][0], left[ln2][j][r - n + 1 - POW[ln2]]));
				r1 = max(r1, max(right[ln1][j][l], right[ln1][j][n - POW[ln1]]));
				r1 = max(r1, n + max(right[ln2][j][0], right[ln2][j][r - n + 1 - POW[ln2]]));
				if(r1 - l1 + 1 < n)
				{
					l = l1;
					r = r1;
					cnt += POW[j];
				}
			}
			else
			{
				int ln = LOG2[r - l + 1];
				l1 = min(l1, min(left[ln][j][l], left[ln][j][r - (1 << ln) + 1]));
				r1 = max(r1, max(right[ln][j][l], right[ln][j][r - (1 << ln) + 1]));
				if(r1 - l1 + 1 < n)
				{
					l = l1;
					r = r1;
					cnt += POW[j];
				}
			}
		}
		cout << cnt + 1 << " ";
	}
	return 0;
}