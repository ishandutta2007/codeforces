#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    void in() {
        scanf("%d%d", &x, &y);
    }
}a[1000010];

void calc(const vector<int> &vec, int lX,int rX,int lY,int rY) {
    if(vec.empty()) return;
    if(vec.size() <= 2) {
        for(int u:vec) printf("%d ", u+1);
        return;
    }
    vector<int> c[2][2];
    int mX = (lX + rX) / 2, mY = (lY + rY) / 2;
    for(int i:vec) c[a[i].x>=mX][a[i].y>=mY].push_back(i);
    calc(c[0][0], lX, mX, lY, mY);
    calc(c[0][1], lX, mX, mY, rY);
    calc(c[1][1], mX, rX, mY, rY);
    calc(c[1][0], mX, rX, lY, mY);
}

int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i) a[i].in();
    vector<int> vec;
    for(int i = 0; i < n; ++i) vec.push_back(i);
    calc(vec, 0, 1000001, 0, 1000001);
}