
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

// 2 piles of same number = losing (n = 2)
// 1 1 2 2 (n = 4) = winning
// 1 1 1 1 = losing

// X X X X X X X 1
// If you make 1 empty pile, you lose. Opponent can remove n/2 piles
// First one to make an empty pile loses
// X X X X -> 1 1 X X -> 1 1 1 1
// If there are more than n/2 ones, you lose.

// 1 X X X -> 1 1 1 X
// If you reveal the first 1, you lose
// If there is a 1 in the beginning, you win

// 2 X X X -> 2 2 2 X -> 1 2 2 X -> 1 1 1 X
// If there are more than n/2 twos (no ones or zeroes), you lose

// If the minimum element appears no more than n/2 times, Alice wins
// Otherwise, Bob wins

// 1 1 3 4 -> 1 1 1 1 -> 0 0 1 1 -> 0 0 0 0 

int n;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    VI a(n);
    FOR(i, n) {
        cin >> a[i];
    }
    int M = *min_element(all(a));
    int c = 0;
    FOR(i, n) {
        c += (a[i] == M);
    }
    cout << (c <= n / 2 ? "Alice" : "Bob") << endl;
}