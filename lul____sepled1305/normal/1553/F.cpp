
#include<bits/stdc++.h>
using namespace std;
 
const int N = 3e5+10;  // limit for array size
 
struct FenwickTree
{
    vector<long long> bit;  // binary indexed tree
    int n;
 
    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }
 
    long long sum(int r)
    {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    long long sum(int l, int r)
    {
        if(l > r)
            return 0;
        return sum(r) - sum(l - 1);
    }
 
    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
 
FenwickTree T(N),C(N);
int c[N];
 
long long solve_small(int n)
{
    long long cur = T.sum(1,n-1);
    int i;
    for(i=1; i*i<=n; i++)
    {
        cur += c[i]*(n%i);
    }
    int last = i-1;
    for(; i>=1; i--)
    {
        cur += (C.sum(last+1,n/i)*n)-(T.sum(last+1,n/i)*i);
        last = max(n/i,last);
    }
    return cur;
}
 
long long solve_large(int n)
{
    long long cur = C.sum(n+1,N)*n;
    for(int i=1; i*n<N; i++)
    {
        cur += T.sum(i*n,min(i*n+n-1,N)) - (C.sum(i*n,min(i*n+n-1,N)))*i*n;
    }
    return cur;
}
 
long long solve(int n)
{
    return solve_small(n) + solve_large(n);
}
 
long long turn(int n)
{
    long long cur = solve(n);
    T.add(n,n);
    C.add(n,1);
    c[n] = 1;
    return cur;
}
 
main()
{
    int n;
    scanf("%d",&n);
    long long cur = 0;
    for(int i=0; i<n; i++)
    {
        int aa;
        scanf("%d",&aa);
        cur += turn(aa);
        printf("%lld ",cur);
    }
    return 0;
}