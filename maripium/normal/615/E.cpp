#include<bits/stdc++.h>
using namespace std;

long long t;

int main() {
    cin >> t;
    long long r = (sqrt(t * 3 + 1) - 1) / 3;
    long long step = r + 1, pos, cur = 0;
    t -= 1LL * (r * 3 + 2) * r;
    for(pos = 1; pos <= 6; ++pos) {
        cur += step;
        if(pos == 2) cur--;
        if(cur > t) {
            if(pos == 2) cur -= (step - 1);
            else cur -= step;
            break;
        }
    }
    long long x,y;
    t -= cur;
    if(pos == 1) {
        x = r + t;
        y = -2*r + t*2;
    }
    else if(pos == 2) {
        x = 1 + 2*r - t;
        y = 2 + 2*t;
    }
    else if(pos == 3) {
        x = 1 + r - 2*t;
        y = 2 + 2*r;
    }
    else if(pos == 4) {
        x = -1 - r - t;
        y = 2 + 2*r - 2*t;
    }
    else if(pos == 5) {
        x = -2 + -2*r + t;
        y = -2*t;
    }
    else {
        x = -1 + -r + 2*t;
        y = -2 + -2*r;
    }
    cout << x << ' ' << y << '\n';
}