#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[110];
set <int> s;
int ans;

int Nxt(int book, int s)
{
	for (int i = s; i < n; i ++)
		if (a[i] == book) return i;
	return n;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i ++)
		if (s.find(a[i]) == s.end()) 
		{
			ans ++;
			if (s.size() == k) 
			{
				int id = -1, mx = -1;
				for (set <int>::iterator it = s.begin(); it != s.end(); it ++) 
				{
					int is = Nxt(*it, i);
					if (is > mx) { mx = is; id = *it; }
				}
				s.erase(id);
			}
			s.insert(a[i]);
		}
	printf("%d\n", ans);
	return 0;
}