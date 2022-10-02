#include <iostream> 
#include <set>
#include <vector>

using namespace std;
#define x first
#define y second
constexpr int T = 1e6+5;
typedef pair<int,int> pii;
int main() {

    int N, M; cin >> N >> M;
    set<int> Occ{0,N+1};
    set<pii> Options;
    vector<int> Place(T, -1);
    
    auto gen = [&](int x, int y) -> pii {
        ++x; --y;
        if (x > y) return pii{1,-1};
        else if (x == 1) return {-y+1, 1};
        else if (y == N) return {-(N-x), N};
        else return {-((y-x)/2), (x+y)/2};
    };
    auto add = [&](int x, int y) {
        auto g = gen(x,y);
        if (g.x != 1) {
            Options.insert(g);
        }
    };
    auto remove = [&](int x, int y) {
        auto g = gen(x,y);
        if (g.x != 1) {
            Options.erase(g);
        }
    };

    add(0, N+1);

    for (int i = 0; i < M; ++i) {
        int t, c; cin >> t >> c;
        if (t == 1) {
            auto put = *Options.begin();
            Options.erase(put);
            int y = put.y;
            auto it = Occ.insert(y).x;
            add(*prev(it), y);
            add(y, *next(it));
            Place[c] = y;
            cout << y << '\n';
        } else {
            int y = Place[c];
            auto it = Occ.find(y);
            remove(*prev(it), y);
            remove(y, *next(it));
            add(*prev(it), *next(it));
            Occ.erase(it);
        }
    }
    
    
}