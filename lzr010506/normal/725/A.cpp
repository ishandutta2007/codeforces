#include <bits/stdc++.h>
using namespace std;
int n;
char ch[200010];
int main()
{
	cin >> n;
	scanf("%s", ch + 1);
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		if(ch[i] == '<') ans ++;
		else break;
	for(int i = n; i >= 1; i --)
		if(ch[i] == '>') ans ++;
		else break;
	cout << ans;
	return 0;
}