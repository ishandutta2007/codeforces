#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    string a; cin >> a;

    int x = a[0] - 'a';
    int y = a[1] - '1';

    int tot = 0;

    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j){
            if (i | j){
                int xx = x + i, yy = y + j;
                if (xx >= 0 && xx < 8  && yy >= 0 && yy < 8)
                    ++tot;
            }
        }

    cout << tot << endl;

    return 0;
}