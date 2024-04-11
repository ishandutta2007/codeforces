#include <bits/stdc++.h>
using namespace std;

#define MAXL 1000006

int T, N, K;
char buf[MAXL];
int D[MAXL], E[MAXL];
vector <int> con[MAXL]; bool vis[MAXL];

struct NODE {
    int num;
    NODE *nxt[26];
} container[MAXL];

NODE* new_node()
{
    NODE *ret = &container[K]; vis[K] = 0; con[K].clear();
    ret->num = K++;
    memset(ret->nxt, 0, sizeof(ret->nxt));
    return ret;
}

void dp(int n)
{
    D[n] = 1; E[n] = 0;
    for (int t: con[n]) if (!vis[t]){
        vis[t] = 1;
        dp(t);
        D[n] += E[t];
        E[n] += max(D[t], E[t]);
    }
}

int main()
{
    for (scanf("%d", &T);T--;){
        K = 0; NODE *root = new_node();
        scanf("%d", &N);
        vector <string> arr;
        for (int i=1;i<=N;i++){
            scanf("%s", buf); arr.push_back(buf);
            NODE* now = root;
            for (int j=0;buf[j];j++){
                if (!now->nxt[buf[j]-'a'])
                    now->nxt[buf[j]-'a'] = new_node();
                now = now->nxt[buf[j]-'a'];
            }
        }
        for (const auto &s: arr){
            NODE *now = root, *prv = root;
            for (int i=0;i<s.length();i++){
                int c = s[i]-'a';
                if (i > 0 && prv) prv = prv->nxt[c];
                now = now->nxt[c];
                con[prv ? prv->num : 0].push_back(now->num);
            }
        }
        dp(0);
        printf("%d\n", E[0]);
    }
}