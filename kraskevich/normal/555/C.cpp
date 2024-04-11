#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9 + 10;

struct Tree {
    vector<int> data;
    int size;

    Tree(int n) {
        size = n;
        data.assign(4 * n + 10, INF);  
    }

    void put(int i, int tl, int tr, int pos, int val) {
        data[i] = min(data[i], val);
        if (tl == tr) {
            return;
        }
        int m = (tl + tr) / 2;
        if (pos <= m)
            put(2 * i + 1, tl, m, pos, val);
        else
            put(2 * i + 2, m + 1, tr, pos, val);
    }

    void put(int pos, int val) {
        put(0, 0, size - 1, pos, val);
    }

    int getMin(int i, int tl, int tr, int l, int r) {
        if (l == tl && r == tr)
            return data[i];
        int ml = INF;
        int mr = INF;
        int m = (tl + tr) / 2;
        if (l <= m)
            ml = getMin(2 * i + 1, tl, m, l, min(r, m));
        if (r > m)
            mr = getMin(2 * i + 2, m + 1, tr, max(m + 1, l), r);
        return min(ml, mr);
    }

    int get(int l, int r) {
        return getMin(0, 0, size - 1, l, r);
    }
};

const int N = 200 * 1000 + 10; 

vector<int> all;
int x[N];
int y[N];
string dir[N];
int n;

int getId(int p) {
   return lower_bound(all.begin(), all.end(), p) - all.begin();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> y[i] >> x[i];
        cin >> dir[i];
        all.push_back(x[i]);
        all.push_back(y[i]);
    }     
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    Tree vert(all.size());
    Tree hor(all.size());
    int tot = all.size();
    for (int i = 0; i < q; i++) {
        int sX = getId(x[i]);
        int sY = getId(y[i]);
        if (dir[i] == "U") {
            if (vert.get(sY, sY) != INF || hor.get(sX, sX) != INF) {
                cout << 0 << "\n";
                continue;
            }
            if (hor.get(0, sX) > y[i]) {
                cout << x[i] << "\n";
                vert.put(sY, 1);  
                continue;
            }
            int low = 0;
            int high = sX;
            while (high - low > 1) {
                int mid = (low + high) / 2;
                if (hor.get(mid, sX) <= y[i])
                    low = mid;
                else
                    high = mid;
            }
            int upX = all[low];
            cout << x[i] - upX << "\n";
            vert.put(sY, upX);                              
        } else {
            if (vert.get(sY, sY) != INF || hor.get(sX, sX) != INF) {
                cout << 0 << "\n";
                continue;
            }
            //cerr << vert.get(0, sY) << " " << x[i] << " " << endl;
            if (vert.get(0, sY) > x[i]) {
                cout << y[i] << "\n";
                hor.put(sX, 1);
                continue;
            }
            int low = 0;
            int high = sY;
            while (high - low > 1) {
                int mid = (low + high) / 2;
                if (vert.get(mid, sY) <= x[i])
                    low = mid;
                else
                    high = mid;
            }
            int upY = all[low];
            cout << y[i] - upY << "\n";
            hor.put(sX, upY);                        
        }
    }
    return 0;

}