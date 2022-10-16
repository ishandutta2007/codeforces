#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 300010;

vi events[maxn];
int pnt[maxn];
bool active[maxn];
int last;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;

    int answer = 0;
    int b = 1;

    for (int i = 1; i <= q; ++i){
        int t, x;
        cin >> t >> x;

        if (t == 1){
            active[b] = true;
            events[x].push_back(b);
            b++;
            answer++;
        }
        else if (t == 2){
            for (; pnt[x] < (int)events[x].size(); ++pnt[x]){
                int u = events[x][pnt[x]];
                if (active[u]){
                    answer--;
                    active[u] = false;
                }
            }
        }
        else{
            for (;last <= x; ++last){
                if (active[last]){
                    answer--;
                    active[last] = false;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}