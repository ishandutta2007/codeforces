#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
#include<stack>
#include<string>
using namespace std;
int main()
{
	long long a, b;
	cin >> a >> b;
	long long sum = a + b;
	long long p = ( - 1 + (long long)sqrt(8 * sum + 1)) / 2;
	vector <bool> used(p);
	long long k = p;
	set <long long> q, w;
	while(a > (long long)0 && k > 0)
	{
		long long h = min(a, k);
		a-=h;
		q.insert(h);
		used[h - 1] = true;
		k = h - 1;
	}
	k = p;
	while(b > (long long)0 && k > 0)
	{
		for(int i = k - 1; i >= 0; i--)
		{
			if(!used[i])
			{
				k = i + 1;
				break;
			}
		}
		long long h = min(b, k);
		if(!used[h - 1])
		{
		w.insert(h);
		}
		used[h - 1] = true;
		b-=h;
	}
	cout << q.size() << endl;
	set<long long> :: iterator it;
	for(it = q.begin(); it != q.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << w.size() << endl;
	for(it = w.begin(); it != w.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}