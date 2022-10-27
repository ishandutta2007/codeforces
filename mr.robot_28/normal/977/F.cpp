#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	map <int, int> Q;
	map <int, int> W;
	vector <pair <int, int> > P(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		Q[A[i]] ++;
		if(Q[A[i] - 1] != 0)
		{
			W[A[i]] = W[A[i] - 1] + 1;
		}
		else
		{
			W[A[i]] = 1;
		}
	}
	map<int, int> :: iterator it;
	for(it = W.begin(); it != W.end(); it++)
	{
		P.push_back({it -> second, it -> first});
	}
	sort(P.begin(), P.end());
	vector <int> L;
	int j = A.size() -1 ;
	while(P[P.size() - 1].first > 0)
	{
		for(j = j; j >= 0; j--)
		{
			if(A[j] == P[P.size() - 1].second)
			{
				L.push_back(j + 1);
				P[P.size() - 1].second--;
				P[P.size() - 1].first --;
				break;
			}
		}
	}
	cout << L.size() << endl;
	for(int i = L.size() - 1; i>= 0; i--)
	{
		cout << L[i] << " ";
	}
	return 0;	
}