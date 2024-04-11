#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;

vector <vector <int> > query(int l, int r)
{
	cout << "? " << l << " " << r << endl;
	vector <vector <int> > res;
	int c = (r - l + 1);
	c = c * (c + 1) / 2;
	for(int i = 0; i < c; i++)
	{
		string s;
		cin >> s;
		vector <int> cnt(26, 0);
		for(int j = 0; j < sz(s); j++)
		{
			cnt[s[j] - 'a']++;
		}
		res.push_back(cnt);
	}
	return res;
}
bool cmp(vector <int> a, vector <int> b)
{
	int c1 =0 , c2 = 0;
	for(int i = 0; i < 26; i++)
	{
		c1 += a[i];
		c2 += b[i];
	}
	return c1 < c2;
}
string get_str(int l, int r)
{
	map <vector <int>, int> mp;
	vector <vector <int> > p = query(l, r);
	vector <vector <int> > p1 = query(l + 1, r);
	for(auto x : p)
	{
		mp[x]++;
	}
	for(auto x : p1)
	{
		mp[x]--;
	}
	vector <int> cnt1(26, 0);
	vector <vector <int> > p2;
	for(auto it : mp)
	{
	    if(it.Y)
        {
		p2.push_back(it.X);
        }
	}
	sort(p2.begin(), p2.end(), cmp);
	vector <int> cnt(26, 0);
	string s = "";
	for(int i = 0; i < sz(p2); i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(p2[i][j] > cnt[j])
			{
				cnt[j]++;
				char t = j + 'a';
				s += t;
			}
		}
	}
	return s;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	map <vector <int>, int> mp;
	if(n == 1)
	{
        vector <vector <int> > p = query(1, n);
		for(int i = 0; i < 26; i++)
		{
			if(p[0][i])
			{
				char t = 'a' + i;
				cout << "! " << t << endl;
			}
		}
		return 0;
	}
	if(n == 2)
    {
        string s = get_str(1, 2);
        cout << "! " << s << endl;
        return 0;
    }
    string s_first_half = get_str(1, (n + 1) / 2);
    vector <vector <int> > p = query(1, n);
    vector <char> str(n + 1);
    for(int i = 1; i <= n / 2; i++)
    {
        str[i] = s_first_half[i - 1];
    }
    vector <int> cnt_pred;
    for(int i = 0; i < sz(p); i++)
    {
        int s = 0;
        for(int j = 0; j < 26; j++)
        {
            s += p[i][j];
        }
        if(s == n)
        {
            cnt_pred = p[i];
        }
    }
    vector <vector <int> > cnt(n + 2, vector <int> (26));
    cnt[1] = cnt_pred;
    for(int i = 1; i <= (n + 1) / 2; i++)
    {
        vector <int> cnt_t(26);
        for(int j = 0; j < sz(p); j++)
        {
            int s = 0;
            for(int t = 0; t < 26; t++)
            {
                s += p[j][t];
            }
            if(s == i + 1)
            {
                for(int t = 0; t < 26; t++)
                {
                    cnt_t[t] += p[j][t];
                }
            }
            else if(s == i){
                for(int t = 0; t < 26; t++)
                {
                    cnt_t[t] -= p[j][t];
                }
            }
        }
        for(int j = 0; j < 26; j++)
        {
            cnt[i + 1][j] = cnt_t[j];
        }
    }
    for(int i = 1; i <= (n + 1) / 2; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            int dlp = cnt[i][j] - cnt[i + 1][j];
            char t = 'a' + j;
      //      cout << dlp << " ";
            if(str[i] == t)
            {
                dlp--;
            }
            if(dlp)
            {
                str[n - i + 1] = t;
            }
        }
   //     cout << "\n";
    }
    cout << "! ";
    for(int i = 1; i <= n; i++)
    {
        cout << str[i];
    }
    cout << endl;
	return 0;
}