#include <bits/stdc++.h>

using namespace std;

struct Event {
    int coord;
    int cnt;
    int type; // 0 - a new point appears 1 - a point disappears

    Event(int coord = 0, int cnt = 0, int type = 0): coord(coord), cnt(cnt), type(type) {}

    bool operator < (const Event& e) const {
        if (coord != e.coord)
            return coord < e.coord;
        return type < e.type;
    }
};

const int N = (int) 1e5 + 10;
map<int, int> countAt;
long long ans[N];
int n;
int k;

void processLayer(long long mult) {
    if (mult == 0)
        return;
    vector<Event> opens;
    vector<Event> closes;
    vector<Event> all(countAt.size() * 2);
    opens.reserve(countAt.size());
    closes.reserve(countAt.size());
    for (pair<int, int> p: countAt) {
        opens.push_back(Event(p.first - k + 1, p.second, 0));
        closes.push_back(Event(p.first + 1, p.second, 1)); 
    }  
    merge(opens.begin(), opens.end(), closes.begin(), closes.end(), all.begin());
    long long curCnt = 0;
    for (int i = 0; i < all.size(); i++) {
        if (all[i].type == 0)
            curCnt += all[i].cnt;
        else
            curCnt -= all[i].cnt;
        if (curCnt != 0)
            ans[curCnt] += (all[i + 1].coord - all[i].coord) * mult;       
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    vector<Event> e;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e.push_back(Event(x - k + 1, y, 0));
        e.push_back(Event(x + 1, y, 1));
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < e.size(); i++) {
        if (e[i].type == 0)
            countAt[e[i].cnt]++;
        else {
            countAt[e[i].cnt]--;
            if (countAt[e[i].cnt] == 0)
                countAt.erase(e[i].cnt);
        }
        if (countAt.size() != 0)
            processLayer(e[i + 1].coord - e[i].coord);        
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}