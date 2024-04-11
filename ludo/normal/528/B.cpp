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
#define MAX 200000

typedef long long ll;
typedef pair<int, int> pii;

int n;
pii pts[MAX];

int last_ind[MAX];
int max_len = 1;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(false);
#endif // LOCAL

    cin >> n;
    for (int i = n; i--; ) {
        cin >> pts[i].first >> pts[i].second;
        pts[i].first += pts[i].second;
    }
    sort(pts, pts+n);

#ifdef LOCAL
    for (int i = 0; i < n; i++) {
        cout << pts[i].first << ", " << pts[i].second << endl;
    }
#endif

    max_len = 1;
    last_ind[1] = pts[0].first;
    for (int ind = 1; ind < n; ind++) {
        if (last_ind[max_len] <= pts[ind].first - pts[ind].second * 2) {
            last_ind[++max_len] = pts[ind].first;
        }
    }
    cout << max_len << endl;

//    cin >> n;
//    for (int i = n; i--; ) {
//        cin >> pts[i].first >> pts[i].second;
////        pts[i].first += pts[i].second;
//    }
//
//    sort(pts, pts + n);
//
//#ifdef LOCAL
//    for (int i = 0; i < n; i++) {
//        cout << pts[i].first << ", " << pts[i].second << endl;
//    }
//#endif
//
//    max_len = 1;
//    last_ind[1] = pts[0].first + pts[0].second;
//    for (int ind = 1; ind < n; ind++) {
//        if (last_ind[max_len] <= pts[ind].first - pts[ind].second) {
//            last_ind[++max_len] = pts[ind].first + pts[ind].second;
//        }
////        for (int l = max_len - 1; --l > 0;) {
////            if (last_ind[l] <= pts[ind].first - pts[ind].second) {
////                last_ind[l + 1] = min(last_ind[l + 1], pts[ind].first + pts[ind].second);
////            }
////        }
////        last_ind[1] = min(last_ind[1], pts[ind].first + pts[ind].second);
//    }
//    cout << max_len << endl;
    return 0;
}