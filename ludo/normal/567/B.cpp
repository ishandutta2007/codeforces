#include<bits/stdc++.h>

using namespace std;

typedef pair<int, bool> pib;

#define MAX 100

int n, id[MAX];
bool enter[MAX];

set<int> cnt[MAX];

map<int, int> mapping;
int rev_mapping[MAX], n_vals;

vector<pib> events[MAX];

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#endif // LOCAL
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch >> id[i];
        enter[i] = (ch == '+');
    }

    for (int i = 0; i < n; i++) {
        if (mapping.find(id[i]) == mapping.end()) {
            mapping[id[i]] = n_vals;
            rev_mapping[n_vals++] = id[i];
        }

        events[mapping[id[i]]].push_back(make_pair(i, enter[i]));
    }

    vector<int> ids_start;

    for (int i = 0; i < n_vals; i++) {
//        cerr << rev_mapping[i] << ": ";

        if (events[i].size() > 0 && !events[i][0].second) {
            ids_start.push_back(i);
        }

//        for (int j = 0; j < events[i].size(); j++) {
//            cerr << "(" << events[i][j].first << "," << events[i][j].second << ") ";
//        }
//        cerr << endl;
    }

    bool isinside[MAX];

    for (int i = 0; i < n_vals; i++) isinside[i] = false;

    int curcnt = 0;
    while (!ids_start.empty()) {
        isinside[ids_start.back()] = true;
        curcnt++;
        ids_start.pop_back();
    }

    int maxcnt = curcnt;

    for (int i = 0; i < n; i++) {
        int m = mapping[id[i]];

//        cerr << i << " " << m << " " << enter[i] << " " << isinside[m] << endl;

        if (enter[i]) {
            assert(!isinside[m]);
            isinside[m] = true;
            curcnt++;
        } else {
            assert(isinside[m]);
            isinside[m] = false;
            curcnt--;
        }
        maxcnt = max(maxcnt, curcnt);
    }

    cout << maxcnt << endl;

    return 0;
}