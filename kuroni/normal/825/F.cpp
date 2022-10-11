#include <iostream>
#include <cstdio>
using namespace std;

string s, t = "";
short int len[8005][8005], z[8005][8005], cnt[8005], ans[8005], n;

inline void mini(short int &a, short int b)
{
    if (b < a)
        a = b;
}

void init()
{
    int i;
    for (i = 1; i < 10; i++)
        cnt[i] = 1;
    for (i = 10; i < 100; i++)
        cnt[i] = 2;
    for (i = 100; i < 1000; i++)
        cnt[i] = 3;
    for (i = 1000; i < 8005; i++)
        cnt[i] = 4;
}

void z_func()
{
    int i, j, l, r;
    for (i = n - 1; i >= 0; i--)
    {
        t = s[i] + t;
        z[i][0] = t.size();
        l = r = 0;
        for (j = 1; j < t.size(); j++)
            if (j > r)
            {
                l = r = j;
                while (r < t.size() && t[r] == t[r - l])
                    ++r;
                z[i][j] = r - l; --r;
            }
            else
            {
                int k = j - l;
                if (z[i][k] < r - j + 1)
                    z[i][j] = z[i][k];
                else
                {
                    l = j;
                    while (r < t.size() && t[r] == t[r - l])
                        ++r;
                    z[i][j] = r - l; --r;
                }
            }
        for (j = t.size() - 1; j >= 0; j--)
            z[i][j + n - t.size()] = z[i][j];
    }
}


void init_period()
{
    int i, j;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			len[i][j] = j - i + 1;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (j + len[i][j] < n && z[i][j + 1] >= len[i][j])
				mini(len[i][j + len[i][j]], len[i][j]);
}

void find_ans()
{
	for (int i = 0; i < n; i++)
	{
		ans[i] = len[0][i] + cnt[(i + 1) / len[0][i]];
		for (int j = 0; j < i; j++)
			mini(ans[i], ans[j] + len[j + 1][i] + cnt[(i - j) / len[j + 1][i]]);
	}
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(); cout.tie();
    cin >> s; n = s.size();
    init();
    z_func();
    init_period();
    find_ans();
    cout << ans[n - 1];
}