#include <iostream>
using namespace std;

long long mod = (long long) 1e9 + 7;


long long cnt[10];
long long deg[10], degOct[10];
long long c[10][10];

long long ans = 0;
int some[10];
int s1[10];
bool is[10];

long long getSome(long long n, int k)
{
    long long ans = 1;
    memset(is, false, sizeof is);
    for (int i = 0; i < k; i++)
    {
        long long cur = n - i;
        ans *= cur;
        ans %= mod;
    }
    return ans;
}

void getAns(int pos = 0)
{
    int sum = 0;
    for (int i = 1; i < 7; i++)
        sum += some[i];
    if (sum >= some[0] && pos)
        return ;

    if (pos != 7)
    {
        for (int i = 0; i < 10; i++)
        {
            some[pos] = i;
            getAns(pos + 1);
        }
        some[pos] = 0;
        return;
    }
    memset(s1, false, sizeof s1);
    for (int i = 1; i < 7; i++)
        s1[some[i] ] ++;
    long long curans = 1;
    for (int i = 0; i < 10; i++)
    {
        int c = s1[i];
        curans *= getSome(cnt[i], c);
        curans %= mod;
    }
    curans *= getSome(cnt[some[0] ], 1);
    curans %= mod;
    ans += curans;
    ans %= mod;


    return;
}

int main()
{

    for (int i = 0; i < 10; i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }

    int n;
    scanf("%d", &n);

    deg[0] = 1;
    for (int i = 1; i < 10; i++)
        deg[i] = deg[i - 1] * 10;
    degOct[0] = 1;
    for (int i = 1; i < 10; i++)
        degOct[i] = degOct[i - 1] * 8;
    int num = 0;
    for (int i = 0; i < 10; i++)
    {
        int cur = (n / deg[i]) % 10;
        if (cur == 4 || cur == 7)
        {
            for (int j = 9; j > 0; j--)
                cnt[j] = cnt[j - 1];
            cnt[0] = 0;
            num++;
        }
        for (int j = 0; j < cur; j++)
        {
            for (int k = 0; k < 10 && k <= i; k++)
            {
                int nk = k;
                if (j == 4 || j == 7)
                    nk ++;
                cnt[nk] += degOct[i - k] * (1LL << k) * c[i][k];
            }
        }
    }
    cnt[num] ++;
    cnt[0] --;

    getAns();
    printf("%I64d", ans);

    return 0;
}