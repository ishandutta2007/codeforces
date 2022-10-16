#include <bits/stdc++.h>

using namespace std;

int n;
long long cost[100005];
long long need[100005]; //min stamina needed before going through
long long free_walk[100005], free_swim[100005]; //how much we can convert to flying
long long walk_converted[100005];
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> cost[i], cost[i] *= 2;
    cin >> s; s = ' ' + s;
    long long ans = 0;
    long long charge_cost = 7;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'L') {
            need[i] = need[i-1] + cost[i];
        }
        else {
            need[i] = need[i-1] - cost[i];
            if (s[i] == 'G') charge_cost = min(charge_cost, 5LL);
            else charge_cost = min(charge_cost, 3LL);
        }
        if (need[i] > 0) { //of course s[i] == 'L'
            ans += charge_cost * need[i];
            ans += cost[i];
            need[i] = 0;
            free_swim[i] = free_walk[i] = 0;
        }
        else {
            int go_cost = (s[i] == 'L' ? 1 : (s[i] == 'W' ? 3 : 5));
            ans += go_cost * cost[i];
            free_swim[i] = free_swim[i-1];
            free_walk[i] = free_walk[i-1];
            if (s[i] == 'W') free_swim[i] += cost[i];
            else if (s[i] == 'G') free_walk[i] += cost[i];
            else {
                //sacrifice swim
                long long tmp = cost[i];
                long long sub = min(free_swim[i], tmp);
                tmp -= sub, free_swim[i] -= sub;
                sub = min(free_walk[i], tmp);
                tmp -= sub, free_walk[i] -= sub;
            }
        }
    }
    if (need[n] < 0) { //shit let's go back
        //convert walk first
        long long convert_walk = 0, max_convertible = 1e18;
        for (int i = n; i >= 1; --i) {
            max_convertible = min(max_convertible, min(-need[i] / 2, free_walk[i]));
            if (s[i] == 'G') {
                long long convert = min(max_convertible, cost[i]);
                walk_converted[i] = convert;
                convert_walk += convert;
                max_convertible -= convert;
            }
        }
        ans -= convert_walk * 4;

        for (int i = 1; i <= n; ++i) {
            walk_converted[i] += walk_converted[i-1];
            need[i] += 2 * walk_converted[i];
        }

        long long convert_swim = 0; max_convertible = 1e18;
        for (int i = n; i >= 1; --i) {
            max_convertible = min(max_convertible, min(-need[i] / 2, free_swim[i]));
            if (s[i] == 'W') {
                long long convert = min(max_convertible, cost[i]);
                convert_swim += convert;
                max_convertible -= convert;
            }
        }
        ans -= convert_swim * 2;

        //cout << convert_walk << ' ' << convert_swim << endl;
    }
    cout << ans / 2 << endl;
    return 0;
}