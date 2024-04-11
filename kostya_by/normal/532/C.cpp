#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool strategy(int x1, int y1, int x2, int y2, int type) {
    set<pair<int, int> > taken[2];
    taken[0].insert(make_pair(x1, y1) );
    taken[1].insert(make_pair(x2, y2) );

    int turn = 0;
    while (true) {
        if (x1 + y1 == 0) {
            return true;
        }
        if (x2 + y2 == 0) {
            return false;
        }
        if (turn == 0) {
            if (type == 1) {
                if (x1 > 0) {
                    x1 -= 1;
                } else {
                    y1 -= 1;
                }
            } else {
                if (y1 > 0) {
                    y1 -= 1;
                } else {
                    x1 -= 1;
                }
            }
            
            if (taken[1].find(make_pair(x1, y1) ) != taken[1].end() ) {
                return false;
            }
            taken[0].insert(make_pair(x1, y1) );
        } else {
            if (x2 > 0) {
                x2 -= 1;
            }
            y2 -= 1;
            
            if (taken[0].find(make_pair(x2, y2) ) != taken[0].end() ) {
                return true;
            }
            taken[1].insert(make_pair(x2, y2) );
        }
        turn ^= 1;
    }
}

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x2 > y2) {
        swap(x1, y1);
        swap(x2, y2);
    }
    if (strategy(x1, y1, x2, y2, 1) || strategy(x1, y1, x2, y2, 2) ) {
        cout << "Polycarp\n";
    } else {
        cout << "Vasiliy\n";
    }
}

int main() {
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
    return 0;
}