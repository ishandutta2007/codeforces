#include<bits/stdc++.h>
 
using namespace std;
#define int long long
struct cmp
{
bool operator() (pair <int, int> a, pair <int, int> b)
{
	if(a == b)
	{
		return false;
	}
	if(a == make_pair(-1LL, 0LL))
	{
		return true;
	}
	if(b == make_pair(-1LL, 0LL))
	{
		return false;
	}
	if(a.second == 0)
	{
		return b.second > 0;
	}
	if(b.second == 0)
	{
		return a.second < 0;
	}
	if(a.second < 0 && b.second > 0)
	{
		return true;
	}
	if(a.second > 0 && b.second < 0)
	{
		return false;
	}
	if(a.second < 0)
	{
		a.second = -a.second;
		b.second = -b.second;
		swap(a, b);
	}
	return (long double) b.first / b.second < (long double)a.first / a.second;
}
};
map <pair <int, int>, int, cmp> countpoint;
bool crossproduct(pair <int, int> a, pair <int, int> b)
{
	return (long double) a.first * b.second > (long double)a.second * b.first;
}
pair <int, int> lower(pair <int, int> p)
{
	auto it = countpoint.upper_bound(p);
	if(it == countpoint.begin())
	{
		it = countpoint.end();
	}
	it--;
	return it -> first;
}
pair <int, int> higher(pair <int, int> p)
{
	auto it = countpoint.upper_bound(p);
	if(it == countpoint.end())
	{
		it = countpoint.begin();
	}
	return it -> first;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s, p, g;
	cin >> s >> p >> g;
	s = s + p + g;
	int n;
	cin >> n;
	int cnt0 = 0;
	int countpairs = 0;
	int ans = 0;
	vector <pair <int, int> > masspoint;
	for(int i = 0; i < n; i++)
	{
		char t;
		cin >> t;
		if(t == 'A')
		{
			int s1, p1, g1, p2, s2;
			cin >> s1 >> p1 >> g1;
			s1 = s1 + p1 + g1;
			p2 = s1 * p - p1 * s;
			s2 = s1 * g - g1 * s;
			if(p2 == 0 && s2 == 0)
			{
				cnt0++;
				masspoint.push_back({0, 0});
			}
			else
			{
				long long d = __gcd(p2, s2);
				if(d < 0)
				{
					d = -d;
				}
				masspoint.push_back({p2 / d, s2 / d});
				pair <int, int> a1 = make_pair(p2 / d, s2 / d);
				pair <int, int> a2 = make_pair(-p2 / d, -s2 / d);
				if(!countpoint.empty())
				{
					pair <int, int> p1 = lower(a1);
					pair <int, int> p2 = higher(a1);
					if(!crossproduct(p1, p2) && crossproduct(p1, a1) && crossproduct(a1, p2))
					{
						ans = 3;
					}
				}
				if(countpoint.find(a1) == countpoint.end() && countpoint.find(a2) != countpoint.end())
				{
					countpairs++;
				}
				countpoint[a1]++;
			}
		}
		else
		{
			int idx;
			cin >> idx;
			idx--;
			pair <int, int> t = masspoint[idx];
			if(t.first == 0 && t.second == 0)
			{
				cnt0--;
			}
			else
			{
				countpoint[t]--;
				if(countpoint[t] == 0)
				{
					countpoint.erase(t);
					if(!countpoint.empty())
					{
						pair <int, int> p1 = lower(t);
						pair <int, int> p2 = higher(t);
						if(!crossproduct(p1, p2)){
							ans = 0;
						}
					}
					if(countpoint.find({-t.first, -t.second}) != countpoint.end())
					{
						countpairs--;
					}
				}
			}
		}
		if(cnt0 > 0)
		{
			cout << 1 << "\n";
		}
		else if(countpairs > 0)
		{
			cout << 2  << "\n";
		}
		else
		{
			cout << ans << "\n";
		}
	}
	return 0;
}