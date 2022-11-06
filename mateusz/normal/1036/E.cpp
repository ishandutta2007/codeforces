#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
int xA[N], yA[N], xB[N], yB[N];

long long det(long long xA, long long yA, long long xB, long long yB, long long xC, long long yC) {
    return xA * yB + xB * yC + xC * yA - yA * xB - yB * xC - yC * xA;
}

int side(long long xA, long long yA, long long xB, long long yB, long long xC, long long yC) {
    auto val = det(xA, yA, xB, yB, xC, yC);
    if (val > 0) return 1;
    if (val == 0) return 0;
    return -1;
}

bool between(int x, int y, int k) {
    return min(xA[k], xB[k]) <= x &&
           x <= max(xA[k], xB[k]) && 
           min(yA[k], yB[k]) <= y && 
           y <= max(yA[k], yB[k]);
}

int main() {
    
    scanf("%d", &n);
    
    long long oneLine = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &xA[i], &yA[i], &xB[i], &yB[i]);
        int diffx = xB[i] - xA[i];
        int diffy = yB[i] - yA[i];
        if (diffx == 0 || diffy == 0) {
            oneLine += abs(diffx) + abs(diffy) + 1;
        } else {
            oneLine += __gcd(abs(diffx), abs(diffy)) + 1;
        }
    }
    
    
    set<pair<int, int> > points;
    map<pair<int, int>, int> cntOccur;
    
    for (int i = 1; i <= n; i++) {
        int diffx = xB[i] - xA[i];
        int diffy = yB[i] - yA[i];
        int cnt = 0;
        if (diffx == 0 || diffy == 0) {
            cnt = abs(diffx) + abs(diffy) + 1;
        } else {
            cnt = __gcd(abs(diffx), abs(diffy)) + 1;
        }
        int dx = diffx / (cnt - 1);
        int dy = diffy / (cnt - 1);
        cnt--;
        for (int j = i + 1; j <= n; j++) {
            int low = 0;
            int high = cnt;
            int initSide = side(xA[i], yA[i], xA[j], yA[j], xB[j], yB[j]);
            
//             cerr << i << " " << j << " " << low << " " << high << endl;
            if (initSide == 0 && between(xA[i], yA[i], j)) {
//             cerr << i << " " << j << " " << xA[i] << " " << yA[i] << " " << initSide << " " << dx << " " << dy << endl;
                points.insert({xA[i], yA[i]});
                    cntOccur[{xA[i], yA[i]}]++;
                continue;
            }
            while (low <= high) {
                int mid = (low + high) / 2;
                int x = xA[i] + dx * mid;
                int y = yA[i] + dy * mid;
                auto dSide = side(x, y, xA[j], yA[j], xB[j], yB[j]);
                if (dSide == 0 && between(x, y, j)) {
//                 cerr << i << " " << j << " " << x << " " << y << " " << dSide << " " << dx << " " << dy << " " << mid << endl;
                    points.insert({x, y});
                    cntOccur[{x, y}]++;
                    break;
                }
                if (dSide == initSide) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }
    
    long long toSub = 0;
    for (auto p : points) {
//         cerr << p.first << " " << p.second << endl;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (side(xA[i], yA[i], xB[i], yB[i], p.first, p.second) == 0 && between(p.first, p.second, i)) {
                cnt++;
            }
        }
        toSub += cnt - 1;
    }
//     for (auto p : cntOccur) {
//         int val = p.second;
//         toSub += (((int)sqrt(8 * val + 1) + 1) / 2) - 1;
//     }
//     cerr << oneLine << " " << toSub << endl;
    long long ans = oneLine - toSub;
    printf("%lld\n", ans);

    return 0;
}