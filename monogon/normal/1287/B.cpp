
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1505;
int n, k;
string card[N];
map<char, int> m = {{'S', 0}, {'E', 1}, {'T', 2}};

string missing(const string &s1, const string &s2) {
    string ans = "";
    for(int i = 0; i < k; i++) {
        ans.push_back(((-s1[i] - s2[i]) % 3 + 3) % 3);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> card[i];
        for(int j = 0; j < k; j++) {
            card[i][j] = m[card[i][j]];
        }
    }
    sort(card, card + n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cnt += binary_search(card, card + n, missing(card[i], card[j]));
        }
    }
    cout << cnt / 3 << endl;
}