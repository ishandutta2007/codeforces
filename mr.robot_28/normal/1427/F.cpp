#include<bits/stdc++.h>
using namespace std;

signed main()
{
 //   ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   // cout.tie(NULL);
   	int n;
   	cin >> n;
   	vector <bool> used(n * 6, 0);
   	for(int i = 0; i < n * 3; i++)
   	{
   		int x;
   		cin >> x;
   		x--;
   		used[x] = 1;
	}
	stack <int> S;
	S.push(-1);
	vector <vector <int> > nodes;
	vector <int> father(n * 6, -1);
	vector <int> player(n * 6);
	vector <int> deg(n * 6, 0);
	vector <bool> used1(n * 6, 0);
	for(int i = 0; i < n * 6; i++)
	{
		if(S.top() != -1 && player[S.top()] == used[i])
		{
			nodes[S.top()].push_back(i);
			if(nodes[S.top()].size() == 3)
			{
				S.pop();
			}
		}
		else
		{
			int ind = nodes.size();
			deg[ind] = 0;
			father[ind] = S.top();
			player[ind] = used[i];
			vector <int> vec = {i};
			nodes.push_back(vec);
			if(S.top() != -1)
			{
			deg[S.top()]++;
			}
			S.push(ind);
		}
	}
	for(int i = 1; i <= n * 2; i++){
		int val = -1;
		for(int j = 0; j < n * 2; j++)
		{
			if(!used1[j] && deg[j] == 0 && player[j] == i % 2)
			{
				val = j;
				if(i % 2 || father[j] != -1)
				{
					break;
				}
			}
		}
		if(val == -1)
		{
			cout << "A";
			return 0;
		}
		cout << nodes[val][0] + 1 << " " << nodes[val][1] + 1 << " " << nodes[val][2] + 1 << "\n";
		used1[val] = 1;
		if(father[val] != -1)
		{
			deg[father[val]]--;
		}
	}
    return 0;
}