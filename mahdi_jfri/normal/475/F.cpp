#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define is_empty shittoc

typedef pair<int , int> kir;
typedef set<kir>::iterator shit;

const int maxn = 1e5 + 20;

inline bool is_empty(set<kir> &a , int x)
{
	shit l = a.lower_bound(make_pair(x , -1e9 - 1));
	shit r = a.lower_bound(make_pair(x+1 , -1e9 - 1));

	return (l == a.end() || l == r) && (r != a.end() && l != a.begin());

}

inline int solve(set<kir> &a , set<kir> &b)
{
	shit cl = a.begin() , cr = a.end() , ru = b.begin() , rd = b.end();
	cr-- , rd--;

	for(int i = 0; i * 2 < (int)a.size(); i++)
	{
		if(is_empty(a , (cl -> first) + 1))
		{
			set<kir> tmpa , tmpb;

			while((*a.begin()).first <= (*cl).first)
			{
				kir tmp = *a.begin();
				
				a.erase(tmp);
				tmpa.insert(tmp);

				swap(tmp.first , tmp.second);

				b.erase(tmp);
				tmpb.insert(tmp);
			}
			return solve(tmpa , tmpb) + solve(a , b);
		}

		if(is_empty(a , (cr -> first) + 1))
		{
			set<kir> tmpa , tmpb;

			while((*a.rbegin()).first > (*cr).first)
			{
				kir tmp = *a.rbegin();
				
				a.erase(tmp);
				tmpa.insert(tmp);

				swap(tmp.first , tmp.second);

				b.erase(tmp);
				tmpb.insert(tmp);
			}
			return solve(tmpa , tmpb) + solve(a , b);
		}

		if(is_empty(b , (ru -> first) + 1))
		{
			set<kir> tmpa , tmpb;

			while((*b.begin()).first <= (*ru).first)
			{
				kir tmp = *b.begin();
				
				b.erase(tmp);
				tmpb.insert(tmp);

				swap(tmp.first , tmp.second);

				a.erase(tmp);
				tmpa.insert(tmp);

			}
			return solve(tmpa , tmpb) + solve(a , b);
		}

		if(is_empty(b , (rd -> first) + 1))
		{
			set<kir> tmpa , tmpb;

			while((*b.rbegin()).first > (*rd).first)
			{
				kir tmp = *b.rbegin();
				
				b.erase(tmp);
				tmpb.insert(tmp);

				swap(tmp.first , tmp.second);

				a.erase(tmp);
				tmpa.insert(tmp);
			}
			return solve(tmpa , tmpb) + solve(a , b);
		}

		cl++;
		cr--;

		ru++;
		rd--;
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	set<kir> a , b;

	for(int i = 0; i < n; i++)
	{
		int x , y;
		cin >> x >> y;

		a.insert({x , y});
		b.insert({y , x});
	}

	cout << solve(a , b) << endl;
}