#include <algorithm>
#include <cassert>
#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;

typedef map<int, int> mii;

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<mii> trie;

#define MAXN 2100

trie t1, t2;
vi idx1, idx2;

inline void add1(const string &s, int from, int to)
{
    int curIdx = 0;
    for (int i = from; i <= to; i++) {
        if (t1[curIdx].find(s[i]) == t1[curIdx].end()) {
            t1[curIdx][s[i]] = t1.size();
            t1.push_back(mii());
            idx1.push_back(i);
        }
        curIdx = t1[curIdx][s[i]];
    }
}

inline void add2(const string &s, int from, int to)
{
    int curIdx = 0;
    for (int i = to; i >= from; i--) {
        if (t2[curIdx].find(s[i]) == t2[curIdx].end()) {
            t2[curIdx][s[i]] = t2.size();
            t2.push_back(mii());
            idx2.push_back(i);
        }
        curIdx = t2[curIdx][s[i]];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    t1.push_back(mii());
    idx1.push_back(-1);
    t2.push_back(mii());
    idx2.push_back(-1);

    string s, t;
    cin >> s >> t;

    int ns = s.size(), nt = t.size();

    for (int i = ns; i--; ) {
        add1(s, i, ns - 1);
        add2(s, 0, i);
    }

    vi minSteps(nt + 1, 2147483647);
    vii lastAdd(nt + 1, pii(-1, -1));

    minSteps[0] = 0;

    for (int i = 0; i < nt; i++) {
        int ptr = 0;

        // forward:
        for (int j = i; j < nt; j++) {
            if (t1[ptr].find(t[j]) == t1[ptr].end()) {
                break;
            }

            ptr = t1[ptr][t[j]];

            // j - i + 1 characters
            if (minSteps[j + 1] > minSteps[i] + 1) {
                minSteps[j + 1] = minSteps[i] + 1;

                int endInS = idx1[ptr];
                lastAdd[j + 1] = pii(endInS - (j - i), endInS);
            }
        }

        ptr = 0;
        // reverse:
        for (int j = i; j < nt; j++) {
            if (t2[ptr].find(t[j]) == t2[ptr].end()) {
                break;
            }

            ptr = t2[ptr][t[j]];

            if (minSteps[j + 1] > minSteps[i] + 1) {
                minSteps[j + 1] = minSteps[i] + 1;

                int endInS = idx2[ptr];
                lastAdd[j + 1] = pii(endInS + (j - i), endInS);
            }
        }
    }

    vii ans;

    int len = nt;
    while (len > 0) {

        if (lastAdd[len].first == -1 && lastAdd[len].second == -1) {
            cout << "-1" << endl;
            return 0;
        }

        ans.push_back(pii(lastAdd[len].first + 1, lastAdd[len].second + 1));
//		cout << (lastAdd[len].first + 1) << " " << (lastAdd[len].second + 1) << endl;
        int diff = abs(lastAdd[len].first - lastAdd[len].second) + 1;
//        assert(minSteps[len - diff] == minSteps[len] - 1);
        len -= diff;
    }

    cout << ans.size() << endl;
    for (int i = ans.size(); i--; ) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

//	for (int i = 0; i <= nt; i++) {
//		cout << i << ": " << minSteps[i] << "\t" << lastAdd[i].first << ", " << lastAdd[i].second << endl;
//	}

    return 0;
}