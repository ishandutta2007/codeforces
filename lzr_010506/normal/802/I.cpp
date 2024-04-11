#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;

char p[101000];
struct point
{
    int a,b;
}w[101000];
int n, C[101000], ord1[101000], ord2[101000], rk[101000], SA[101000], LCP[101000], st[101000][2];

ll sqr(int x)
{
	return (ll)x * x;
}

void Suffix_Array()
{
    int i, L = 1, M = max(200, n);
    for(i = 0; i < n; i ++)
    	w[i].a = p[i], w[i].b = p[i + 1];
    while(1)
    {
        for(i = 0; i <= M; i ++) C[i] = 0;
        for(i = 0; i < n; i ++) C[w[i].b] ++;
        for(i = 1; i <= M; i ++) C[i] += C[i - 1];
        for(i = 0; i < n; i ++) ord1[-- C[w[i].b]] = i;
        for(i = 0; i <= M; i ++) C[i] = 0;
        for(i = 0; i < n; i ++) C[w[i].a] ++;
        for(i = 1; i <= M; i ++) C[i] += C[i - 1];
        for(i = n - 1; i >= 0; i --) ord2[-- C[w[ord1[i]].a]] = ord1[i];
        int cnt = 0;
        for(i = 0; i < n; i ++)
        {
            if(!i || w[ord2[i]].a != w[ord2[i - 1]].a || w[ord2[i]].b != w[ord2[i - 1]].b) cnt ++;
            rk[ord2[i]] = cnt;
        }
        if(cnt == n) break;
        L <<= 1;
        for(i = 0; i < n; i ++)
        {
            w[i].a = rk[i];
            if(i + L >= n) w[i].b = 0;
            else w[i].b = rk[i + L];
        }
    }
    for(i = 0; i < n; i ++)
    	SA[rk[i]] = i;
    int x, y, t = 0;
    for(i = 0; i < n; i ++)
    {
    	x = rk[i];
    	if(t) t --;
    	if(x == n) continue;
    	y = SA[x + 1];
    	while(p[i + t] == p[y + t]) t ++;
    	LCP[x] = t;
    }
}

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		scanf("%s", p);
		n = strlen(p);
		Suffix_Array();
		long long res = 0;
		int top = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(i <= n) res += (n - SA[i]) - max(LCP[i - 1], LCP[i]);
			while(top && st[top][0] >= LCP[i])
			{
				res += 1ll * (st[top][0] - max(LCP[i], st[top - 1][0])) * sqr(i - st[top - 1][1]);
				top --;
			}
			top ++;
            st[top][0] = LCP[i], st[top][1] = i;
		}
		cout << res << endl;
	}

	return 0;
}