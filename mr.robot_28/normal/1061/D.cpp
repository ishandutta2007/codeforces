#include<bits/stdc++.h>
using namespace std;
const int CONST = 1e9 + 7;
int main(){
	#define int long long
	int n, x, y;
	cin >> n >> x >> y;
	int cost = 0;
	vector <pair <int, int> > A;
	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		A.push_back({l, -1});
		A.push_back({r, 1});
	}
	sort(A.begin(), A.end());
	stack <int> T;
	int j = 0;
	int cnt = 0;
	for(int i = 0; i < A.size(); i++)
	{
		if(A[i].second == -1)
		{
			if(i != 0)
			{
				cost = (cost + ((y * cnt) % CONST) * (A[i].first - A[i - 1].first) % CONST) % CONST;
			}
			bool flag = false;
			if(T.size() != 0)
			{
				if((A[i].first - T.top()) * y < x)
				{
					flag = true;
					cost = (cost + (A[i].first - T.top()) * y) % CONST;
					cnt++;
					T.pop();
				}
			}
			if(!flag)
			{
				cost = (cost + x) % CONST;
				cnt++;
			}
		}
		else
		{
			cost = (cost + ((y * cnt) % CONST) * (A[i].first - A[i - 1].first) % CONST) % CONST;
			T.push(A[i].first);
			cnt--;
		}
	}
	cout << cost;
	return 0;
}