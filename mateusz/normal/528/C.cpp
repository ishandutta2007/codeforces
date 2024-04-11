#include <bits/stdc++.h>

using namespace std;
const int N = 500005;
pair<int, int> kr[N];
int st[N];
bool odw[N];
vector<pair<int, int> > V[N];
vector<int> stos;
int n, m;
vector<pair<int, int > >results;
void DFS(int w) {
    while(!V[w].empty()) {
        int u = V[w].back().first;
        int in = V[w].back().second;
        V[w].pop_back();
        if(odw[in] == false) {
            odw[in] = true;
            DFS(u);
            stos.push_back(u);
        }
    }
}

int main() {
    
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &kr[i].first, &kr[i].second);
        int a = kr[i].first;
        int b = kr[i].second;
        st[a]++;
        st[b]++;
    }

    vector<int> nieparzysci;
    for(int i = 1; i <= n; i++) {
        if(st[i] % 2 == 1) {
            nieparzysci.push_back(i);
        }
    }
    for(int i = 0; i < nieparzysci.size(); i += 2) {
        kr[++m].first = nieparzysci[i];
        kr[m].second = nieparzysci[i + 1];
    }
    
    for(int i = 1; i <= m; i++) {
        int a = kr[i].first;
        int b = kr[i].second;
        V[a].push_back({b, i});
        V[b].push_back({a, i});
    }
    DFS(1);
    stos.push_back(1);
    printf("%d\n", m + m % 2);
    if(m % 2) {
        printf("1 1\n");
    }
    for(int i = 0; i < stos.size() - 1; i++) {
        if(i % 2 == 0) {
            printf("%d %d\n", stos[i], stos[i + 1]);
        } else {
            printf("%d %d\n", stos[i + 1], stos[i]);
        }
    }
    return 0;
}