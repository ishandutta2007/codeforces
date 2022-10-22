#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

vector<pair<int, int>> factorize(int N) {
    vector<pair<int, int>> res;
    for (int i = 2; i * i <= N; i++) {
        if (N % i) continue;
        res.push_back({ i,0 });
        while (N % i == 0) { N /= i; res.back().second++; }
    }
    if (N != 1) res.push_back({ N,1 });
    return move(res);
}


void loop() {
    int N; scanf("%d", &N);
    auto P = factorize(N);
    bool sq = false;
    rep(i, P.size()) if (P[i].second >= 2) sq = true;
    if (sq) {
        int sqi = 0;
        rep(i, P.size()) if (P[i].second >= 2) sqi = i;
        swap(P[sqi], P.back());
        auto sqp = P.back(); P.pop_back();

        deque<int> ans2 = { 1 };
        for (auto p : P) {
            int z = ans2.size() * p.second;
            rep(i, z) ans2.push_back(ans2[i] * p.first);
        }
        
        deque<int> ans;
        for (auto p : ans2) {
            vector<int> buf = { p };
            rep(i, sqp.second) buf.push_back(buf.back() * sqp.first);
            swap(buf[0], buf[1]);
            for (auto e : buf) ans.push_back(e);
        }
        swap(ans[0], ans[1]); ans.pop_front();

        rep(i, ans.size()) { if (i) printf(" "); printf("%d", ans[i]); } printf("\n");
        printf("0\n");
    }
    else if (P.size() >= 3) {
        deque<int> ans2 = { 1 };
        for (int ip = 2; ip < P.size(); ip++) {
            for (int i = ans2.size() - 1; i >= 0; i--)
                ans2.push_back(ans2[i] * P[ip].first);
        }

        int x = P[0].first, y = P[1].first;
        deque<int> ans;
        for (auto p : ans2) ans.push_back(p);
        reverse(ans2.begin(), ans2.end());
        for (auto p : ans2) ans.push_back(p * x);
        for (auto p : ans2) ans.push_back(p * x * y);
        reverse(ans2.begin(), ans2.end());
        swap(ans2[0], ans2[1]);
        reverse(ans2.begin(), ans2.end());
        for (auto p : ans2) ans.push_back(p * y);
        ans.pop_front();

        rep(i, ans.size()) { if (i) printf(" "); printf("%d", ans[i]); } printf("\n");
        printf("0\n");
    }
    else {
        int x = P[0].first, y = P[1].first;
        printf("%d %d %d\n", x, x * y, y);
        printf("1\n");
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) loop();
    return 0;
}