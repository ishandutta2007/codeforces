#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
string a, st, ed;
bool flag1[1000010], flag2[1000010];
vector<ull> ans;
int main()
{
	cin >> a >> st >> ed;
	int n = a.size();
	int lena = st.size();
	int lenb = ed.size();
	int maxl = max(lena, lenb);
	for(int i = 0; i < n; i ++)
	{
		if(a.substr(i, lena) == st) flag1[i] = 1;
		if(a.substr(i, lenb) == ed) flag2[i + lenb - 1] = 1;
	}
	for(int i = 0; i < n; i ++)

		if(flag1[i])
		{
			ull now = 0;
			for(int j = i; j < n; j ++)
			{
				now = now * 31 + a[j];
				if(flag2[j] == 1 && j - i + 1 >= max(lena, lenb)) ans.push_back(now);
			}
		}
	sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    printf("%d\n", ans.size());
	return 0;
}