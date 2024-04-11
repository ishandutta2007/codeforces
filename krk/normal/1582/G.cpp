#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const int Inf = 1000000000;

int mx[Maxn];
int n;
int a[Maxn];
vector <ii> seq[Maxn];
int nil[Maxn];
char b[Maxn];
map <int, int> M;
ll res;

void Add(int x)
{
    auto it = M.find(x);
    if (it != M.end())
        it->second++;
    else M.insert(make_pair(x, 1));
}

void Rem(int x)
{
    auto it = M.find(x);
    if (it->second == 1) M.erase(it);
    else it->second--;
}

int main()
{
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
        for (int j = i; j < Maxn; j += i)
            mx[j] = i;
    scanf("%d", &n);
    Add(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%s", b + 1);
    for (int i = n; i > 0; i--) {
        int num = a[i];
        while (num > 1) {
            int cur = mx[num], cnt = 0;
            while (mx[num] == cur) {
                cnt++;
                num /= cur;
            }
            if (b[i] == '/') {
                seq[cur].push_back(ii(-nil[cur], i));
                nil[cur] -= cnt;
                Add(i);
            } else {
                nil[cur] += cnt;
                while (!seq[cur].empty() && seq[cur].back().first + nil[cur] >= 0) {
                    Rem(seq[cur].back().second);
                    seq[cur].pop_back();
                }
            }
        }
        res += M.begin()->first - i;
    }
    cout << res << endl;
    return 0;
}