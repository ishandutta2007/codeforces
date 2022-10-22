#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;


int const LOG = 31; // [0 .. LOG - 1]
int const N = 200005;

struct Node {
    Node *l, *r;
    int cnt;
    Node(int _cnt = 1) {
        l = r = 0;
        cnt = _cnt;
    }
} *t;

multiset< int > H;

void add(int val) {
    Node *ptr = t;
    for(int cur, bit = 30;bit >= 0;bit--) {
        cur = ((1 << bit) & val?1 : 0);
        if(cur == 0) {
            if(!ptr->l) ptr->l = new Node(0);
            ptr = ptr->l;
        }else {
            if(!ptr->r) ptr->r = new Node(0);
            ptr = ptr->r;
        }
        ptr->cnt++;
    }
}

void del(int val) {
    Node *ptr = t;
    for(int cur, bit = 30;bit >= 0;bit--) {
        cur = ((1 << bit) & val?1 : 0);
        if(cur == 0) {
            ptr = ptr->l;
        }else {
            ptr = ptr->r;
        }
        ptr->cnt--;
    }
}

int get(int val) {
    Node * ptr = t;
    int res = 0;
    for(int cur, bit = 30;bit >= 0;bit--) {
        cur = ((1 << bit) & val?1 : 0);
        if(cur == 1) {
            if(ptr->l && ptr->l->cnt > 0) ptr = ptr->l, res |= (1 << bit);
            else ptr = ptr->r;
        }else {
            if(ptr->r && ptr->r->cnt > 0) ptr = ptr->r, res |= (1 << bit);
            else ptr = ptr->l;
        }
    }
    return res;
}

bool solve() {

    int q;
    scanf("%d", &q);

    t = new Node(0);
    add(0);

    char type;
    for(int x, iter = 0;iter < q;iter++) {
        scanf(" %c %d", &type, &x);
        if(type == '+') {
            if(!H.count(x)) add(x);
            H.insert(x);
        }else if(type == '-') {
            H.erase(H.lower_bound(x));
            if(!H.count(x)) del(x);
        }else {
            printf("%d\n", get(x));
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}