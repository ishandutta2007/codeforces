#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m;
int price[N];
int colorFront[N], colorBack[N];
priority_queue<pair<int, int> > tshirts[5];
int bestColor;
bool done[N];

int main() {
  
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &colorFront[i]);
        tshirts[colorFront[i]].push({-price[i], i});
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &colorBack[i]);
        tshirts[colorBack[i]].push({-price[i], i});
    }
    
    scanf("%d", &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d", &bestColor);
        while (!tshirts[bestColor].empty() && done[tshirts[bestColor].top().second]) tshirts[bestColor].pop();
        if (tshirts[bestColor].empty()) {
            printf("-1 ");
        } else {
            int id = tshirts[bestColor].top().second;
            tshirts[bestColor].pop();
            done[id] = true;
            printf("%d ", price[id]);
        }
    }
    
    return 0;
}