#include <iostream>
#include <vector>
using namespace std;


int pr[1005];
bool isNotLast[1005];

int n, x;
int ADD = 0;


int dfs(int pos, bool &some)
{
	int cnt = 1;
	if (pos == x)
	{
		some = true;
		ADD = 1;
	}
	while (pr[pos] != -1)
	{
		cnt++;
		pos = pr[pos];
		if (pos == x)
		{
			ADD = cnt;
			some = true;
		}
	}
	if (some)
	{
		ADD = cnt - ADD + 1; 
	}
	return cnt;
}




vector <int> q;

bool isPossible[1005];




int main()
{

	scanf("%d%d", &n, &x);
	x--;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pr[i] );
		pr[i]--;
		if (pr[i] != -1)
			isNotLast[pr[i] ] = true;
	}

	for (int i = 0; i < n; i++)
	{
		if (!isNotLast[i] )
		{
			bool isMain = false;
			int cnt = dfs(i, isMain);
			if (!isMain)
				q.push_back(cnt);
		}
	}
	isPossible[0] = true;
	for (int i = 0; i < q.size(); i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (isPossible[j] == false)
				continue;
			isPossible[j + q[i] ] = true;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (isPossible[i] == true)
		{
			printf("%d\n", i + ADD);
		}
	}
	


	return 0;
}