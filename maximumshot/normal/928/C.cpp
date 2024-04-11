#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1005;

int n;
pair< string, int > pr[N];
vec< pair< string, int > > g[N];
map< pair< string, int >, int > id;
unordered_set< string > used;
vec< pair< string, int > > res;
int dist[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    fill(dist, dist + N, inf);

    cin >> n;

    for(int i = 0;i < n;i++) {
        string name;
        int version;
        cin >> name >> version;
        id[make_pair(name, version)] = i;
        pr[i] = make_pair(name, version);
        int k;
        cin >> k;
        for(int j = 0;j < k;j++) {
            string t_name;
            int t_version;
            cin >> t_name;
            cin >> t_version;
            g[i].push_back(make_pair(t_name, t_version));
        }
    }

    dist[0] = 0;

    // {dist, -v, i}
    set< tuple< int, int, int > > q;

    q.insert(make_tuple(dist[0], -pr[0].second, 0));

    while(!q.empty()) {
        int i;
        tie(ignore, ignore, i) = *q.begin();
        q.erase(q.begin());
        if(used.count(pr[i].first)) continue;
        used.insert(pr[i].first);
        if(i > 0) res.push_back(pr[i]);
        for(auto to : g[i]) {
            int j = id[to];
            if(dist[j] > dist[i] + 1) {
                q.erase(make_tuple(dist[j], -pr[j].second, j));
                dist[j] = dist[i] + 1;
                q.insert(make_tuple(dist[j], -pr[j].second, j));
            }
        }
    }

    sort(ALL(res));

    cout << (int)res.size() << "\n";
    for(pair< string, int > i : res) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}