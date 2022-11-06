#include <bits/stdc++.h>

using namespace std;
const int N = 200000;
int n;
int kol[N + 5], wie[N + 5];
vector<int> kolumna[N + 5], wiersz[N + 5];
int kolor[N + 5], odw[N + 5];

void DFS(int w, int czyWiersz, int parz) {
    if(czyWiersz) {
        while(!wiersz[w].empty()) {
            int kr = wiersz[w].back();
            if(odw[kr]) wiersz[w].pop_back();
            else break;
        }
        if(wiersz[w].empty())
            return;
        int kr = wiersz[w].back();
        wiersz[w].pop_back();
        odw[kr] = true;
        kolor[kr] = parz;
        DFS(kol[kr], 0, 1 - parz);
    } else {
        while(!kolumna[w].empty()) {
            int kr = kolumna[w].back();
            if(odw[kr]) kolumna[w].pop_back();
            else break;
        }
        if(kolumna[w].empty()) return;
        int kr = kolumna[w].back();
        kolumna[w].pop_back();
        odw[kr] = true;
        kolor[kr] = parz;
        DFS(wie[kr], 1, 1 - parz);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &kol[i], &wie[i]);
        kolumna[kol[i]].push_back(i);
        wiersz[wie[i]].push_back(i);
    }
    
    for(int i = 1; i <= N; i++) {
        int parz = 0;
        while(!kolumna[i].empty()) {
            DFS(i, 0, parz % 2);
            parz++;
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%c", kolor[i]?'b':'r');
    }
    return 0;
}