/*
    Author: MarX
    School: UH
 */

#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)5e3 + 10;

int N;
int L[MAXN];
int ST[MAXN << 2];

void build(int p, int b, int e)
{
    if (b == e)
    {
        ST[p] = b;
    }
    else
    {
        int mid = (b + e) >> 1;
        int left = p << 1;
        int right = left | 1;

        build(left,b,mid);
        build(right,mid + 1,e);
        if (L[ST[left]] <= L[ST[right]])
            ST[p] = ST[left];
        else
            ST[p] = ST[right];
    }
}

int query(int p, int b, int e, int x, int y)
{
    if (x <= b && e <= y)
        return ST[p];
    else
    {
        int mid = (b + e) >> 1;
        int left = p << 1;
        int right = left | 1;

        if (y <= mid)
            return query(left,b,mid,x,y);
        else if (mid + 1 <= x)
            return query(right,mid + 1,e,x,y);
        else
        {
            int l = query(left,b,mid,x,y);
            int r = query(right,mid + 1,e,x,y);
            if (L[l] <= L[r])
                return l;
            else
                return r;
        }
    }
}

int solve(int a, int b, int h)
{
    if (b < a)
        return 0;
    int ans = b - a + 1;
    int p = query(1,0,N - 1,a,b);
    ans = min(ans,L[p] - h + solve(a, p - 1, L[p]) + solve(p + 1,b, L[p]));
    return ans;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> L[i];

    build(1,0, N - 1);
    cout << solve(0, N - 1, 0) << endl;
}