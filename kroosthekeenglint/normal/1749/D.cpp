#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int modo = 998244353;
bool is_prime[300005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    long long m;
    scanf("%d%lld",&n,&m);
    long long now = 1;
    int p = 1;
    int i;
    int ans = 1;
    int sum_ans = 0;
    for (i=2;i<=n;i++)
    {
        is_prime[i] = true;
    }
    for (i=2;i<=n;i++)
    {
        if (is_prime[i])
        {
            int j;
            for (j = i + i; j <= n; j+=i)
            {
                is_prime[j] = false;
            }
        } 
    }
    for (i=1;i<=n;i++)
    {
        ans = (long long)ans * (m % modo) % modo;
        sum_ans += ans;
        sum_ans %= modo;
        if (is_prime[i])
        {
            now = now * i;
        }
        if (now > m)
        {
            now = m;
            p = 0; 
        }
        p = (long long)p * ((m / now) % modo) % modo;
        sum_ans -= p;
        sum_ans %= modo;
    }
    printf("%d\n",(sum_ans + modo)%modo);
    return 0;
}