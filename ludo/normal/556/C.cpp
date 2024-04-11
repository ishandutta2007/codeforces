#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
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

int n, k;
int chainlen[MAX];
int chainstart[MAX];
int numbers[MAX];

int chainind[MAX], chainnr[MAX];

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif // LOCAL

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> chainlen[i];
        chainstart[i] = (i == 0 ? 0 : (chainstart[i - 1] + chainlen[i - 1]));
        for (int j = 0; j < chainlen[i]; j++) {
            cin >> numbers[chainstart[i] + j];
            numbers[chainstart[i] + j]--;
        }
    }

    int curchain = -1;
    for (int i = 0; i < n; i++) {
        if (i == chainstart[curchain + 1]) {
            curchain++;
        }

		chainind[numbers[i]] = i;
		chainnr[numbers[i]] = curchain;

//		cerr << numbers[i] << ": " << i << ", " << curchain << endl;
    }

    int startchain = chainnr[0];
    int startind = chainind[0];

//    cerr << startind << " " << chainstart[startchain] << " " << startchain << endl;

    assert(startind == chainstart[startchain]);

    int startlen = 1;
    while (startlen < chainlen[startchain] && numbers[startind + startlen] == numbers[startind + startlen - 1] + 1) {
        startlen++;
    }

    cout << ((k - 1) + 2 * (n - k - (startlen - 1))) << endl;

    return 0;
}