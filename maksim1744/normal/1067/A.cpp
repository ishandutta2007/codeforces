/*
    24.10.2018 19:36:54
*/

#include <bits/stdc++.h>

using namespace std;

string to_string(const basic_string< char >& s) {
    return (string)s;
}

string to_string(const bool& b) {
    return b ? "true" : "false";
}

string to_string(const char& c) {
    string ans(1, c);
    return ans;
}

string to_string(const unsigned char& c) {
    string answer = "";
    if (c / 16 < 10) {
        answer.push_back('0' + c / 16);
    } else {
        answer.push_back('a' + c / 16 - 10);
    }
    if (c % 16 < 10) {
        answer.push_back('0' + c % 16);
    } else {
        answer.push_back('a' + c % 16 - 10);
    }
    return answer;
}

template< typename T1, typename T2 >
string to_string(const pair< T1, T2 >& p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template< typename T >
string to_string(const T& c) {
    string answer = "[";
    bool first = true;
    for (auto& item : c) {
        if (!first) {
            answer += ", ";
        }
        answer += to_string(item);
        first = false;
    }
    answer += "]";
    return answer;
}

template< typename T >
void print(const T& t, bool end = true) {
    cout << to_string(t);
    if (end) {
        cout << "\n";
    }
}

const bool debug = true;

const long long mod = 998244353;

// long long solve(int a1, int a2, int n, bool ok1, bool ok2) {
//     vector< int > dp1(201, 0), dp2(201, 0);
//     for (int i = 0; i < a1; ++i) {
//         dp2[i] = 1;
//     }
//     for (int i = 200; i >= a1; --i) {
//         dp1[i] = 1;
//     }
//     if (ok1) {

//     }
//     for (int i = 0; i < n - 1; ++i) {
//         vector< int > ndp1(201, 0), ndp2(201, 0);
//     }
// }

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector< int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector< long long > dp1(201, 0), dp2(201, 0), dp3(201, 0);  // up equal down
    if (a[0] == -1) {
        for (int i = 1; i < 201; ++i) {
            dp1[i] = 1;
        }
    } else {
        dp1[a[0]] = 1;
    }
    // print(dp1);
    // print(dp2);
    // print(dp3);
    for (int i = 1; i < n; ++i) {
        if (a[i] == -1) {
            vector< long long > nd1(201, 0), nd2(201, 0), nd3(201, 0);
            for (int j = 1; j < 201; ++j) {
                nd2[j] = dp1[j] + dp2[j] + dp3[j];
            }
            long long s = 0;
            for (int j = 1; j < 201; ++j) {
                nd1[j] = s % mod;
                s += dp1[j] + dp2[j] + dp3[j];
            }
            s = 0;
            for (int j = 200; j > 0; --j) {
                nd3[j] = s % mod;
                s += dp2[j] + dp3[j];
            }
            swap(nd1, dp1);
            swap(nd2, dp2);
            swap(nd3, dp3);
        } else {
            dp2[a[i]] += dp1[a[i]] + dp3[a[i]];
            dp1[a[i]] = 0;
            dp3[a[i]] = 0;
            for (int j = 1; j <= a[i]; ++j) {
                dp1[j] += dp1[j - 1] + dp2[j - 1] + dp3[j - 1];
            }
            for (int j = 199; j >= a[i]; --j) {
                dp3[j] += dp3[j + 1] + dp2[j + 1];
            }
            for (int j = 200; j > a[i]; --j) {
                dp1[j] = 0;
                dp2[j] = 0;
                dp3[j] = 0;
            }
            for (int j = 0; j < a[i]; ++j) {
                dp1[j] = 0;
                dp2[j] = 0;
                dp3[j] = 0;
            }
            dp1[a[i]] %= mod;
            dp2[a[i]] %= mod;
            dp3[a[i]] %= mod;
        }
        // cout << '\n';
        // print(dp1);
        // print(dp2);
        // print(dp3);
        // cout << '\n';
    }
    long long ans = 0;
    for (int i = 1; i < 201; ++i) {
        ans += dp2[i] + dp3[i];
    }
    cout << ans % mod << '\n';
    // a[0] = 1;
    // a[n + 1] = 1;
    // long long ans = 1;
    // int i = 0;
    // while (i < n + 2) {
    //     if (a[i] == -1) {
    //         int i2 = i + 1;
    //         while (a[i2] == -1) {
    //             ++i2;
    //         }
    //         bool ok1 = false, ok2 = false;
    //         if (i - 1 > 0 && a[i - 1] <= a[i - 2]) {
    //             ok1 = true;
    //         }
    //         if (i2 + 1 < n + 2 && a[i2 + 1] >= a[i2]) {
    //             ok2 = true;
    //         }
    //         ans = (ans * solve(a[i - 1], a[i2], i2 - i, ok1, ok2));
    //         i = i2;
    //     } else {
    //         ++i;
    //     }
    // }
    return 0;
}