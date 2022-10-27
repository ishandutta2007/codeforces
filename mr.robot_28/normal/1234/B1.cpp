#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	set <int> S;
	queue <int> K;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(K.size() < k && S.find(a) == S.end())
		{
			K.push(a);
			S.insert(a);
		}
		else
		{
			if(S.find(a) == S.end())
			{
				S.erase(K.front());
				K.pop();
				K.push(a);
				S.insert(a);
			}
		}
	}
	cout << S.size() << "\n";
	vector <int> P;
	while(K.size() > 0)
	{
		P.push_back(K.front());
		K.pop();
	}
	for(int i = P.size() - 1; i >= 0; i--)
	{
		cout << P[i] << " ";
	}
    return 0;
}