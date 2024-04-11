#include <bits/stdc++.h>

using namespace std;


struct Bit {
    vector<int> f;

    Bit(int n=0) { 
        f.resize(n); 
    }
    
    void upd(int at, int by) {
        for (; at < f.size(); at = (at | (at + 1)))
            f[at] += by;
    }

    int get(int at) {
        int s = 0;
        for (; at >= 0; at = (at & (at + 1)) - 1)
            s += f[at];
        return s;
    }
};

const int N = 100 * 1000 + 10;

int aa[N];
int tt[N];
int xx[N];

map<int, vector<int>> pp;
map<int, Bit> bb; 
set<int> all;

void process(vector<int>& v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

int getPos(const vector<int>& v, int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aa[i] >> tt[i] >> xx[i];
        all.insert(xx[i]);
        pp[xx[i]].push_back(tt[i]);
    }
    for (int x : all) { 
        process(pp[x]);
        bb[x] = Bit(pp[x].size());
    }   
    for (int i = 0; i < n; i++) {
        if (aa[i] == 1) 
            bb[xx[i]].upd(getPos(pp[xx[i]], tt[i]), 1);
        else if (aa[i] == 2)
            bb[xx[i]].upd(getPos(pp[xx[i]], tt[i]), -1);
        else
            cout << bb[xx[i]].get(getPos(pp[xx[i]], tt[i])) << "\n";
    }
    return 0;
}