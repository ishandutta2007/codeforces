#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

struct MyStack {
    int cnt = 0;
    int allOpens = 0;
    stack<int> s;
    stack<int> minValue;
    stack<int> maxValue;

    void push(int x) {
        s.push(x);
        cnt += x;
        if (x == 1) {
            allOpens += 1;
        }
        minValue.push((minValue.size() ? min(minValue.top(), cnt) : cnt));
        maxValue.push((maxValue.size() ? max(maxValue.top(), cnt) : cnt));
    }

    void pop() {
        if (s.size() == 0) {
            return;
        }
        cnt -= s.top();
        if (s.top() == 1) {
            allOpens -= 1;
        }
        s.pop();
        minValue.pop();
        maxValue.pop();
    }

    int top() {
        return s.top();
    }

    bool isCorrect() {
        return (minValue.size() == 0 || minValue.top() >= 0);
    }

    int depth() {
        return (maxValue.size() ? maxValue.top() : 0);
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    MyStack left, right;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        right.push(0);
    }
    left.push(0);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (pos != 0) {
                pos--;
                right.push(-left.top());
                left.pop();
            }
        } else if (s[i] == 'R') {
            pos++;
            left.push(-right.top());
            right.pop();
        } else if (s[i] == '(') {
            left.pop();
            left.push(1);
        } else if (s[i] == ')') {
            left.pop();
            left.push(-1);
        } else {
            left.pop();
            left.push(0);
        }
        if (left.isCorrect() && right.isCorrect() && left.cnt == right.cnt) {
            cout << max({left.depth(), right.depth(), left.cnt}) << " ";
        } else {
            cout << "-1 ";
        }
    }
}