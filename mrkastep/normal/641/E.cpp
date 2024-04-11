#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex>

using namespace std;

const int INF = 2e9;
const int mod = 1e9 + 7;
const long long LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<double, double> point;

struct ST{
    struct node{
        node *L, *R;
        int val;
        node(){
            val = 0;
            L = R = NULL;
        }
    };

    typedef node* pnode;

    pnode root;
    int s;

    ST(){
        s = 0;
    }

    ST(int n){
        s = n;
    }

    void add(int pos, int val){
        add(root, 0, s, pos, val);
    }

    int ask(int pos){
        return ask(root, 0, s, pos);
    }

private:

    int vl(pnode v){
        if (v == NULL) return 0;
        return v->val;
    }

    void add(pnode &v, int l, int r, int pos, int val){
        if (v == NULL){
            v = new node;
        }
        if (l + 1 == r){
            v->val += val;
            return;
        }
        int m = (l + r) / 2;
        if (pos < m){
            add(v->L, l, m, pos, val);
        }
        else{
            add(v->R, m, r, pos, val);
        }
        v->val = vl(v->L) + vl(v->R);
    }

    int ask(pnode v, int l, int r, int p){
        if (v == NULL) return 0;
        if (r == p){
            return v->val;
        }
        int m = (l + r) / 2;
        if (p < m){
            return ask(v->L, l, m, p);
        }
        return vl(v->L) + ask(v->R, m, r, p);
    }
};

ST T[1001000];

map<int, int> t, a;

vector<vector<int> > V;

void solve(){
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i){
        vector<int> v(3);
        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        t[v[1]]++;
        a[v[2]]++;
        V.push_back(v);
    }
    int cnt = 0;
    for (auto it = t.begin(); it != t.end(); ++it){
        it->y = cnt++;
    }
    cnt = 0;
    for (auto it = a.begin(); it != a.end(); ++it){
        T[cnt].s = t.size();
        it->y = cnt++;
    }
    for (int i = 0; i < q; ++i){
        if (V[i][0] == 1){
            T[a[V[i][2]]].add(t[V[i][1]], 1);
        }
        if (V[i][0] == 2){
            T[a[V[i][2]]].add(t[V[i][1]], -1);
        }
        if (V[i][0] == 3){
            printf("%d\n", T[a[V[i][2]]].ask(t[V[i][1]]));
        }
    }
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}