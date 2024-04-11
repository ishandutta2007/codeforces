#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 5e5 + 100;
int a[N];
long long sum[N];


int segs[N];
int segNeed = 0;
void addSeg(long long l, long long r)
{
    l = max(l, 0LL);
    r = min(r, N - 3LL);
    if (r < l) return;
    eprintf("[%lld .. %lld]\n", l, r);
    segs[l]++;
    segs[r + 1]--;
}

void printAns(long long x)
{
    bool fnd = false;
    for (int i = 0; i < N; i++)
    {
        segs[i + 1] += segs[i];
        if (segs[i] == segNeed && (i + x) % 2 == 0)
        {
            fnd = true;
            printf("%d ", i);
        }
    }
    if (!fnd)
        printf("-1");
    printf("\n");
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];
    
    long long sumAll = sum[n];
    int ptrk = n - 1, ptrkk = n - 1;

    addSeg(0, n);
    segNeed++;
    for (int k = 0; k <= n; k++)
    {
        long long A = sum[k];
        segNeed++;
        if (k > 0)
        {
            while (ptrk >= 0 && a[ptrk] < k)
                ptrk--;
            int pk = max(ptrk + 1, k);
            long long B = sumAll - sum[pk] + (pk - k) * 1LL * k + k * 1LL * (k - 1);
            eprintf("pk = %d, (pk - k) k = %lld\n", pk, (pk - k) * 1LL * k);

            long long rb = a[k];
            long long lb = A - B;
            eprintf("%d) A = %lld, B = %lld\n", k, A, B);
            eprintf("lb = %lld, rb = %lld\n", lb, rb);

            if (lb <= rb && A - B <= k)
            {
                addSeg(lb, rb);
            }
        }
        else
        {
            addSeg(0, a[0]);
        }

        int kk = k + 1;
        while (ptrkk >= 0 && a[ptrkk] < kk)
            ptrkk--;
        int pkk = max(ptrkk + 1, k);
        long long B = sumAll - sum[pkk] + (pkk - k) * 1LL * kk + kk * 1LL * (kk - 1);

        long long lb;
        if (k != 0)
            lb = a[k] + 1;
        else
            lb = a[0] + 1;
        long long rb = B - A;
        
        eprintf("%d) A = %lld, B = %lld\n", k, A, B);
        eprintf("%lld - %lld + %lld + %lld\n", sumAll, sum[pkk], (pkk - k) * 1LL * kk, kk * 1LL * (kk - 1));
        eprintf("lb = %lld, rb = %lld\n", lb, rb);
        if (lb <= rb)
            addSeg(lb, rb);
        

        eprintf("\n");
    }

    printAns(sumAll);


	return 0;
}