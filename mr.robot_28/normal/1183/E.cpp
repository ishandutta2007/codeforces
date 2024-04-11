#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	set <string> K;
	queue <string> Q;
	Q.push(s);
	K.insert(s);
	if(k == 1)
	{
		cout << 0;
		return 0;
	}
	int sum = 0;
	while(!Q.empty())
	{
		string v = Q.front();
		Q.pop();
		for(int i = 0; i < v.size(); i++)
		{
			string h = "";
			for(int j = 0; j < i; j++)
			{
				h += v[j];
			}
			for(int j = i + 1; j  <v.size(); j++)
			{
				h += v[j];
			}
			int p = K.size();
			K.insert(h);
			if(K.size() != p)
			{
				Q.push(h);
				sum += n - h.size();
				if(K.size() == k)
				{
					cout << sum;
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}