#include <bits/stdc++.h>

using namespace std;

bool cmp(pair< pair< int, int >, int > const & p1,pair< pair< int, int >, int > const & p2) {
    return p1.first.second < p2.first.second;
}

inline int nextRand() {
    return (rand() << 16) | rand();
}

struct Node {
    Node *l, *r;
    int prior;
    int value;
    int cnt;
    int id;
    Node() : id(-1), l(0), r(0), prior(nextRand()), value(0), cnt(0) {}
    Node(int x, int id) : id(id), l(0), r(0), prior(nextRand()), value(x), cnt(1) { }
};

inline void update(Node *& v) {
    v->cnt = 1;
    if(v->l) v->cnt += v->l->cnt;
    if(v->r) v->cnt += v->r->cnt;
}

void merge(Node *& v, Node * l, Node * r) {
    if(!l || !r) {
        v = l ? l : r;
        return;
    }
    if(l->prior < r->prior) {
        merge(l->r, l->r, r);
        v = l;
    }else {
        merge(r->l, l, r->l);
        v = r;
    }
    if(v) update(v);
}

inline int get_cnt(Node *& v) {
    return v ? v->cnt : 0;
}

void split_by_cnt(Node *v, Node *& l, Node *& r, int x) {
    if(!v) {
        l = r = 0;
        return;
    }
    if(get_cnt(v->l) + 1 <= x) {
        split_by_cnt(v->r, v->r, r, x - get_cnt(v->l) - 1);
        l = v;
    }else {
        split_by_cnt(v->l, l, v->l, x);
        r = v;
    }
    if(l) update(l);
    if(r) update(r);
}

// <= x
void split_by_value(Node * v, Node *& l, Node *& r, int x, int id) {
    if(!v) {
        l = r = 0;
        return;
    }
    if(make_pair(v->value, v->id) <= make_pair(x, id)) {
        split_by_value(v->r, v->r, r, x, id);
        l = v;
    }else {
        split_by_value(v->l, l, v->l, x, id);
        r = v;
    }
    if(l) update(l);
    if(r) update(r);
}

vector< int > way;

void show(Node *v) {
    if(v->l) {
        show(v->l);
    }
    way.push_back(v->id);
    if(v->r) {
        show(v->r);
    }
}

void erase(Node *& v, int x, int id) {
    Node *nl, *nm, *nr;
    nl = nm = nr = 0;
    split_by_value(v, nl, nr, x, id);
    split_by_cnt(nl, nl, nm, get_cnt(nl) - 1);
    merge(v, nl, nr);
}

void insert(Node *& v, int x, int id) {
    Node *nl, *nr;
    nl = nr = 0;
    split_by_value(v, nl, nr, x, id);
    merge(nl, nl, new Node(x, id));
    merge(v, nl, nr);
}

int main() {

    srand(time(NULL));

    int n, k;

    scanf("%d %d", &n, &k);

    vector< pair< pair< int, int >, int > > seg(n);

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &seg[i].first.first, &seg[i].first.second);
        seg[i].second = i;
    }

    sort(seg.begin(), seg.end(), cmp);

    Node * t = 0, *nl, *nm, *nr;

    t = 0;
    for(int i = 0;i < n;i++) {
        insert(t, seg[i].first.first, seg[i].second + 1);
    }

    int res_val = -1;
    int res_id = 0;

    for(int i = 0;i < n;i++) {
        int j = i;
        while(j < n && seg[i].first.second == seg[j].first.second) j++;
        j--;

        for(int q = i;q <= j;q++) {
            erase(t, seg[q].first.first, seg[q].second + 1);
            if(get_cnt(t) >= k - 1) {
                int ql = seg[q].first.first;
                int qr = seg[q].first.second;
                nl = nm = nr = 0;
                split_by_cnt(t, nl, nr, k - 1);
                if(k > 1) {
                    split_by_cnt(nl, nl, nm, get_cnt(nl) - 1);
                    if(nm) {
                        ql = max(ql, nm->value);
                    }
                    merge(nl, nl, nm);
                }
                merge(t, nl, nr);
                int tmp_val = max(0, qr - ql + 1);
                int tmp_id = q;
                if(tmp_val > res_val) {
                    res_val = tmp_val;
                    res_id = tmp_id;
                }
            }
            insert(t, seg[q].first.first, seg[q].second + 1);
        }

        for(int q = i;q <= j;q++) {
            erase(t, seg[q].first.first, seg[q].second + 1);
        }

        i = j;
    }

    printf("%d\n", res_val);

    t = 0;
    for(int i = 0;i < n;i++) {
        insert(t, seg[i].first.first, seg[i].second + 1);
    }

    way.reserve(k);

    for(int i = 0;i < n;i++) {
        int j = i;
        while(j < n && seg[i].first.second == seg[j].first.second) j++;
        j--;

        for(int q = i;q <= j;q++) {
            erase(t, seg[q].first.first, seg[q].second + 1);
            if(get_cnt(t) >= k - 1) {
                int ql = seg[q].first.first;
                int qr = seg[q].first.second;
                nl = nm = nr = 0;
                split_by_cnt(t, nl, nr, k - 1);
                if(k > 1) {
                    split_by_cnt(nl, nl, nm, get_cnt(nl) - 1);
                    if(nm) {
                        ql = max(ql, nm->value);
                    }
                    merge(nl, nl, nm);
                }
                merge(t, nl, nr);
                int tmp_val = max(0, qr - ql + 1);
                int tmp_id = q;
                if(tmp_id == res_id) {
                    way.push_back(seg[q].second + 1);
                    nl = nm = nr = 0;
                    split_by_cnt(t, nl, nr, k - 1);
                    if(nl) show(nl);
                    merge(t, nl, nr);
                }
            }
            insert(t, seg[q].first.first, seg[q].second + 1);
        }

        for(int q = i;q <= j;q++) {
            erase(t, seg[q].first.first, seg[q].second + 1);
        }

        i = j;
    }

    sort(way.begin(), way.end());

    for(int x : way) {
        printf("%d ", x);
    }

    printf("\n");

    return 0;
}