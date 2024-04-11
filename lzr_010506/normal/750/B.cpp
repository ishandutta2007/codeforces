#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	int l = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		char ch[6];
		scanf("%d%s", &x, ch);
		if(l == 0 && ch[0] != 'S') {cout << "NO"; return 0;}
		if(l == 20000 && ch[0] != 'N') {cout << "NO"; return 0;}
		if(ch[0] == 'E' || ch[0] == 'W') continue;
		if(ch[0] == 'S') l += x;
		else l -= x;
		if(l > 20000 || l < 0) {cout << "NO"; return 0;}
	}
	if(l == 0) cout << "YES";
	else cout << "NO";
	return 0;
}