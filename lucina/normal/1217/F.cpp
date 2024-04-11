#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int top ;
int last;
int n, m;

int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}


vector < pair <int *, int>>  st ;


vector < pair <int, int> > sg[nax << 2];
vector < pair <int, int> > all_edge ;

int get_id (pair <int, int> x) {
    return lower_bound(all_edge.begin(), all_edge.end(), x) - all_edge.begin();
}

bool active[nax << 1];

int par[nax], sz[nax];



struct query {
    int t, x, y;

    void read () {
        t = ::read(), x = ::read(), y = ::read();

        if (x > y) swap(x, y);
    }
};
query q[nax];

int nxt (int x) {
    return x == n ? 1 : x + 1;
}

void change (int &from, int to) {
    st.emplace_back(&from, from);
    from = to;
}

void rollback () {
    *st.back().first = st.back().second;
    st.pop_back();
}

int find_par (int x) {
    return par[x] == x ? x : find_par(par[x]);
}

void unite (int a, int b ) {
    a = find_par(a), b = find_par(b);

    if (a == b) return ;
    if (sz[a] < sz[b]) swap(a, b);
    change(par[b], a);
    change(sz[a], sz[a] + sz[b]);
}

void process (int i) {
    int x = last ? nxt(q[i].x) : q[i].x, y = last ? nxt(q[i].y) : q[i].y;
    active[get_id(minmax(x, y))] ^= 1;
}


void add (int v, int x, int y, int l, int r, pair < int, int> to_add) {

    if (l > r) return ;

    if (l == x && r == y) {

        sg[v].push_back(to_add);
        return ;
    }

    int mid = x + y >> 1;

    add (v << 1 , x , mid, l, min(r, mid), to_add);
    add (v << 1 ^ 1, mid + 1, y, max(l, mid + 1), r, to_add);
}




/// yet another DCP problem
void dfs (int v, int l, int r, bool finished_left) {

    int prev_top = (int)st.size();
    if (finished_left && q[l].t == 1) process(l);
    /**
        If we finished processing left subtree, we will know what is the real "last"
        and which edge should be really on the query on this range
        , then we just need to toggle it.
        If it's not active, it's active.
        If it's active, it's time to stop.
    */

    for (auto &i : sg[v])
        if (active[get_id(i)]) unite(i.first, i.second);

    if (l == r) {
        if (q[l].t == 2) {
            int x = last == 0 ? q[l].x : nxt(q[l].x), y = last == 0 ? q[l].y : nxt(q[l].y);
            last = find_par(x) == find_par(y);
            putchar(last + '0');
        }
    }
    else {
        int mid = l + r >> 1;
        dfs(v << 1, l, mid, false);
        dfs(v << 1 ^ 1, mid + 1, r, true);
    }

    while ((int)st.size() != prev_top) rollback();
}


int main () {


    n = read(), m = read();



    map < pair <int, int>, vector <int> > keep;


    for (int i = 1 ; i <= m ; ++ i) {
        q[i].read();

        if (q[i].t == 1) {
            int x = q[i].x, y = q[i].y;
            all_edge.emplace_back(x, y);
            keep[make_pair(x, y)].push_back(i);
            x = nxt(x), y = nxt(y);
            all_edge.push_back(minmax(x, y));
            keep[minmax(x, y)].push_back(i);
        }
    }

    for (auto & it : keep) {
        it.second.push_back(m + 1);

        for (int j = 0 ; j < (int)it.second.size() - 1 ; ++ j) {

            add(1, 1, m, it.second[j], it.second[j + 1] - 1, it.first);
        }
    }

    sort(all_edge.begin(), all_edge.end());
    all_edge.erase(unique(all_edge.begin(), all_edge.end()), all_edge.end());

    fill(sz + 1 , sz + 1 + n, 1);
    iota(par + 1 , par + 1 + n, 1);

    dfs(1, 1, m, true);


}