#include <bits/stdc++.h>

using namespace std;

const int N = 500005, M = 1000000007;

int n;
char moves[N];
vector<int> iksy, igreki;
int momentGora[N], momentDol[N], momentLewo[N], momentPrawo[N];

int minX, minY, maxX, maxY;
int curX, curY;

void add(int &w, int v) {
    w += v;
    if (w >= M) {
        w -= M;
    }
}

int solve(int h, int w) {
    int wynik = 0;
    
    for (int i = 1; i <= n; i++) {
        if (moves[i] == 'U') {
            curY++;
            if (curY > maxY) {
                maxY = curY;
                momentGora[curY] = i;
                if (minY + maxY <= h){
                    add(wynik,  (long long)i * max(0, (w - minX - maxX)) % M);
                }
            }
        } else if (moves[i] == 'D') {
            curY--;
            if (-curY > minY) {
                minY = -curY;
                momentDol[minY] = i;
                if (minY + maxY <= h) {
                    add(wynik,  (long long)i * max(0, (w - minX - maxX)) % M);
                }
            }
        } else if (moves[i] == 'L') {
            curX--;
            if (-curX > minX) {
                minX = -curX;
                momentLewo[minX] = i;
                if (minX + maxX <= w) {
                    add(wynik, (long long)i * max(0, (h - minY - maxY)) % M);
                }
            }
        } else {
            curX++;
            if (curX > maxX) {
                maxX = curX;
                momentPrawo[maxX] = i;
                if (minX + maxX <= w) {
                    add(wynik, (long long)i * max(0, (h - minY - maxY)) % M);
                }  
            }
        }
    }
    
//     cerr << minX << " " << maxX << " " << minY << " " << maxY << endl;
    
    if (curX > 0) {
        for (int i = maxX - curX + 1; i <= maxX; i++) {
            iksy.push_back(momentPrawo[i]);
        }
    } else {
        for (int i = minX + curX + 1; i <= minX; i++) {
            iksy.push_back(momentLewo[i]);
        }
        curX *= -1;
    }
    
    if (curY > 0) {
        for (int i = maxY - curY + 1; i <= maxY; i++) {
            igreki.push_back(momentGora[i]);
        }
    } else {
        for (int i = minY + curY + 1; i <= minY; i++) {
            igreki.push_back(momentDol[i]);
        }
        curY *= -1;
    }
    
//     cerr << "wynik: " << wynik << endl;
    return wynik;
}


int main() {
    int h, w;
    scanf("%d %d %d", &n, &h, &w);
    scanf("%s", &moves[1]);
    
    int wynik = solve(h, w);

    
//     cerr << curX << " " << curY << endl;
    if (minX + maxX < w && minY + maxY < h && curX == 0 && curY == 0) {
        printf("-1\n");
        return 0;
    } else {
        if (minX + maxX < w && minY + maxY < h) {
            h = h - maxY - minY;
            w = w - maxX - minX;
            int pelneKolka = 1;
            vector<pair<int, int> > v;
            for (int i = 0; i < igreki.size(); i++) {
                v.push_back({igreki[i], 0});
            }
            for (int i = 0; i < iksy.size(); i++) {
                v.push_back({iksy[i], 1});
            }
            sort(v.begin(), v.end());
            while(h > 0 && w > 0) {
//                 cerr << "h, w: " << h << " " << w << endl;
                int pionowe = 0, poziome = 0;
                for (int i = 0; i < v.size(); i++) {
                    int moment = v[i].first;
                    int kierunek = v[i].second;
//                     cerr << moment << endl;
                    if (kierunek == 0) {
                        if (pionowe < h)
                        add(wynik, (((long long)pelneKolka * n % M + moment) % M * max(0, (w - poziome))) % M);
                        pionowe++;
                    } else {
                        if (poziome < w)
                        add(wynik, (((long long)pelneKolka * n  % M + moment) % M * max(0, (h - pionowe))) % M);
                        poziome++;
                    }
                }
                
                w -= curX;
                h -= curY;
                pelneKolka++;
            }
        }
    }
    printf("%d\n", wynik);
    
    return 0;
}