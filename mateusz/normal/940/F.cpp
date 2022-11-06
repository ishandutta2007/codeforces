#include <bits/stdc++.h>

using namespace std;

const int N = 100005, S = 350, SQRT = 2000;

int n, q;
int tab[N];
vector<int> history[N];

int what[N], qf[N], qs[N];

int updatesBefore[N];

int answer[N];

int cnt[2 * N];
int cntOccurs[2 * N];
vector<int> updates;

bool cmp(int a, int b) {
    return make_pair(updatesBefore[a] / SQRT, make_pair(qf[a] / SQRT, qs[a])) < make_pair(updatesBefore[b] / SQRT, make_pair(qf[b] / SQRT, qs[b]));
}

void insert(int pos, int type) {
    cntOccurs[cnt[history[pos].back()]]--;
    cnt[history[pos].back()] += type;
    cntOccurs[cnt[history[pos].back()]]++;
}

void add(int t, int from, int to, int type) {
    t = updates[t];
    bool inside = (from <= qf[t] && qf[t] <= to);
    if (inside) {
        insert(qf[t], -1);
    }
    if (type == 1) {
        history[qf[t]].push_back(qs[t]);
    } else {
        history[qf[t]].pop_back();
    }
    if (inside) {
        insert(qf[t], 1);
    }
}

int main() {
    
    vector<pair<int, pair<int, int> > > nums;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        nums.push_back({tab[i], {i, 0}});
    }
    
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &what[i], &qf[i] ,&qs[i]);
        if (what[i] == 2) {
            nums.push_back({qs[i], {i, 1}});
        }
    }
    
    sort(nums.begin(), nums.end());
    
    int id = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || nums[i].first != nums[i - 1].first) {
            id++;
        }
        if (nums[i].second.second == 0) {
            tab[nums[i].second.first] = id;
        } else {
            qs[nums[i].second.first] = id;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        history[i].push_back(tab[i]);
    }
    
    vector<int> queries;
    for (int i = 1; i <= q; i++) {
        if (what[i] == 2) {
            updates.push_back(i);
            continue;;
        }
        updatesBefore[i] = updates.size();
        queries.push_back(i);
    }
    
    sort(queries.begin(), queries.end(), cmp);
    
    int low = 1;
    int high = 0;
    int curT = 0;
    for (auto query : queries) {
        int from = qf[query];
        int to = qs[query];
        int t = updatesBefore[query];
        
        while (low > from) insert(--low, 1);
        while (high < to) insert(++high, 1);
        while (low < from) insert(low++, -1);
        while (high > to) insert(high--, -1);
        while (curT < t) add(curT++, low, high, 1);
        while (curT > t) add(--curT, low, high, -1);
        
        int ans = SQRT + 1;
        for (int i = 1; i <= SQRT; i++) {
            if (cntOccurs[i] == 0) {
                ans = i;
                break;
            }
        }
        
        answer[query] = ans;
    }
    
    for (int i = 1; i <= q; i++) {
        if (what[i] == 1) {
            printf("%d\n", answer[i]);
        }
    }
    
    return 0;
}