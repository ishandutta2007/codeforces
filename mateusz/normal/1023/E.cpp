#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int> > cells, scells;

void makePath() {
    string ans;
    for (int i = 1; i < scells.size(); i++) {
        int dx = scells[i].first - scells[i - 1].first;
        int dy = scells[i].second - scells[i - 1].second;
        if (dx == 0 && dy == 0) continue;
        if (dx > 0) {
            ans += 'D';
        } else {
            ans += 'R';
        }
    }
    cout << "! " << ans << endl;
}

bool ask(int x, int y, int xx, int yy) {
    cout << "? " << x << " " << y << " " << xx << " " << yy << endl;
    string res;
    cin >> res;
    if (res == "YES") return true;
    else return false;
}

void firstStep(int x, int y) {
    if (x - 1 + y - 1 == n - 1) {
        return;
    }
    int xx, yy;
    if (x > 1) {
        xx = x - 1;
        yy = y;
    } else {
        xx = x;
        yy = y - 1;
    }
    bool res = ask(1, 1, xx, yy);
    if (res) {
        cells.push_back({xx, yy});
        firstStep(xx, yy);
    } else {
        if (x == xx) {
            xx = x - 1;
            yy = y;
        } else {
            xx = x;
            yy = y - 1;
        }
        cells.push_back({xx, yy});
        firstStep(xx, yy);
    }
}

void secondStep(int x, int y) {
    if (n - x + n - y == n - 1) {
        return;
    }
    int xx, yy;
    if (y < n) {
        xx = x;
        yy = y + 1;
    } else {
        xx = x + 1;
        yy = y;
    }
    bool res = ask(xx, yy, n, n);
    if (res) {
        scells.push_back({xx, yy});
        secondStep(xx, yy);
    } else {
        if (x == xx) {
            xx = x + 1;
            yy = y;
        } else {
            xx = x;
            yy = y + 1;
        }
        scells.push_back({xx, yy});
        secondStep(xx, yy);
    }
}

int main() {
    
    cin >> n;
    cells.push_back({n, n});
    firstStep(n, n);
    scells.push_back({1, 1});
    secondStep(1, 1);
    
    reverse(cells.begin(), cells.end());
    for (auto p : cells) {
        scells.push_back(p);
    }
    
    makePath();
    
    return 0;
}