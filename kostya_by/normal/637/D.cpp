#include <bits/stdc++.h>

using namespace std;

vector<int> obj;
unordered_set<int> has;
unordered_map<int, int> fromland, fromjump;
int n, m, s, d;
vector<int> posland, posjump;
vector<pair<string, int> > out;
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        obj.push_back(x);
        has.insert(x);
    }
    sort(obj.begin(), obj.end() );
    posland.push_back(0);
    for (int i = 0; i < obj.size(); i++) {
        int x = obj[i] - 1;
        int pr = -1;
        if (i > 0) {
            pr = obj[i - 1];
        }
        if (has.find(x) == has.end() ) {
            int wh = posland.back();
            if (wh > pr) {
                if (x - wh >= s) {
                    posjump.push_back(x);
                    fromjump[x] = wh;
                }
            }
        }
        x = obj[i] + 1;
        if (has.find(x) == has.end() ) {
            auto it = lower_bound(posjump.begin(), posjump.end(), x - d);
            if (it != posjump.end() ) {
                int wh = *it;
                posland.push_back(x);
                fromland[x] = wh;
            }
        }
    }
    if (posland.back() != obj.back() + 1) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int cur = obj.back() + 1;
    bool land = true;
    while (cur > 0) {
        if (land == true) {
            out.push_back( make_pair("JUMP", cur - fromland[cur]) );
            cur = fromland[cur];
        }
        else {
            out.push_back( make_pair("RUN", cur - fromjump[cur]) );
            cur = fromjump[cur];
        }
        land ^= 1;
    }

    reverse(out.begin(), out.end() );

    if (m > obj.back() + 1) {
        out.push_back( make_pair("RUN", m - obj.back() - 1) );
    }

    for (int i = 0; i < out.size(); i++) {
        for (int j = 0; j < out[i].first.length(); j++) {
            printf("%c", out[i].first[j]);
        }
        printf(" ");
        printf("%d\n", out[i].second);
    }

    return 0;
}