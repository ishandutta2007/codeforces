#include<bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin >> q;
	for(int t = 0; t < q; t++)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		multiset<int> r;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			r.insert(A[i]);
		}
		bool flag = false;
		while(r.size() > 1)
		{
			int a = *r.begin();
			r.erase(r.begin());
			int b = *r.begin();
			r.erase(r.begin());
			if(a == 2048)
			{
				flag = true;
			}
			if(a == b){
				r.insert(2 * a);
			}
			else
			{
				r.insert(b);
			}
		}
		if(r.size() == 1 && *r.begin() == 2048)
		{
			flag = true;
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}