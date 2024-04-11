#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int total(int64 v){
    int ans = 0;
    for (int i = 2; i < 63; ++i){
        for (int j = 0; j + 1 < i; ++j){
            int64 c = ((1LL << i) - 1) ^ (1LL << j);
            if (c <= v){
                ++ans;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 a, b;
    cin >> a >> b;
    cout << total(b) - total(a - 1) << endl;

    return 0;
}