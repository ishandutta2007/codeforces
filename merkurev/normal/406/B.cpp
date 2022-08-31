#include <iostream>
#include <vector>
using namespace std;


const int mx = 1e6;
bool used[mx + 5];
vector <int> ans;
             


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);          
		used[x] = true;
	}
	int ie = 1;
	int je = mx;
	for (int i = 1; i <= mx / 2; i++)
	{
		int j = mx - i + 1;
		if (used[i] && !used[j] )
		{                   
			ans.push_back(j);
		} 
		else if (!used[i] && used[j] )
		{                   
			ans.push_back(i); 
		} 
		else if (used[i] && used[j] )
		{                   
			while (used[ie] || used[je] )
			{
				ie++;
				je--;
			}               
			ans.push_back(ie);
			ans.push_back(je);
			ie++;
			je--;
		}
	
	}
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] );
	




	return 0;
}