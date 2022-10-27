#include<bits/stdc++.h>
using namespace std;
const int _size = 2e5 + 10;
char s[_size];
int cnt[_size];
int cc[26];
int all_cnt;
int ma;
void update_ma()
{
	while(ma > 0 && !cnt[ma]){
		ma--;
	}
}
void dec1(int id)
{
	cnt[cc[id]]--;
	cc[id]--;
	cnt[cc[id]]++;
}
pair <int, int> stk[_size];
int sn, m, now, last_len;
void add(int i, bool flag)
{
	if(flag)
	{
		dec1(stk[sn - 1].second);
		dec1(stk[i].second);
		all_cnt -= 2;
		cout << now + 1 << " " << now + stk[i].first << "\n";
		update_ma();
		sn--;
		now -= stk[sn].first;
		if(i + 1 < m)
		{
			stk[i + 1].first += stk[sn].first;
		}
		else
		{
			last_len += stk[sn].first;
		}
	}
	else
	{
		stk[sn++] = stk[i];
		now += stk[i].first;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		int n = strlen(s);
		all_cnt = 0;
		int lt = 0;
		m = 0;
		for(int i = 1; i < n; i++)
		{
			if(s[i] == s[i - 1])
			{
				cc[s[i] - 'a']++;
				all_cnt++;
				stk[m++] = make_pair(i - lt, s[i] - 'a');
				lt = i;
			}
		}
		last_len = n - lt;
		ma = 0;
		for(int i = 0; i < 26; i++)
		{
			cnt[cc[i]]++;
			ma = max(ma, cc[i]);
		}
		cout << 1 + max(ma, (all_cnt + 1) / 2) << "\n";
		if(ma * 2 < all_cnt)
		{
			sn = now = 0;
			for(int i = 0; i < m; i++)
			{
				add(i, sn && stk[sn - 1].second != stk[i].second && ma * 2 < all_cnt);
			}
			m = sn;
		}
		int main_id = -1;
		for(int i = 0; i < 26; i++)
		{
			if(cc[i] == ma)
			{
				main_id = i;
			}
		}
		sn = now = 0;
		for(int i = 0; i < m; i++)
		{
			add(i, sn && ((stk[sn - 1].second == main_id) ^ (stk[i].second == main_id)));
		}
		for(int i = 0; i < sn; i++)
		{
			cout << 1 << " " << stk[i].first << "\n";
		}
		cout << 1 << " " << last_len << "\n";
		memset(cc, 0, sizeof(cc));
		memset(cnt, 0, sizeof(int) * (ma + 1));
	}
	return 0;
}