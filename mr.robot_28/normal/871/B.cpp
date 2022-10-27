#include<bits/stdc++.h>
using namespace std;

signed main() {
	int n;
	cin >> n;
	vector <vector <int> > matrix(n, vector <int> (n));
	for(int i = 0; i < n; i++)
	{
		cout << "? " << i << " " << i << endl;
		fflush(stdout);
		cin >> matrix[i][i];
	}
	for(int i = 0; i < n; i++)
	{
		cout << "? " << i << " " << (i + 1) % n << endl;
		fflush(stdout);
		cin >> matrix[i][(i + 1) % n];
	}
	vector <int> pref1(n), post1(n + 1), pref2(n), post2(n + 1);
	for(int i = 0; i < n; i++)
	{
		if(i == 0){
			pref1[i] = matrix[i][i];
			pref2[i] = matrix[i][(i + 1) % n];
		}
		else
		{
			pref1[i] = pref1[i - 1] ^ matrix[i][i];
			pref2[i] = pref2[i - 1] ^ matrix[i][(i + 1) % n];
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		post1[i] = post1[i + 1] ^ matrix[i][i];
		post2[i] = post2[i + 1] ^ matrix[i][(i + 1) % n];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < n - 1; j++)
		{
			int val = 0;
			if(i - j >= 0)
			{
				val = pref1[i];
			}
			else
			{
				val = pref1[i] ^ post1[(i - j + n) % n];
			}
			if(i - j > 0){
				val ^= pref1[i - j - 1];
			}
			if(i > 0){
				val ^= pref2[i - 1];
			}
			if(i - j - 1 >= 0)
			{
				val ^= pref2[i - j - 1];
			}
			if(i - j < 0)
			{
				val ^= post2[(i - j + n) % n];
			}
			matrix[i][(i - j + n) % n] = val;
		}
	}
	vector <int> ans;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		bool flag = true;
		vector <int> ind(n);
		vector <int> p(n, -1);
		for(int j = 0; j < n; j++)
		{
			if((matrix[0][j] ^ i) >= n)
			{
				flag = false;
				break;
			}
			p[matrix[0][j] ^ i] = j;
		}
		for(int j = 0; j < n; j++){
			if(p[j] == -1)
			{
				flag = false;
				break;
			}
			ind[p[j]] = j;
		}
		if(!flag)
		{
			continue;
		}
		for(int j = 0; j < n; j++)
		{
			if(matrix[j][j] != (p[j] ^ ind[j]))
			{
				flag = false;
			}
			if(matrix[j][(j + 1) % n] != (p[j] ^ ind[(j + 1) % n]))
			{
				flag = false;
			}
		}
		if(!flag)
		{
			continue;
		}
		if(ans.size() == 0)
		{
			for(int j = 0; j < n; j++)
			{
				ans.push_back(p[j]);
			}
		}
		cnt++;
	}
	cout << "!" << endl;
	cout << cnt << endl;
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	fflush(stdout);
	return 0;
}