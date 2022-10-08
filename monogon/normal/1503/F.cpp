
#include <bits/stdc++.h>

using namespace std;

struct curve {
    list<int> a, b;
    curve() {}
    curve(int x) {
        a.push_back(x);
        b.push_back(x);
    }
    curve& operator+=(curve &o) {
        a.splice(a.end(), o.a);
        o.b.splice(o.b.end(), b);
        b.swap(o.b);
        return *this;
    }
    curve& rev() {
        a.swap(b);
        return *this;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> openfront(n + 1), closefront(n + 1), openback(n + 1), closeback(n + 1), a(2 * n), b(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] > 0) openfront[a[i]] = i;
        else closefront[-a[i]] = i;
        if(b[i] > 0) openback[b[i]] = i;
        else closeback[-b[i]] = i;
    }
    vector<bool> vis(2 * n, false);
    vector<int> ans, ve;
    stack<int> st;
    stack<curve*> stnode;
    string s;
    for(int i = 0; i < 2 * n; i++) {
        if(!vis[i]) {
            ve.clear();
            s.clear();
            int x = i;
            int cnt = 0;
            do {
                ve.push_back(x);
                vis[x] = true;
                if(a[x] > 0) {
                    cnt++;
                    s.push_back('1');
                    x = closefront[a[x]];
                }else {
                    s.push_back('0');
                    x = openfront[-a[x]];
                }
                ve.push_back(x);
                vis[x] = true;
                if(b[x] > 0) {
                    s.push_back('0');
                    x = closeback[b[x]];
                }else {
                    cnt++;
                    s.push_back('1');
                    x = openback[-b[x]];
                }
            }while(x != i);
            if(cnt == (int) s.length() / 2 - 1) {
                cnt = s.length() - cnt;
                for(char &c : s) c = (c == '0' ? '1' : '0');
            }
            if(cnt != (int) s.length() / 2 + 1) {
                cout << "NO\n";
                return 0;
            }
            int idx = 0;
            while(s[idx] == '0' || s[idx + 1] == '0') idx++;
            rotate(s.begin(), s.begin() + idx, s.end());
            rotate(ve.begin(), ve.begin() + idx, ve.end());
            stnode.push(new curve(0));
            for(int j = (int) s.length() - 1; j >= 2; j--) {
                if(st.empty() || s[st.top()] == s[j]) {
                    st.push(j);
                    stnode.push(new curve());
                }else {
                    curve *x = new curve(j), *y = new curve(st.top()), *z = stnode.top();
                    st.pop();
                    stnode.pop();
                    if(s[j] == '0') {
                        *x += *y;
                        *x += z->rev();
                        *x += *stnode.top();
                        stnode.pop();
                        stnode.push(x);
                    }else {
                        curve *w = stnode.top();
                        stnode.pop();
                        *w += z->rev();
                        *w += *y;
                        *w += *x;
                        stnode.push(w);
                    }
                }
            }
            assert(st.empty());
            assert((int) stnode.size() == 1);
            curve *y = stnode.top();
            y->a.push_front(1);
            y->b.push_back(1);
            if(a[ve[1]] < 0) y->rev();
            for(int idx : y->a) {
                ans.push_back(ve[idx]);
            }
            stnode.pop();
        }
    }
    cout << "YES\n";
    for(int i : ans) {
        cout << a[i] << ' ' << b[i] << '\n';
    }
}