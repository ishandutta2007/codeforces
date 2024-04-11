#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int n, q;
int m[max_n];
int fst[max_n];
int lst[max_n];

int main()
{
    memset(fst, -1, sizeof(fst));
    memset(lst, -1, sizeof(lst));
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    int mx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        int a = m[i];
        if (fst[a] == -1) {
            fst[a] = i;
        }
        lst[a] = max(lst[a], i);
        mx = max(mx, m[i]);
    }
    if (mx < q) {
        for (int i = 0; i < n; ++i) {
            if (m[i] == 0) {
                m[i] = q;
                mx = -1;
                fst[q] = lst[q] = i;
                break;
            }
        }
        if (mx != -1) {
            cout << "NO";
            return 0;
        }
    }

    lst[1] = n - 1;
    fst[1] = 0;
    for (int i = 0; i < n; ++i) {
        if (m[i] == 0) {
            m[i] = 1;
        } else {
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (m[i] == 0) {
            m[i] = 1;
        } else {
            break;
        }
    }
    stack<int> st;
    st.push(1);
    for (int i = 0; i < n; ++i) {
        if (m[i] == 0) {
            m[i] = st.top();
            continue;
        }
        if (m[i] < st.top()) {
            cout << "NO";
            return 0;
        } else if (m[i] > st.top()) {
            if (fst[m[i]] != lst[m[i]]) {
                st.push(m[i]);
            }
        } else {
            if (lst[m[i]] == i) {
                st.pop();
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << m[i] << ' ';
    }


    return 0;
}