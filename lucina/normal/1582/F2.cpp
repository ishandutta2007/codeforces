#include<bits/stdc++.h>
using namespace std;
const int N = 8192;
int n;
vector <int> to_update[N + 10];
bool can[N + 10];
int r[N + 10];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    can[0] = true;
    for (int i = 0 ; i < N ; ++ i) {
        to_update[i].push_back(0);
    }
    fill(r, r + N, N);

    for (int i = 0, x ; i < n ; ++ i) {
        cin >> x;
        for (int key : to_update[x]) {
            int to = x ^ key;
            can[to] = true;
            while (r[to] > x) {
                r[to] -= 1;
                if (r[to] != x) to_update[r[to]].push_back(to);
            }
        }
        to_update[x].clear();
    }
    int k = count(can, can + N, true);
    cout << k << '\n';
    for (int i = 0 ; i < N ; ++ i)
        if (can[i]) cout << i << ' ';
    cout << '\n';
}
/**
    Wow, this problem is so cool. I can't solve this myself, but this is kinda teach me how to find LIS in O(max(A)^2)
    Obvious dp solution is for each X keep minimal Y that can have increase sequences end at Y and XOR = x.
    we can naively update it in O(max(A)) each time. But it will be O(max(A) * n) instead.
    Instead, for each X, it's meaningful to be at each position once.
    If there is increasing sequences with value = X and end at Y.
    Then this X can be base XOR value for Y + 1, ... , max(A). We can naively keep this in vector!
    It's meaningful to be at Y + 1, ..., max(A) once, and if we can achieve this again with minimal ending Z,
    just push it at position Z + 1, ..., Y, each number will push max(A) times in total.
    so O(max(A)^2)
*/