#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	int n, k;
	cin >> n >> k;
	map<int, vector <int> > R;
	vector <int> A(n);
	vector <int> color(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		R[A[i]].push_back(i);
	}
	map <int, vector <int> > :: iterator it;
	vector <int> W;
	int count = 0;
	for(it = R.begin(); it != R.end(); it++)
	{
		W = it -> second;
		if(W.size() > k)
		{
			cout << "NO";
			return 0;
		}
		else
		{
			for(int i = 0; i < W.size(); i++)
			{
				color[W[i]] = count+1;
				count++;
				count = count % k;
			}
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << color[i] << " ";
	}
	return 0;
}