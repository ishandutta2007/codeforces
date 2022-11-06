#include <bits/stdc++.h>

using namespace std;

int n, value;
string operationType;

int main() {

    ios_base::sync_with_stdio(0);

    cin >> n;
    vector<pair<string, int> > answer;
    priority_queue<int> Q;
    for (int i = 1; i <= n; i++) {
        cin >> operationType;
        if (operationType == "insert") {
            cin >> value;
            answer.push_back({"insert", value});
            Q.push(-value);

        } else if (operationType == "getMin") {
            cin >> value;
            while (!Q.empty() && -Q.top() < value) {
                Q.pop();
                answer.push_back({"removeMin", 5});
            }
            if (Q.empty() || -Q.top() > value) {
                Q.push(-value);
                answer.push_back({"insert", value});
            }
            answer.push_back({"getMin", value});

        } else {
            if (Q.empty()) {
                answer.push_back({"insert", 1});
            } else {
                Q.pop();
            }
            answer.push_back({"removeMin", 5});
        }
    }

    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i].first;
        if (answer[i].first != "removeMin") {
            cout << " " << answer[i].second;
        }
        cout << endl;
    }

    return 0;
}