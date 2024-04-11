#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define DB(x) cout << #x << "=" << x << endl

bool mk[100];

bool start;

void write(int v){
    if (!start) start = true;
    else cout << " ";
    cout << v;
}

void solve(int64 k, int len, int last)
{
//  DB(k); DB(last);
    int64 cur = 0;
    int p = last + 1;
    for (; cur < k; cur += (len == p ? 1 : (1LL << (len - p - 1))), ++p){
//      DB(cur);
    }
    --p;
    write(p);
    mk[p] = true;

    if (p < len){
        solve(k - (cur - (1LL << (len - p - 1))), len, p);
    }
}

int main()
{
    int n;
    int64 cnt;
    cin >> n >> cnt;

    solve(cnt, n, 0);

    for (int i = n; i > 0; --i) if (!mk[i]) write(i);

    cout << endl;

    return 0;
}