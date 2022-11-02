#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int n, a[MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

//    srand(time(NULL));
//    n = MAX;
//    for (int i = 0; i < n; i++) {
//        a[i] = 1 + ((rand() & 127) | ((rand() & 255) << 7) | ((rand() & 255) << 15) | ((rand() & 255) << 23)) % 1000000000;
//    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ret = 0;
    int i = 0;
    while (i < n) {
        int w = 1, decs = 0, lastdec = i + 1;
        while (i + w < n) {
//            cerr << (i + w) << ": " << a[i + w] << endl;
            if (a[i + w - 1] >= a[i + w]) {
                if (decs > 0) {
//                    cerr << "more desc cut" << endl;
                    break;
                } else if(w > 1 && i + w <= n && !(a[i + w - 1] + 1 < a[i + w + 1] || a[i + w - 2] + 1 < a[i + w])) {
                    if (decs == 0) {
                        lastdec = i + w - 1;
                        w++;
                    }
//                    cerr << "inc cut " << i + w << ", " << decs << endl;
                    break;
                }
                decs++;
                lastdec = i + w;
            }
            w++;
        }
//        cerr << i << ":\t" << w << endl << endl;
        if (w > ret) {
            ret = w;
        }
        if (i + w == n) {
            break;
        }
        i = lastdec;
    }
    cout << ret << endl;
    return 0;
}