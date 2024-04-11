#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m;
vector <int> CNT;
bool cmp(pair <int, pair <int, int> > a, pair <int, pair <int, int> > b)
{
	int t = sqrt(n);
	if(a.second.first / t == b.second.first / t)
	{
		return a.second.second < b.second.second;
	}
	else
	{
		return a.second.first / t < b.second.first / t;
	}
}
int main()
{
	cin >> n >> m;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <int> ANS(m);
	vector <pair <int, pair <int, int> > > K(m);
	for(int i = 0; i < m; i++)
	{
		cin >> K[i].second.first >> K[i].second.second;
		K[i].second.first--;
		K[i].second.second--;
		K[i].first = i;
	}
	int cnt = 0;
	CNT.resize(n + 1, 0);
	sort(K.begin(), K.end(), cmp);
	for(int i = 0; i < m; i++)
	{
		if(i == 0 || K[i].second.second < K[i - 1].second.second)
		{
			cnt = 0;
			for(int j = 0; j <= n; j++)
			{
				CNT[j] = 0;
			}
			for(int j = K[i].second.first; j <= K[i].second.second; j++)
			{
				if(A[j] <= n)
				{
					CNT[A[j]]++;
					if(CNT[A[j]] == A[j] + 1){
						cnt--;
					}
					else if(CNT[A[j]] == A[j])
					{
						cnt++;
					}
				}
			}
		}
		else
		{
			for(int j = K[i - 1].second.second + 1; j <= K[i].second.second; j++)
			{
				if(A[j] <= n)
				{
					CNT[A[j]]++;
					if(CNT[A[j]] == A[j] + 1){
						cnt--;
					}
					else if(CNT[A[j]] == A[j])
					{
						cnt++;
					}
				}
			}
			if(K[i].second.first >= K[i- 1].second.first)
			{
				for(int j = K[i - 1].second.first; j < K[i].second.first; j++)
				{
					if(A[j] <= n)
					{
						CNT[A[j]]--;
						if(CNT[A[j]] == A[j] - 1)
						{
							cnt--;
						}
						else if(CNT[A[j]] == A[j])
						{
							cnt++;
						}
					}
				}
			}
			else
			{
				for(int j = K[i].second.first; j < K[i - 1].second.first; j++)
				{
					if(A[j] <= n)
					{
						CNT[A[j]]++;
						if(CNT[A[j]] == A[j] + 1)
						{
							cnt--;
						}
						else if(CNT[A[j]] == A[j])
						{
							cnt++;
						}
					}
				}
			}
		}
		ANS[K[i].first] = cnt;
	}
	for(int i = 0; i < m; i++)
	{
		cout << ANS[i] << "\n";
	}
	return 0;
}