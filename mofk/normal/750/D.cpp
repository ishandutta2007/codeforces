#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef pair <ii, ii> candle;

int N;
set <ii> visited;
set <candle> s, news;

void work(int step) {
    for (set <candle> :: iterator it = s.begin(); it != s.end(); ++it) {
        ii cord = it -> first, proj = it -> second;
        ff(i, 1, step) visited.insert(ii(cord.first + proj.first * i, cord.second + proj.second * i));
        ii last = ii(cord.first + proj.first * step, cord.second + proj.second * step);
        ii n1, n2;
        if (proj.first == 0) n1 = ii(-1, proj.second), n2 = ii(1, proj.second);
        else if (proj.second == 0) n1 = ii(proj.first, -1), n2 = ii(proj.first, 1);
        else n1 = ii(0, proj.second), n2 = ii(proj.first, 0);
        news.insert(candle(last, n1));
        news.insert(candle(last, n2));
    }
    s.swap(news); news.clear();
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    s.insert(candle(ii(0, 0), ii(0, 1)));
    int x;
    ff(i, 1, N) cin >> x, work(x);
    cout << visited.size() << endl;
    return 0;
}