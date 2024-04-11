#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 500005;

int n;
char str[Maxn];
int len[Maxn];
ll val[Maxn];
ll res;
vector <ii> seq;

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    len[n] = 0;
    val[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '0') {
            len[i] = 0;
            if (len[i + 1] > 0)
                seq.push_back(ii(len[i + 1], i + 1));
            val[i] = val[i + 1];
        } else {
            len[i] = len[i + 1] + 1;
            if (!seq.empty() && seq.back().first == len[i])
                seq.pop_back();
            if (seq.empty())
                val[i] = ll(len[i]) * (n - i) - ll(len[i]) * (len[i] - 1) / 2ll;
            else val[i] = val[seq.back().second] + ll(len[i]) * ll(seq.back().second - i);
        }
        res += val[i];
    }
    cout << res << endl;
    return 0;
}