#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	vector <int> used(n, 0);
	vector <pair <int, int> > P;
	set <int> L;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		P.push_back({A[i], i});
		L.insert(i);
	}
	int cnt = 0;
	sort(P.begin(), P.end());
	for(int i = P.size() - 1; i >= 0; i--)
	{
		if(used[P[i].second] == 0)
		{
			set<int> :: iterator it;
			int cnt1 = -1;
			it = L.lower_bound(P[i].second);
			set <int> :: iterator it1;
			it1 = it;
			vector <int> wP;
			for(;it != L.end(); it++)
			{
				if(cnt1 == k)
				{
					break;
				}
				else
				{
					wP.push_back(*it);
					used[*it] = cnt % 2 + 1;
					//L.erase(it);
				}
				cnt1++;
			}
			if(it1 != L.begin())
			{
			cnt1 = 0;
			it1--;
			for(;it1 != L.begin(); it1--)
			{
				if(cnt1 == k)
				{
					break;
				}
				else
				{
					wP.push_back(*it1);
					used[*it1] = cnt %2 + 1;
					//L.erase(it1);
				}
				cnt1 ++;
			}
			if(cnt1 != k)
			{
				wP.push_back(*L.begin());
				used[*L.begin()] = cnt % 2 + 1;
			}
			}
			for(int j = 0; j < wP.size(); j++)
			{
				L.erase(wP[j]);
				used[wP[j]] = cnt % 2 + 1;
			}
			cnt ++ ;
		}
	}
	for(int i = 0; i < used.size(); i++)
	{
		cout << used[i];
	}
    return 0;
}