#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, -1, 1, 0};
const char dir[] = "DLRU";
char m[max_n][max_n];
int dist[max_n][max_n];
bool vis[max_n][max_n];
int h, w, k;
int si, sj;

bool is_on_field(int i, int j) {
    return (i >= 0 && i < h && j >= 0 && j < w);
}

void find_dist() {
    queue<pair<int, int> > q;
    q.push(mp(si, sj));
    vis[si][sj] = true;
    dist[si][sj] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int i = cur.F, j = cur.S;
        for (int c = 0; c < 4; ++c) {
            int ni = i + di[c];
            int nj = j + dj[c];
            if (is_on_field(ni, nj) && m[ni][nj] == '.' && !vis[ni][nj]) {
                vis[ni][nj] = true;
                dist[ni][nj] = dist[i][j] + 1;
                q.push(mp(ni, nj));
            }
        }
    }
}

void print_dist()
{
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (m[i][j] == '*') cout << "X ";
            else cout << dist[i][j] << " ";
        }
        cout<< endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &h, &w, &k);
    for (int i = 0; i < h; ++i) {
        scanf("%s", m[i]);
    }
    bool isbr = false;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (m[i][j] == 'X') {
                si = i;
                sj = j;
                m[i][j] = '.';
                isbr = true;
                break;
            }
        }
        if (isbr) break;
    }
    int st_dir_cnt = 0;
    for (int c = 0; c < 4; ++c) {
        int ni = si + di[c];
        int nj = sj + dj[c];
        if (is_on_field(ni, nj) && m[ni][nj] == '.') {
            st_dir_cnt++;
        }
    }
    //cout << "dir_count: " << st_dir_cnt << endl;
    if (k % 2 == 1 || st_dir_cnt == 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    find_dist();
    //print_dist();
    vector<char> ans;
    int i = si, j = sj;
    while (k) {
        for (int c = 0; c < 4; ++c) {
            int ni = i + di[c];
            int nj = j + dj[c];
            if (is_on_field(ni, nj) && m[ni][nj] == '.' && dist[ni][nj] <= k - 1) {
                i = ni;
                j = nj;
                ans.pb(dir[c]);
                break;
            }
        }
        --k;
    }
    for (char c : ans) {
        printf("%c", c);
    }
    cout << endl;
    return 0;
}