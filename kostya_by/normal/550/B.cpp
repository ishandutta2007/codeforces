#include <iostream>

using namespace std;

const int MAXN = 16;
const int INF = 1000000000;

int n;
int lowest_cost, highest_cost;
int max_difference;

int cost[MAXN];

void solve() {
    cin >> n;
    cin >> lowest_cost >> highest_cost;
    cin >> max_difference;

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int answer = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int count = 0;
        int sum_cost = 0;
        int min_cost = INF;
        int max_cost = -INF;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i) ) {
                count += 1;
                sum_cost += cost[i];
                min_cost = min(min_cost, cost[i] );
                max_cost = max(max_cost, cost[i] );
            }
        }

        if (count < 2) {
            continue;
        }
        if (sum_cost < lowest_cost || highest_cost < sum_cost) {
            continue;
        }
        if (max_cost - min_cost < max_difference) {
            continue;
        }
       
        // cerr << mask << " " << count << " " << sum_cost << " " << min_cost << " " << max_cost << "\n";

        answer += 1;
    }

    cout << answer << "\n";
}

int main() {
    int cases; cases = 1;
    for (int i = 0; i < cases; i++) {
        solve(); 
    }
}