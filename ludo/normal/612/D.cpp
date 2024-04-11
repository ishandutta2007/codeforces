#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef pair<int, int> pii;

#define MAXN (1000 * 1000)

int n, k, a[MAXN], b[MAXN];

int nevents = 0;
pii events[2 * MAXN];

vector<pii> answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

        events[nevents++] = pii(a[i], 0);
        events[nevents++] = pii(b[i], 1);
    }

    sort(events, events + nevents);
    int active = 0;

    int curStart = -2147483647;

    for (int i = 0; i < nevents; i++) {
        int cur_spot = events[i].first;
        bool add = events[i].second == 0;
        if (add) {
            if (++active == k) {
//                startSegment = cur_spot;
                curStart = cur_spot;
//                cerr << "START: " << cur_spot << endl;
            }
        } else {
            if (active-- == k) {
//                endSegment = cur_spot;
                answer.push_back(pii(curStart, cur_spot));
//                cerr << "END:   " << cur_spot << endl;
            }
        }
    }

    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i].first << " " << answer[i].second << endl;
    }

    return 0;
}