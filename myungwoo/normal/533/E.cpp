#include <bits/stdc++.h>
using namespace std;

int L;
string A, B;

int op(const string &a, const string &b)
{
    int l, r;
    for (int i=0;i<L;i++){
        if (a[i] != b[i]){ l = i; break; }
    }
    for (int i=L;i--;){
        if (a[i] != b[i]){ r = i; break; }
    }
    for (int i=l;i<r;i++)
        if (a[i] != b[i+1]) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> L >> A >> B;
    int ans = op(A, B) + op(B, A);
    printf("%d\n", ans);
}