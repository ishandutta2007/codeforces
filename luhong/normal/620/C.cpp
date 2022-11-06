#include <cstdio>
#include <set>
#define MN 301000

std::set<int> st;

int n, ans = 0;
int l[MN], r[MN];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		if(st.find(x) != st.end()) st.clear(), ans++, l[ans] = r[ans - 1] + 1, r[ans] = i;
		else st.insert(x);
	}
	r[ans] = n;
	if(!ans) puts("-1");
	else
	{
		printf("%d\n", ans);
		for(int i = 1; i <= ans; i++) printf("%d %d\n", l[i], r[i]);
	}
}