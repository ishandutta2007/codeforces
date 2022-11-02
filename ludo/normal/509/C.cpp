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

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int n, d;

int dsum = 0;
int lnum[MAX] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    srand(time(NULL));
//    n = 10;
    cin >> n;

    for (int i = 0; i < n; i++) {
//        int d = 1 + (rand() % 100);
//        cout << d << ":\t";
        cin >> d;

        lnum[0]++;
        dsum++;
        for (int j = 0; lnum[j] >= 10; j++) {
            lnum[j] -= 10;
            lnum[j + 1]++;
            dsum -= 9;
        }

        int mod_ind = 0;

        while (dsum > d) {
            if (lnum[mod_ind] == 0) {
                mod_ind++;
                continue;
            }
            dsum -= lnum[mod_ind] - 1;
            lnum[mod_ind] = 0;
            lnum[++mod_ind]++;
            for (int j = mod_ind; lnum[j] >= 10; j++) {
                lnum[j] -= 10;
                lnum[j + 1]++;
                dsum -= 9;
            }
        }

        mod_ind = 0;
        while (dsum != d) {
            if(dsum + 9 - lnum[mod_ind] < d) {
                dsum += 9 - lnum[mod_ind];
                lnum[mod_ind++] = 9;
            } else {
                lnum[mod_ind]++;
                dsum++;
                for (int i = mod_ind; lnum[i] >= 10; i++) {
                    lnum[i] -= 10;
                    lnum[i + 1]++;
                    dsum -= 9;
                }
            }
        }
        int ind = MAX - 1;
        while (lnum[ind] == 0) {
            ind--;
        }
        while (ind >= 0) {
            cout << lnum[ind];
            ind--;
        }
        cout << endl;
    }
    return 0;
}