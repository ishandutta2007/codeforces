#include <bits/stdc++.h>
using namespace std;
int n, k, num, ans;
int a[200010], b[200010], c[200010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	n = read();
	k = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	int tot = 0;
    for(int i = 1; i <= n; i ++)
        if(a[i] < 0) tot ++, c[++ num] = b[i - 1];
    	else b[i] = b[i - 1] + 1;
    c[1] = 0;
    /*for(int i = 1; i <= n; i ++)
         cout << b[i] << " ";
    cout << endl;*/
    if(tot > k) {cout << -1; return 0;}
    k -= tot;
    sort(c + 1, c + 1 + num);
    if(tot == 0) {cout << 0; return 0;}
    /*for(int i = 1; i <= num; i ++)
         cout << c[i] << " ";
    cout << endl;*/
    for(int i = 1; i <= num; i ++)
    {
   		k -= c[i];
   		if(k >= 0) continue;
   		k += c[i];
   		if(c[i])ans += 2;
    }

    if(k >= b[n]) ans ++;
    else ans += 2;
    cout << ans;
	return 0;
}