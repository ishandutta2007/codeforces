#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

void setmax(int &a, int b) {
    if (a < b)
        a = b;
}

struct event {
    int x, id, type;

    bool operator<(const event &e) const {
        return x < e.x || (x == e.x && type < e.type);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<event> events;
    events.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, i, 0});
        events.push_back({r, i, 1});
    }
    sort(all(events));

    const int MASK = 1 << k;
    vector<int> popcount(MASK);
    for (int mask = 1; mask < MASK; mask++)
        popcount[mask] = popcount[mask >> 1] + (mask & 1);

    int current_mask = 1;
    vector<int> dp(MASK);
    dp[0] = 0;
    vector<int> new_dp(MASK);

    vector<int> open;
    open.reserve(k);

    for (int i = 0; i < 2 * n; i++) {
        const auto &[x, id, type] = events[i];
        int delta_x = i == 0 ? 0 : x - events[i - 1].x;

        if (type == 0) {
            int new_mask = current_mask << 1;
            for (int prev_mask = 0; prev_mask < current_mask; prev_mask++) {
                new_dp[prev_mask] = dp[prev_mask] + (popcount[prev_mask] & 1) * delta_x;
                new_dp[prev_mask ^ (1 << len(open))] = dp[prev_mask] + (delta_x - 1) * (popcount[prev_mask] & 1)
                    + ((popcount[prev_mask] ^ 1) & 1);
            }

            current_mask = new_mask;
            swap(dp, new_dp);
            open.push_back(id);
        } else {
            int new_mask = current_mask >> 1;
            int position = find(all(open), id) - open.begin();
            assert(position != len(open));

            auto get_new_mask = [&](int mask) {
                int answer = 0;
                for (int i = 0; i < position; i++)
                    answer ^= (mask >> i & 1) << i;

                for (int i = position + 1; i < len(open); i++)
                    answer ^= (mask >> i & 1) << (i - 1);

                return answer;
            };

            fill(new_dp.begin(), new_dp.begin() + new_mask, 0);
            for (int prev_mask = 0; prev_mask < current_mask; prev_mask++)
                setmax(new_dp[get_new_mask(prev_mask)], dp[prev_mask] + delta_x * (popcount[prev_mask] & 1));

            current_mask = new_mask;
            swap(dp, new_dp);
            open.erase(open.begin() + position);
        }
    }

    assert(current_mask == 1);
    cout << dp[0] << '\n';
}