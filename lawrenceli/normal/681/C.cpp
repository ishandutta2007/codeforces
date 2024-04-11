#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;
vector<string> sans;
vector<int> ians;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; int x = 0;
        cin >> s;
        if (s != "removeMin") cin >> x;
        if (s == "insert") pq.push(x);
        else if (s == "getMin") {
            while (!pq.empty() && pq.top() < x) {
                sans.push_back("removeMin");
                ians.push_back(0);
                pq.pop();
            }

            if (pq.empty() || pq.top() != x) {
                sans.push_back("insert");
                ians.push_back(x);
                pq.push(x);
            }
        } else {
            if (pq.empty()) {
                sans.push_back("insert");
                ians.push_back(0);
            } else pq.pop();
        }

        sans.push_back(s);
        ians.push_back(x);
    }

    cout << sans.size() << '\n';
    for (int i = 0; i < sans.size(); i++) {
        cout << sans[i];
        if (sans[i] == "removeMin") cout << '\n';
        else cout << ' ' << ians[i] << '\n';
    }
}