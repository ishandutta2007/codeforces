#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

int N, M;

struct NODE{
    NODE(): end(0){ for (int i=0;i<3;i++) nxt[i] = 0; }

    bool end;
    NODE *nxt[3];
} *root;

bool query(NODE *now, int idx, const string &s, bool changed)
{
    if (!now) return 0;
    if (idx == sz(s)) return changed && now->end;
    int t = s[idx]-'a';
    if (changed) return query(now->nxt[t], idx+1, s, 1);
    return query(now->nxt[t], idx+1, s, 0) || query(now->nxt[(t+1)%3], idx+1, s, 1) || query(now->nxt[(t+2)%3], idx+1, s, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    root = new NODE();
    for (int i=1;i<=N;i++){
        string s;
        cin >> s;
        NODE *now = root;
        for (char c: s){
            int t = c-'a';
            if (!now->nxt[t])
                now->nxt[t] = new NODE();
            now = now->nxt[t];
        }
        now->end = 1;
    }
    for (int i=0;i<M;i++){
        string s;
        cin >> s;
        bool ans = query(root, 0, s, 0);
        cout << (ans ? "YES" : "NO") << endl;
    }
}