
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, k, id;
set<int> screen;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> id;
        if(screen.count(id) == 0) {
            if((int) q.size() == k) {
                screen.erase(screen.find(q.front()));
                q.pop();
            }
            q.push(id);
            screen.insert(id);
        }
    }
    stack<int> st;
    while(q.size()) {
        st.push(q.front());
        q.pop();
    }
    cout << st.size() << endl;
    while(st.size()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}