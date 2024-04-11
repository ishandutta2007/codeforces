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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0) a += MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
int fpow(int x, int n)
{
    if (n == 0) return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1) a = mul(a, x);
    return a;
}

void transform(long long *from, long long *to) 
{ 
    if(to - from == 1) 
        return; 
    long long *mid = from + (to - from) / 2; 
    transform(from, mid); 
    transform(mid, to); 
    for(int i = 0; i < mid - from; i++) 
    {
        long long a = *(from + i);
        long long b = *(mid + i);
        *(from + i) = a + b;
        *(mid + i) = a - b;
    }
} 


/*
   void transform(int *from, int *to) 
{ 
    if(to - from == 1) 
        return; 
    int *mid = from + (to - from) / 2; 
    transform(from, mid); 
    transform(mid, to); 
    for(int i = 0; i < mid - from; i++) 
        *(mid + i) += *(from + i); 
} 

void inverse(int *from, int *to) 
{ 
    if(to - from == 1) 
        return; 
    int *mid = from + (to - from) / 2; 
    inverse(from, mid); 
    inverse(mid, to); 
    for(int i = 0; i < mid - from; i++) 
        *(mid + i) -= *(from + i); 
}

*/

const int K = 20;
const int LEN = (1 << K) + 10;
char str[LEN];
long long a[LEN];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < (1 << n); i++)
        a[i] = str[i] - '0';

    transform(a, a + (1 << n) );
    
    for (int i = 0; i < (1 << n); i++)
        a[i] *= a[i];

    transform(a, a + (1 << n) );
    for (int i = 0; i < (1 << n); i++)
    {
        a[i] /= (1 << n);
        a[i] %= MOD;
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        sadd(ans, mul(fpow(2, n - __builtin_popcount(i) ), a[i] ) );
    }

    ans = mul(ans, 3);
    printf("%d\n", ans);




	return 0;
}