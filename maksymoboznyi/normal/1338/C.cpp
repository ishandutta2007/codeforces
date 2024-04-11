#include <iostream>
#define int long long
using namespace std;

const int N = 1000;

int used[N], a[N];

signed main()
{
  /*  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
*/
    srand(123);
    int cur = 1, cnt = 0;
    while (cur < 256) {
        while (used[cur])
            cur++;
        for (int i = cur + 1; i < N; i++)
            if ((cur ^ i) < N && !used[i] && !used[cur ^ i]) {
                //cout << cur << ' ' << i << ' ' << (cur ^ i) << "\n";
                cnt++;
                a[cnt] = cur;

                cnt++;
                a[cnt] = i;
                cnt++;
                a[cnt] = (cur ^ i);
                used[cur] = used[i] = used[cur ^ i] = 1;
                break;
            }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        //n = rand() % 256 + 1;
        int nn = n;
        if (n <= 3) {
            cout << n << "\n";
            continue;
        }
        int x = 1, lg = 0;
        while (x*4 <= n)
            x *= 4, lg++;
        n -= (x - 1);

        n--; // from 0

        int id = n / 3;
        int f[3];
        f[0] = id + x;
        f[1] = 2;
        //cout << id << endl;
        while (lg > 0) {
            int t = (1ll << (2 * lg - 2));
            if (id / t == 0)
                f[1] <<= 2;
            if (id / t == 1)
                f[1] <<= 2, f[1] |= 2;
            if (id / t == 2)
                f[1] <<= 2, f[1] |= 3;
            if (id / t == 3)
                f[1] <<= 2, f[1] |= 1;
            id %= t;
            lg--;
        }
        //cout << f[1] << endl;
        f[2] = (f[0] ^ f[1]);
        cout << f[n % 3] << "\n";

    }
    return 0;
}