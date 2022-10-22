#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k;
char str[Maxn];
vector <int> seq;
map <int, ll> M;

void Insert(int key, ll val)
{
    map <int, ll>::iterator it = M.upper_bound(key);
    if (it != M.begin()) {
        it--;
        if (it->second <= val) return;
    }
    it = M.lower_bound(key);
    while (it != M.end() && val <= it->second)
        M.erase(it++);
    M[key] = val;
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        if (str[i] == '1') seq.push_back(i);
    Insert(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        map <int, ll>::iterator it = M.end(); it--;
        if (it->first == i + 1) {
            ll val = it->second; M.erase(it);
            Insert(i, val + i + 1);
            int ind = lower_bound(seq.begin(), seq.end(), i - k) - seq.begin();
            if (ind < seq.size() && seq[ind] - k <= i)
                Insert(max(seq[ind] - k, 0), val + seq[ind] + 1);
        }
    }
    cout << M.begin()->second << endl;
    return 0;
}