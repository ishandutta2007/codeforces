#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;

const int BASE = 1e15;
struct str{
	ll a, b;
	str(): a(0), b(0) {}
 
	void increase(ll x) {
		b += x;
		a += b / BASE;
		b = b % BASE;
	}
 
	ll modulo(ll m) {
		return ((a % m) * (BASE % m) + b % m) % m;
	}
};

void chkmin(int &a, int b)
{
	a = min(a, b);
}

struct min_stuff{
	map <ll, ll> values;
	ll sum;
	void insert(ll x){
		values[x]++;
		sum += x;
	}
	void erase(ll x)
	{
		values[x]--;
		sum -= x;
	}
	void min(ll x)
	{
		if(values.empty())
		{
			return;
		}
		while(true)
		{
			auto pp = (*prev(values.end()));
			if(pp.X <= x)
			{
				break;
			}
			sum -= (pp.X - x) * pp.Y;
			values.erase(pp.X);
			values[x] += pp.Y;
		}
	}
	ll get_sum()
	{
		return sum;
	}
};

struct rmq{
	int n;
	vector <int> t;
	void init(int _n)
	{
		n = 1;
		while(n < _n)
		{
			n *= 2;
		}
		t.resize(2 * n);
	}

	void update(int pos, int val)
	{
		pos += n;
		t[pos] = val;
		pos >>= 1;
		while(pos)
		{
			t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
			pos >>= 1;
		}
	}

	int get(int l, int r)
	{
		l += n;
		r += n;
		int res = 2e9;
		while(l <= r)
		{
			if(l & 1)
			{
				chkmin(res, t[l]);
				l++;
			}
			if((r & 1) == 0)
			{
				chkmin(res, t[r]);
				r--;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

struct solver{
	solver(){}

	vector <int> s, p, alive, link;
	vector <int> w;
	rmq R;
	min_stuff S;
	str ans;
	int q, n = 0;
	void init(int _q)
	{
		q = _q;
		s.resize(q);
		p.resize(q);
		w.resize(q);
		alive.resize(q);
		link.resize(q);
		R.init(q);
	}
	str query(int c, int new_w)
	{
		s[n] = c;
		w[n] = new_w;
		if(n == 0)
		{
			p[n] = -1;
		}
		else
		{
			p[n] = p[n - 1];
			while(p[n] != -1 && s[p[n] + 1] != s[n])
			{
				p[n] = p[p[n]];
			}
			if(s[p[n] + 1] == s[n])
			{
				p[n]++;
			}
			alive[n - 1] = s[n];
			if(p[n - 1] == -1 || alive[p[n - 1]] != alive[n - 1])
			{
				link[n - 1] = p[n - 1];
			}
			else
			{
				link[n - 1] = link[p[n - 1]];
			}
		}
		R.update(n, w[n]);
		int v = n - 1;
		while(v != -1){
			if(alive[v] != s[n])
			{
				S.erase(R.get(n - 1 - v, n - 1));
				v = p[v];
			}
			else
			{
				v = link[v];
			}
		}
		S.min(w[n]);
		if(s[n] == s[0])
		{
			S.insert(w[n]);
		}
		n++;
		ans.increase(S.get_sum());
		return ans;
	}
};
solver S;
const int MAXK = 26;
const int MAX_C =(1 << 30);
void query(char &c, int &w, str ans)
{
	c = 'a' + ((c - 'a') + ans.modulo(MAXK)) % MAXK;
	w = w ^ (ans.modulo(MAX_C));
}

signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int q;
	cin >> q;
	S.init(q);
	str ans;
	while(q--)
	{
		char c;
		int w;
		cin >> c >> w;
		query(c, w, ans);
		ll _c = c - 'a';
		ans = S.query(_c, w);
//cout << ans << "\n";
		if(ans.a != 0)
		{
			cout << ans.a;
		int t = ans.b;
		int len = 0;
		while(t > 0)
		{
			len++;
			t /= 10;
		}
		while(len < 15)
		{
			cout << 0;
			len++;
		}
		}
		cout << ans.b << "\n";
	}
	return 0;
}