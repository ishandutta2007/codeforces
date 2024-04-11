#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

inline bool is_symb(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

inline bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main() {

    string s;

    cin >> s;

    vec< pair< string, int > > mas;

    for(int i = 0;i < (int)s.size();i++) {
        string t = "";
        int j = i;
        while(j < (int)s.size() && is_symb(s[j])) {
            t.push_back(s[j++]);
        }
        j++;
        int val = 0;
        while(j < (int)s.size() && is_digit(s[j])) {
            val = val * 10 + s[j++] - '0';
        }
        mas.push_back( make_pair(t, val) );
        i = j;
    }

    int sz = (int)mas.size();

    vec< vec< int > > g(sz);
    set< int > Q;

    for(int i = sz - 1;i >= 0;i--) {
//        cout << mas[i].first << " : ";
//        {
//            auto it = Q.begin();
//            for(int j = 0;j < mas[i].second;j++) {
//                cout << mas[*it].first << " ";
//                it++;
//            }
//        }
//        cout << "\n";
        auto it = Q.begin();
        for(int j = 0;j < mas[i].second;j++) {
            g[i].push_back(*it);
            it = Q.erase(it);
        }
        Q.insert(i);
    }

//    cout << "\nok\n";
//    for(int i = 0;i < sz;i++) {
//        cout << mas[i].first << " : ";
//        for(int j : g[i]) {
//            cout << mas[j].first << " ";
//        }
//        cout << "\n";
//    }

//    cout << "\n";

    queue< int > que;
    vec< int > depth(sz, -1);

    for(int st = 0;st < sz;st++) {
        if(depth[st] != -1) continue;
        que.push(st);
        depth[st] = 0;
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(int to : g[v]) {
                depth[to] = depth[v] + 1;
                que.push(to);
            }
        }
    }

    int mx = *max_element(ALL(depth)) + 1;

    vec< vec< int > > res(mx);

    for(int i = 0;i < sz;i++) {
        res[ depth[i] ].push_back(i);
    }

    printf("%d\n", mx);

    for(int i = 0;i < mx;i++) {
        for(int idx : res[i]) {
            for(char c : mas[idx].first) {
                printf("%c", c);
            }
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}