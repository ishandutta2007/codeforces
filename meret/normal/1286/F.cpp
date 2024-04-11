#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

struct Option {
    LL sum;
    int mask;
    int size;
    int n_positive;
};

bool operator < (const Option& a, const Option& b) {
    return a.sum < b.sum;
}

vector<Option> get_options(LL *a, int n) {
    vector<Option> result;
    for (int mask = 0; mask < (1 << n); ++mask) {
        Option option;
        option.mask = mask;
        set<pair<LL, int>> got;
        for (int submask = mask; ; submask = (submask - 1) & mask) {
            option.n_positive = 0;
            option.size = 0;
            option.sum = 0LL;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    ++option.size;
                    if ((submask >> i) & 1) {
                        ++option.n_positive;
                        option.sum += a[i];
                    } else {
                        option.sum -= a[i];
                    }
                }
            }
            auto description = make_pair(option.sum, option.n_positive);
            if (option.n_positive > 0 && option.n_positive < option.size) {
                description.second = 1;
            }
            if (got.find(description) == got.end()) {
                got.insert(description);
                result.push_back(option);
            }
            if (submask == 0) {
                break;
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

vector<Option> opa, opb;

LL a[25];
int n;

bool possible[1 << 20];
int dp[1 << 20];

inline void smax(int& a, int b) {
    if (b > a) {
        a = b;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            a[last++] = a[i];
        }
    }
    n = last;
    opa = get_options(a, n / 2);
    opb = get_options(a + n / 2, (n + 1) / 2);
    int l = (int)opb.size();
    int r = (int)opb.size();;
    for (const auto& o: opa) {
        while (l > 0 && o.sum + opb[l - 1].sum >= -20) {
            --l;
        }
        while (r > 0 && o.sum + opb[r - 1].sum > 20) {
            --r;
        }
        for (int i = l; i < r; ++i) {
            if (o.n_positive + opb[i].n_positive == 0 || o.n_positive + opb[i].n_positive == o.size + opb[i].size) {
                continue;
            }
            LL sum = o.sum + opb[i].sum;
            LL fudge = o.size + opb[i].size - 1;
            if (((sum + fudge) % 2 == 0) && sum <= fudge && sum >= -fudge) {
                possible[o.mask | (opb[i].mask << (n / 2))] = true;
            }
        }
    }
    for (int submask = 0; submask < (1 << n); ++submask) {
        if (!possible[submask]) {
            continue;
        }
        int other = ((1 << n) - 1) & (~submask);
        int mask = other;
        while(true) {
            smax(dp[mask | submask], dp[mask] + 1);
            if (mask == 0) {
                break;
            }
            mask = (mask - 1) & other;
        }
    }
    int result = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        result = max(result, dp[mask]);
    }
    cout << n - result << endl;
}