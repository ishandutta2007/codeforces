#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <fstream>

using namespace std;

//#define cin fin

int main()
{
    //ifstream fin("input.txt");
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<long long, vector<int> > m;
    set<long long> s;
    for (int i = 0; i < n; i++) {
        if (m.count(a[i]) == 0) {
            vector<int> v(1, i);
            m[a[i]] = v;
            s.insert(a[i]);
        }
        else {
            m[a[i]].push_back(i);
        }
    }
    vector< pair<int, long long> > b;
    while (!s.empty()) {
        long long u = *s.begin();
        s.erase(s.begin());
        vector<int> v = m[u];
        while (v.size() > 0) {
            /*cout << u << " : ";
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << endl;*/
            if (v.size() % 2 == 1) {
                b.push_back(make_pair(v[v.size() - 1], u));
                v.pop_back();
            }
            vector<int> v1 = v;
            v.clear();
            u *= 2ll;
            if (m.count(u) == 0) {
                for (int i = 1; i < v1.size(); i += 2) {
                    v.push_back(v1[i]);
                }
            }
            else {
                int i1 = 1;
                int i2 = 0;
                if (s.find(u) != s.end()) {
                    s.erase(u);
                }
                while (i1 < v1.size() || i2 < m[u].size()) {
                    if (i1 >= v1.size()) {
                        v.push_back(m[u][i2]);
                        i2++;
                    }
                    else if (i2 == m[u].size()) {
                        v.push_back(v1[i1]);
                        i1 += 2;
                    }
                    else {
                        if (v1[i1] < m[u][i2]) {
                            v.push_back(v1[i1]);
                            i1 += 2;
                        }
                        else {
                            v.push_back(m[u][i2]);
                            i2++;
                        }
                    }
                }
            }
        }
        /*
        if (m[u].size() < 2) {
            b.push_back(pair<int, long long> (m[u][0], u));
            continue;
        }
        int c = m[u].size() / 2;
        if (m[u].size() % 2 == 1) {
            b.push_back(pair<int, long long> (m[u][m[u].size() - 1], u));
        }
        if (m.count(2ll * u) == 0) {
            if (c == 1) {
                b.push_back(make_pair(m[u][1], 2ll * u));
                continue;
            }
            else {
                s.insert(2ll * u);
                vector<int> v;
                m[2ll * u] = v;
            }
        }
        for (int i = 0; i < c; i++) {
            m[2ll * u].push_back(m[u][2 * i + 1]);
            sort(m[2ll * u].begin(), m[2ll * u].end());
        }*/
    }
    sort(b.begin(), b.end());
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++) {
        cout << b[i].second << ' ';
    }
}