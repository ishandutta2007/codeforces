#include <bits/stdc++.h>
using namespace std;
char ch[100010];
int main()
{
	int n, a, b;
	cin >> n >> a >> b;
    scanf("%s", ch);
	if(ch[a - 1] == ch[b - 1]) cout << 0;
	else cout << 1;
	return 0;
}