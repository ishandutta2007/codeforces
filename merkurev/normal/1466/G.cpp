#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) 42 // fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}




const int ALP = 26;
const int N = (int) 3e6 + 500;
const int MAX_LEN = (int) 1e6 + 100;
char s0[N], t[N];
int slen[N];

void genPref(int n, int len, char pref[])
{
    slen[0] = len;
    for (int i = 0; i < n; i++)
    {
        pref[len] = t[i];
        for (int j = 0; j < len && len + 1 + j < MAX_LEN; j++)
            pref[len + 1 + j] = pref[j];
        len = 2 * len + 1;
        len = min(len, MAX_LEN);
        slen[i + 1] = len;
    }
}

char pref[N], suff[N];
int id[N];
int cntLetter[MAX_LEN][ALP];
int st[N], en[N];
int zpref[N], zsuff[N];
int deg2[N];
char w[N];
int zw[N];

void calcZ(char s[], int z[], int n)
{
	int l = 0, r = 0;
	for (int i = 1; i < n; i++)
	{
        z[i] = 0;
		if (i < r)
			z[i] = min(r - i, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] > r)
		{
			r = i + z[i];
			l = i;
		}
	}

    for (int i = 0; i < n; i++)
        eprintf("%c ", s[i]);
    eprintf("\n");
    for (int i = 0; i < n; i++)
        eprintf("%d ", z[i]);
    eprintf("\n");
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    deg2[0] = 1;
    for (int i = 0; i + 1 < N; i++)
        deg2[i + 1] = mul(deg2[i], 2);

    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s0);
    scanf("%s", t);

    int len = strlen(s0);
    for (int i = 0; i < len; i++)
    {
        pref[i] = s0[i];
        suff[i] = s0[len - 1 - i];
    }
    genPref(n, len, pref);
    genPref(n, len, suff);
    
    // for (int i = 0; i < len; i++)
    //     cntLetter[1][s0[i] - 'a']++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ALP; j++)
            cntLetter[i + 2][j] = mul(2, cntLetter[i + 1][j]);
        sadd(cntLetter[i + 2][t[i] - 'a'], 1);
    }

    int sw = slen[n];
    for (int it = 0; it < q; it++)
    {
        st[it] = sw;
        scanf("%d%s", &id[it], pref + sw);
        sw += strlen(pref + sw);
        en[it] = sw;
        for (int i = st[it]; i < en[it]; i++)
            suff[i] = pref[st[it] + (en[it] - i - 1)];
    }

    calcZ(pref, zpref, sw);
    calcZ(suff, zsuff, sw);


    for (int it = 0; it < q; it++)
    {
        eprintf("--\n");
        int ans = 0;
        for (int i = st[it]; i < en[it]; i++)
        {
            int prefLen = i - st[it];
            int suffLen = (en[it] - i - 1);
            eprintf("%d - %c - %d\n", prefLen, pref[i], suffLen);
            if (zpref[st[it] + prefLen + 1] >= suffLen && zsuff[st[it] + suffLen + 1] >= prefLen)
            {
                int si = lower_bound(slen, slen + n + 1, max(prefLen, suffLen)) - slen;
                //eprintf("si = %d, id = %d\n", si, id[it]);
                if (si < id[it])
                {
                    int cnt = cntLetter[id[it] + 1][pref[i] - 'a'];
                    eprintf("cnt = %d\n", cnt);
                    ssub(cnt, mul(cntLetter[si + 1][pref[i] - 'a'], deg2[id[it] - si]));
                    eprintf("cnt = %d\n", cnt);
                    sadd(ans, cnt);
                }
            }
        }

        if (en[it] - st[it] <= len)
        {
            int pos = 0;
            for (int i = st[it]; i < en[it]; i++)
                w[pos++] = pref[i];
            for (int i = 0; i < len; i++)
                w[pos++] = s0[i];

            calcZ(w, zw, pos);

            int cnt = 0;
            for (int i = en[it] - st[it]; i < pos; i++)
                if (zw[i] >= en[it] - st[it])
                    cnt++;
            cnt = mul(cnt, deg2[id[it]]);
            sadd(ans, cnt);
        }

        printf("%d\n", ans);
    }

        

	return 0;
}