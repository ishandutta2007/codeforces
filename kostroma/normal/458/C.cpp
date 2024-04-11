#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
//void precalc();
clock_t start;
//int timer = 1;


int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
    cout.sync_with_stdio(0);
    //precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    start = clock();
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        solve();
        //++timer;
    }

#ifdef room111
    cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

class treap {
private:
    typedef struct _node {
        pair<int, int> key;
        int prior;
        _node* l;
        _node* r;
        int sum;
        int cnt;
        _node (pair<int, int> key):key(key) { prior = (rand()<<16) | rand(); sum = key.first; cnt = 1; l = 0; r = 0; }
        inline void recalc(){
            sum = key.first;
            cnt = 1 + Cnt(l) + Cnt(r);
            if (l){
                sum += l->sum;
            }
            if (r){
                sum += r->sum;
            }
        }

        static int Cnt (_node* v){
            if (!v)
                return 0;
            return v->cnt;
        }
    }*node;

    static int Cnt (_node* v){
            if (!v)
                return 0;
            return v->cnt;
    }

    node root;

    node merge (node l, node r){
        if (!l)
            return r;
        if (!r)
            return l;
        if (l->prior < r->prior){
            l->r = merge(l->r, r);
            l->recalc();
            return l;
        }
        else{
            r->l = merge(l, r->l);
            r->recalc();
            return r;
        }
    }

    inline void splitCnt (node v, int key, node& l, node& r){
        l = r = 0;
        if (!v)
            return;
        int cur = v->l ? v->l->cnt : 0;
        if (cur < key){
            l = v;
            splitCnt(l->r, key - cur - 1, l->r, r);
            l->recalc();
        }
        else{
            r = v;
            splitCnt(r->l, key, l, r->l);
            r->recalc();
        }
    }

    inline void split (node v, pair<int, int> key, node& l, node& r){
        l = r = 0;
        if (!v)
            return;
        if (v->key < key){
            l = v;
            split(l->r, key, l->r, r);
            l->recalc();
        }
        else{
            r = v;
            split(r->l, key, l, r->l);
            r->recalc();
        }
    }

public:
    treap() { root = 0; }

    inline void add (pair<int, int> key){
        node l, r;
        split(root, key, l, r);
        root = merge(merge(l, new _node(key)), r);
    }

    inline void erase (pair<int, int> key){
        node l, m, r;
        split(root, key, l, r);
        split(r, mp(key.first, key.second + 1), m, r);
        root = merge(l, r);
    }


    inline int Sum (int pref){
        if (pref == 0)
            return 0;
        node l, r;
        splitCnt(root, pref, l, r);
        //cout<<"size need = "<<L<<" size have = "<< Cnt(l) <<'\n';
        //assert(Cnt(l) == L);
        int res = l->sum;
        //cout<<"size need = "<<R - L + 1 <<" size have = "<< m->cnt <<'\n';
        //assert(m->cnt == R - L + 1);
        root = merge(l, r);
        return res;
    }

    /*void dfs(){
        dfs(root);
    }

    void dfs1(){
        dfs1(root);
    }

    static void dfs (node v, bool rev = false){
        if (!v)
            return;
        rev ^= v->reversed;
        if (!rev){
            dfs(v->l, rev);
            cout<<v->val<<' ';
            dfs(v->r, rev);
        }
        else{
            dfs(v->r, rev);
            cout<<v->val<<' ';
            dfs(v->l, rev);
        }
    }

    static void dfs1 (node v){
        if (!v)
            return;
        cout<<v->val<<' '<<v->reversed<<'\n';
        if (v->l){
            cout<<"left\n";
            dfs1(v->l);
            cout<<"all_left\n";
        }
        if (v->r){
            cout<<"right\n";
            dfs1(v->r);
            cout<<"all_right\n";
        }
    }*/

};

int n;

treap tree;

vector<pair<int, int>> voters[100500]; //number, man

set<pair<int, int>> votes; //votes, candidate

int firstVotes[100500];

const int C = 100001;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ++firstVotes[a];
        voters[a].push_back(mp(b, i));
        if (a != 0) {
            tree.add(mp(b, i));
        }
    }

    for (int i = 0; i < C; ++i) {
        sort(all(voters[i]));
        reverse(all(voters[i]));
    }

    for (int i = 1; i < C; ++i)
        if (firstVotes[i] > 0)
            votes.insert(mp(firstVotes[i], i));

    int ans = 2e9;

    int curAns = 0, got = firstVotes[0];

    for (int x = n; x >= got; --x) {
        while(!votes.empty()) {
            pair<int, int> cur = *votes.rbegin();
            if (cur.first < x)
                break;
            int id = cur.second;
            pair<int, int> nowVoter = voters[id].back();
            voters[id].pop_back();
            curAns += nowVoter.first;
            tree.erase(nowVoter);
            votes.erase(cur);
            --cur.first;
            ++got;
            votes.insert(cur);
            
        }

        ans = min(ans, curAns + tree.Sum(max(x - got, 0)));

    }

    cout << ans;

}