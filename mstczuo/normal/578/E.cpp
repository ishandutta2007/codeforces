# include <iostream>
# include <cstdio>
# include <vector>
# include <set>
# include <cstring>

using namespace std;
#define next _next__

char a[100010];
set<int> L, R;

int next[100010];
int pre[100010];

struct seq {
    int head;
    int tail;
    void print() const {
        for(int u = head; u; u = next[u]) {
            printf("%d ", u);
        }
        puts("");
    }
    seq operator+(const seq&ot) const {
        if(head == -1) return ot;
        if(ot.head == -1) return *this;
        next[tail] = ot.head;
        pre[next[tail]] = tail;
        return {head, ot.tail};
    }
};

vector<seq> c[2][2];

int get_path(int u,int flag) {
    set<int>::iterator it;
    while(true) {
        if(flag) {
            it = R.lower_bound(u);
            if(it == R.end()) return u;
            next[u] = *it;
            pre[next[u]] = u;
            u = next[u];
            R.erase(it);
            flag = 0;
        } else {
            it = L.lower_bound(u);
            if(it == L.end()) return u;
            next[u] = *it;
            pre[next[u]] = u;
            u = next[u];
            L.erase(it);
            flag = 1;
        }
    }
}

int main() {
    scanf("%s", a);
    int n = strlen(a);
    for(int i = 0; i < n; ++i) {
        if(a[i] == 'L') L.insert(i + 1);
        else R.insert(i + 1);
    }
    int ans = -1;
    while(L.size() || R.size()) {
        ans += 1;
        if(L.size() && (R.empty() || *L.begin() < *R.begin())) {
            int u = *L.begin(); L.erase(L.begin());
            int v = get_path(u, 1);
            c[a[u-1] == 'R'][a[v-1] == 'R'].push_back(seq{u,v});
        } else {
            int u = *R.begin(); R.erase(R.begin());
            int v = get_path(u, 0);
            c[a[u-1] == 'R'][a[v-1] == 'R'].push_back(seq{u,v});
        }
    }

    int sz = (int)min(c[0][0].size(), c[1][1].size()); 
    for(int i = 0; i < sz; ++i) {
        seq A = c[0][0][i], B = c[1][1][i];
        c[0][1].push_back(A + B);
    }
    seq LR = {-1, -1}; for(auto u:c[0][1]) LR = LR + u; 
    seq RL = {-1, -1}; for(auto u:c[1][0]) RL = RL + u; 

    cout << ans << endl;
    if((int)c[0][0].size() > sz) {
        (LR + c[0][0][sz] + RL).print();
    } else if((int)c[1][1].size() > sz) {
        (RL + c[1][1][sz] + LR).print();
    } else {
        if(LR.head != -1 && RL.head != -1) {
            if(LR.tail < RL.tail) swap(LR, RL);
            next[RL.tail] = LR.tail;
            RL.tail = LR.tail;
            LR.tail = pre[LR.tail];
            next[LR.tail] = 0;
            (LR+RL).print();
        } else {
            (LR + RL).print();
        }
    }
}