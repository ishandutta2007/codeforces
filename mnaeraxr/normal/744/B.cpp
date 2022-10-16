#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef bitset<1000> B;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct st{
    int n;
    vector<B> question;
    vector<vi> answer;

    st(int n) : n(n){
        question = vector<B>(20);
        answer = vector<vi>(20);
    }

    void build(int level, int b, int e){
        if (level == 10) return;

        int u = 2 * level, v = u + 1;
        int m = (b + e) >> 1;

        for (int i = b; i < e; ++i){
            if (i < m) question[u].set(i);
            else question[v].set(i);
        }

        if (b + 1 < e){
            build(level + 1, b, m);
            build(level + 1, m, e);
        }
    }

    void go(){
        for (int i = 0; i < 20; ++i){
            int c = question[i].count();
            if (c == 0) continue;

            cout << question[i].count() << endl;
            for (int j = 0; j < n; ++j)
                if (question[i].test(j)) cout << j + 1 << " ";
            cout << endl;
            cout.flush();

            answer[i] = vi(n);

            for (int j = 0; j < n; ++j)
                cin >> answer[i][j];
        }
    }

    int query(int x){
        int ans = oo;
        for (int i = 0; i < 20; ++i){
            int c = question[i].count();
            if (c > 0 && !question[i].test(x))
                ans = min(ans, answer[i][x]);
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    st handler(n);

    handler.build(0, 0, n);

    for (int i = 0; i < 20; ++i){
        int c = handler.question[i].count();
        if (!c) continue;
    }

    handler.go();

    cout << -1 << endl;

    for (int i = 0; i < n; ++i)
        cout << handler.query(i) << " ";

    cout << endl;
    cout.flush();

    return 0;
}