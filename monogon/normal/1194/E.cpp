
#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

const int MAX_COORD = 10005;
const int MAX_N = 5005;
int bit[MAX_COORD];
int n, x1, y1, x2, y2;

int getSum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}
void add(int k, int x) {
    while(k <= MAX_COORD) {
        bit[k] += x;
        k += k & -k;
    }
}

struct segment {
    // x1 <= x2, y1 <= y2
    int x1;
    int y1;
    int x2;
    int y2;
    segment() {
        x1 = y1 = x2 = y2 = 0;
    }
    segment(int x1, int y1, int x2, int y2) {
        this->x1 = min(x1, x2);
        this->x2 = max(x1, x2);
        this->y1 = min(y1, y2);
        this->y2 = max(y1, y2);
    }
    bool operator<(const segment &s) const {
        if(y2 == s.y2) {
            if(y1 == y2 || s.y1 == s.y2) {
                return y1 == y2;
            }
            return x1 < s.x1;
        }
        return y2 < s.y2;
    }
};

segment segs[MAX_N];
bool good[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        segs[i] = segment(x1 + 5001, y1 + 5001, x2 + 5001, y2 + 5001);
    }
    sort(segs, segs + n);

    ll tot = 0;
    for(int i = 0; i < n; i++) {
        if(segs[i].y1 == segs[i].y2) {
            // lower horizontal segment
            // clear fenwick tree
            fill(bit, bit + MAX_COORD, 0);
            fill(good, good + n, false);
            // mark good vertical edges
            for(int j = 0; j < n; j++) {
                if(segs[j].x1 == segs[j].x2 && segs[j].x1 >= segs[i].x1 &&
                        segs[j].x1 <= segs[i].x2 && segs[j].y1 <= segs[i].y1 && segs[j].y2 >= segs[i].y1) {
                    add(segs[j].x1, 1);
                    good[j] = true;
                }
            }
            // queries
            for(int j = i + 1; j < n; j++) {
                if(good[j]) {
                    add(segs[j].x1, -1);
                }else if(segs[j].y1 == segs[j].y2) {
                    ll s = getSum(segs[j].x2) - getSum(segs[j].x1 - 1);
                    tot += (s * (s - 1)) / 2;
                }
            }
        }
    }
    cout << tot << endl;
}