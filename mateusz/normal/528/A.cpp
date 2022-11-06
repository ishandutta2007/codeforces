#include <bits/stdc++.h>

using namespace std;
const int N = 200005;
int w, h, n;
set<pair<int, int> > H, W;
priority_queue<pair<int, int> > HQ, WQ;
char co;
int d;
int LH[N], LW[N];
int main() {
    scanf("%d %d %d", &w, &h, &n);
    H.insert({0, h});
    W.insert({0, w});
    HQ.push({h, 0});
    WQ.push({w, 0});
    LH[0] = h;
    LW[0] = w;
    for(int i = 1; i <= n; i++) {
        scanf(" %c", &co);
        if(co == 'H') {
            scanf("%d", &d);
            set<pair<int, int> >::iterator it = H.upper_bound({d, 0});
            it--;
            if(it != H.end()) {
                int a = it->first;
                int b = it->second;
                LH[a] = d - a;
                LH[d] = b - d;
                H.erase(it);
                H.insert({a, d});
                H.insert({d, b});
                HQ.push({LH[a], a});
                HQ.push({LH[d], d});
            }
        } 
        if(co == 'V') {
            scanf("%d", &d);
            set<pair<int, int> >::iterator it = W.upper_bound({d, 0});
            it--;
            if(it != W.end()) {
                int a = it->first;
                int b = it->second;
                LW[a] = d - a;
                LW[d] = b - d;
                W.erase(it);
                W.insert({a, d});
                W.insert({d, b});
                WQ.push({LW[a], a});
                WQ.push({LW[d], d});
            }
        } 
        int l1, l2;
        while(!HQ.empty() && LH[HQ.top().second] != HQ.top().first) HQ.pop();
        if(!HQ.empty()) {
            l1 = HQ.top().first;
        } else {
            l1 = 0;
        }
        while(!WQ.empty() && LW[WQ.top().second] != WQ.top().first) WQ.pop();
        if(!WQ.empty()) {
            l2 = WQ.top().first;
        } else {
            l2 = 0;
        }
        printf("%I64d\n", (long long)l1 * l2);
    }
    
    
    return 0;
}