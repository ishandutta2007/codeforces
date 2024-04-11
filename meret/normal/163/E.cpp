#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

int lastId = 0;

struct Node {
    char x;
    map<char, Node*> e;
    Node* psuf;
    int id;
    int depth;
    Node(char _x, int _depth) {
        x = _x;
        id = lastId++;
        depth = _depth;
        psuf = NULL;
    }
};

Node* searchStep(Node* root, char c) {
    while (root->depth != 0 && root->e.find(c) == root->e.end()) {
        root = root->psuf;
    }
    if (root->e.find(c) != root->e.end()) {
        root = root->e[c];
    }
    return root;
}
Node* safeNext(Node* root, char c) {
    if (root->e.find(c) == root->e.end())
        return root->e[c] = new Node(c, root->depth + 1);
    else
        return root->e[c];
}

char s[1000005];

Node* insert(Node* root) {
    int ss = strlen(s);
    int i = 0;
    while (i < ss)
        root = safeNext(root, s[i++]);
    return root;
}

void ahoCorasick(Node* root) {
    queue<Node*> q;
    q.push(root);
    root->psuf = root;
    while (!q.empty()) {
        Node* c = q.front();
        q.pop();
        char cx = c->x;
        while (c->psuf != root && c->psuf->e.find(cx) == c->psuf->e.end()) {
            c->psuf = c->psuf->psuf;
        }
        if (c->psuf->e.find(cx) != c->psuf->e.end())
            c->psuf = c->psuf->e[cx];
        if (c->psuf == c)
            c->psuf = root;
        FORE (it, c->e) {
            it->ND->psuf = c->psuf;
            q.push(it->ND);
        }
    }
}

const int S = 1000005;

vector<int> sons[S];
int le[S], ri[S];
int curTime;

void dfs(int x) {
    le[x] = ++curTime;
    FORE (it, sons[x]) {
        dfs(*it);
    }
    ri[x] = curTime;
}

void addEdges(Node* root) {
    if (root->psuf != root) {
        sons[root->psuf->id].PB(root->id);
    }
    FORE (it, root->e) {
        addEdges(it->ND);
    }
}

int myNo[100005];

int t[S];

void ad(int x, int v) {
    while (x > 0) {
        t[x] += v;
        x -= x & -x;
    }
}

int sm(int x) {
    int result = 0;
    while (x <= curTime) {
        result += t[x];
        x += x & -x;
    }
    return result;
}

bool inside[100005];

int main() {
    ios_base::sync_with_stdio(false);
    int q, n;
    scanf("%d %d", &q, &n);
    Node* root = new Node(0, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int cur = insert(root)->id;
        myNo[i] = cur;
    }
    ahoCorasick(root);
    addEdges(root);
    dfs(0);
    for (int i = 0; i < n; ++i) {
        ad(ri[myNo[i]], 1);
        ad(le[myNo[i]] - 1, -1);
        inside[i] = true;
    }
    for (int i = 0; i < q; ++i) {
        scanf("%1s", s);
        if (s[0] == '-') {
            int num;
            scanf("%d", &num);
            if (inside[num - 1]) {
                inside[num - 1] = false;
                num = myNo[num - 1];
                ad(ri[num], -1);
                ad(le[num] - 1, 1);
            }
        } else if (s[0] == '+') {
            int num;
            scanf("%d", &num);
            if (!inside[num - 1]) {
                inside[num - 1] = true;
                num = myNo[num - 1];
                ad(ri[num], 1);
                ad(le[num] - 1, -1);
            }
        } else {
            scanf("%s", s);
            LL result = 0;
            Node* cur = root;
            int ss = strlen(s);
            for (int i = 0; i < ss; ++i) {
                cur = searchStep(cur, s[i]);
                if (cur != NULL) {
                    result += sm(le[cur->id]);
                }
            }
            cout << result << "\n";
        }
    }
}