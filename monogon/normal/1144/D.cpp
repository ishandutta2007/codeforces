
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define ll long long
#define VI vector<int>

using namespace std;

const int MAX_N = 2e5 + 5;
int n;
int a[MAX_N], amt[MAX_N];
bool visited[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    FOR(i, n) {
        cin >> a[i];
        amt[a[i]]++;
    }
    int mode = 0;
    for(int i = 1; i < MAX_N; i++) {
        if(amt[i] > amt[mode]) {
            mode = i;
        }
    }
    // queue of indices
    queue<int> q;
    FOR(i, n) {
        if(a[i] == mode) {
            q.push(i);
            visited[i] = true;
        }
    }
    cout << n - amt[mode] << endl;
    while(q.size()) {
        int x = q.front();
        q.pop();
        if(x > 0 && !visited[x - 1]) {
            visited[x - 1] = true;
            q.push(x - 1);
            if(mode > a[x - 1]) {
                cout << "1 " << x << " " << (x + 1) << endl;
            }else {
                cout << "2 " << x << " " << (x + 1) << endl;
            }
        }
        if(x < n - 1  && !visited[x + 1]) {
            visited[x + 1] = true;
            q.push(x + 1);
            if(mode > a[x + 1]) {
                cout << "1 " << (x + 2) << " " << (x + 1) << endl;
            }else {
                cout << "2 " << (x + 2) << " " << (x + 1) << endl;
            }
        }
    }
}