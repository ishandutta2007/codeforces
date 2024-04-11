#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> A;
typedef pair<int,int> pii;
#define x first
#define y second

int solve(int l, int r, int x) {
    if (l == r) return 0;
    pii lo = {2e9, -1};
    for (int i = l; i < r; ++i) lo = min(lo, {A[i], i});
    return min(r-l, lo.x - x + solve(l, lo.y, lo.x) + solve(lo.y + 1, r, lo.x));
}

int main() {
    cin >> N;
    A.resize(N);
    for (int&a:A) cin >> a;
    cout << solve(0, N, 0) << endl;
}