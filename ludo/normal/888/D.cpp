#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    ll ret = 1;
    if (K >= 2) ret += N * (N-1) / 2;
    if (K >= 3) ret += N * (N-1) * (N-2) / 3;
    if (K >= 4) ret += N * (N-1) * (N-2) * (N-3) / 8 * 3;
    
    cout << ret << endl;
    return 0;
}