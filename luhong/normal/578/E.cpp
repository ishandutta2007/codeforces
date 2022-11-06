#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MN 101000

char s[MN];
std::vector<int> v[MN]; int tot = 0;
std::vector<int> L, LL;
std::vector<int> R, RR;
int ql[MN], tl = 0, qr[MN], tr = 0;

void dfs(int ty)
{
	if(ty == 0)
	{
		if(!L.empty())
		{
			int x = L[L.size() - 1];
			for(int i = 0; i < v[x].size(); i++) printf("%d ", v[x][i]);
			L.pop_back(); dfs(0);
		}
		else if(!LL.empty())
		{
			int x = LL[LL.size() - 1];
			for(int i = 0; i < v[x].size(); i++) printf("%d ", v[x][i]);
			LL.pop_back(); dfs(1);
		}
	}
	if(ty == 1)
	{
		if(!R.empty())
		{
			if(R.empty()) return;
			int x = R[R.size() - 1];
			for(int i = 0; i < v[x].size(); i++) printf("%d ", v[x][i]);
			R.pop_back(); dfs(1);
		}
		else if(!RR.empty())
		{
			if(RR.empty()) return;
			int x = RR[RR.size() - 1];
			for(int i = 0; i < v[x].size(); i++) printf("%d ", v[x][i]);
			RR.pop_back(); dfs(0);
		}
	}
}

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	for(int i = 1; i <= len; i++)
	{
		if(s[i] == 'L')
		{
			int N;
			if(tr) N = qr[tr--];
			else N = ++tot;
			
			ql[++tl] = N;
			v[N].push_back(i);
		}
		else
		{
			int N;
			if(tl) N = ql[tl--];
			else N = ++tot;
			
			qr[++tr] = N;
			v[N].push_back(i);
		}
	}
	printf("%u\n", tot - 1); 
	int id1 = 0, id2 = 0;
	for(int i = 1; i <= tot; i++)
	{
		int S = v[i].size() - 1;
		if(s[v[i][0]] == 'L' && s[v[i][S]] == 'R') id1 = i;
		if(s[v[i][0]] == 'R' && s[v[i][S]] == 'L') id2 = i;
	}
	if(id1 && id2)
	{
		if(v[id1][v[id1].size() - 1] > v[id2][v[id2].size() - 1])
		{
			v[id2].push_back(v[id1][v[id1].size() - 1]);
			v[id1].pop_back();
		}
		else
		{
			v[id1].push_back(v[id2][v[id2].size() - 1]);
			v[id2].pop_back();
		}
	}
	for(int i = 1; i <= tot; i++)
	{
		int S = v[i].size() - 1; 
		if(s[v[i][0]] == 'L' && s[v[i][S]] == 'L') LL.push_back(i), cnt1++;
		if(s[v[i][0]] == 'L' && s[v[i][S]] == 'R') L.push_back(i), cnt3++;
		if(s[v[i][0]] == 'R' && s[v[i][S]] == 'L') R.push_back(i), cnt4++;
		if(s[v[i][0]] == 'R' && s[v[i][S]] == 'R') RR.push_back(i), cnt2++;
	}
	if(cnt1 > cnt2 || cnt1 == cnt2 && cnt3 > cnt4) dfs(0);
	else dfs(1);
}