#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > S;
int ans(int l, int r, int maxans)
{
	if(l == r)
	{
		return l;
	}
	vector <int> vec1;
	for(int i = l; i <= (r + l) / 2; i++)
	{
		for(int j = 0; j < S[i].size(); j++)
		{
			vec1.push_back(S[i][j]);
		}
	}
	cout << "? " << vec1.size() << " ";
	for(int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] + 1 << " ";
	}
	cout << endl;
	fflush(stdout);
	int a;
	cin >> a;
	if(a == maxans)
	{
		return ans(l, (r+ l) / 2, maxans);
	}
	return ans((r + l) / 2 + 1, r, maxans);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    S.resize(1000);
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	vector <int> used(n, -1);
    	for(int i = 0; i < k; i++)
    	{
    		int c;
    		cin >> c;
    		S[i].resize(c);
    		for(int j = 0; j < c; j++)
    		{
    			cin >> S[i][j];
    			S[i][j]--;
    			used[S[i][j]] = i;
			}
		}
		int maxans;
		cout << "? " << n << " ";
		for(int i = 1; i <= n; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		fflush(stdout);
		cin >> maxans;
		int j = ans(0, k - 1, maxans);
		int maxans1;
		vector <int> vec;
		for(int i = 0; i < n; i++)
		{
			if(used[i] != j)
			{
				vec.push_back(i+ 1);
			}
		}
		cout << "? " << vec.size() << " ";
		for(int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
		fflush(stdout);
		cin >> maxans1;
		cout << "! ";
		for(int i = 0; i < k; i++)
		{
			if(i != j)
			{
				cout << maxans << " ";
			}
			else
			{
				cout << maxans1 << " ";
			}
		}
		cout << endl;
		fflush(stdout);
		string s;
		cin >> s;
	}
    return 0;
}