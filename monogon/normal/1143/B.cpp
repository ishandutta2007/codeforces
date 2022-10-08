
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

// let's say there are k digits
// max(n - 1, 1) * 9^{k - 1}
// n * find(n - leading digit)

string str;

LL maxprod(string s) {
    if(s.length() == 0)
        return 0;
    LL l1 = max(s[0] - 1 - '0', 1);
    FOR(i, s.length() - 1) {
        l1 *= 9;
    }
    LL l2 = s[0] - '0';
    int i = 1;
    while(i < s.length() && s[i] == '0') {
        i++;
    }
    if(s.length() > 1) {
        l2 *= maxprod(s.substr(i));
    }
    return max(l1, l2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> str;
    cout << maxprod(str) << endl;
}