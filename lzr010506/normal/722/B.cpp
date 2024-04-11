#include <bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; i ++)
		scanf("%d", &a[i]);
	getchar();
	bool ans = 1;
	char ch[10010];
	for(int P = 1; P <= T; P ++)
	{
		int n = 0;
		gets(ch);
		n = strlen(ch);
		int ll = 0;
		for(int i = 0; i < n; i ++)
			if(ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'y')
				ll ++;
		if(ll != a[P]) {ans = 0; break;}
	}
	if(ans == 0) printf("NO");
	else printf("YES");

	return 0;
}