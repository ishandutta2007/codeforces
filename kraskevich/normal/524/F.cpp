#include <bits/stdc++.h>

using namespace std;

const int N = 2000 * 1000;

int pos[N];
int new_pos[N];
int c[N];
int new_c[N];
int head[N];
int cnt[N];
string s;
int n;

int low(int i, int step)
{
    i -= step;
    if (i < 0)
        i += n;
    return i;
}

int high(int i, int step)
{
    i += step;
    if (i >= n)
        i -= n;
    return i;
}

bool are_same(int p1, int p2, int step)
{
    if (c[p1] != c[p2])
        return false;
    p1 = high(p1, step);
    p2 = high(p2, step);
    if (c[p1] != c[p2])
        return false;
    return true;
}

void build_array()
{
    n = s.length();
    fill(head, head + N, 0);
    fill(cnt, cnt + N, 0);

    for (int i = 0; i < n; ++i)
        ++cnt[s[i]];
    for (int i = 1; i < N; ++i)
        head[i] = head[i - 1] + cnt[i - 1];
    for (int i = 0; i < n; ++i)
    {
        c[i] = s[i];
        pos[head[c[i]]++] = i;
    }
    head[0] = 0;
    for (int i = 1; i < N; ++i)
        head[i] = head[i - 1] + cnt[i - 1];
    for (int step = 1; step <= n; step *= 2)
    {
        for (int i = 0; i < n; ++i)
        {
            int cur = low(pos[i], step);
            new_pos[head[c[cur]]++] = cur;
        }
        head[0] = 0;
        new_c[new_pos[0]] = 0;
        bool all_diff = true;
        for (int i = 1; i < n; ++i)
            if (are_same(new_pos[i], new_pos[i - 1], step))
            {
                new_c[new_pos[i]] = new_c[new_pos[i - 1]];
                all_diff = false;
            }
            else
            {
                new_c[new_pos[i]] = new_c[new_pos[i - 1]] + 1;
                head[new_c[new_pos[i]]] = i;
            }
        copy(new_c, new_c + n, c);
        copy(new_pos, new_pos + n, pos);
        if (all_diff)
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> s;
    build_array();
    vector<int> bal(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            sum++;
         else
            sum--;  
         bal[i] = sum;
    }
    int tot = sum;
    vector<int> suffMin(n + 1, N);
    for (int i = n - 1; i >= 0; i--)
        suffMin[i] = min(bal[i], suffMin[i + 1]);
    vector<bool> good(n);
    int curMin = N;
    for (int i = 0; i < n; i++) {
        int old = i == 0 ? 0 : bal[i - 1];
        bool ok = true;
        if (suffMin[i] - old < min(tot, 0))
            ok = false;
        if (tot - old + curMin < min(tot, 0))
            ok = false;
        if (ok)
            good[i] = true; 
        curMin = min(curMin, bal[i]);
    }
    int start = 0;
    for (int i = 0; i < n; i++)
        if (good[pos[i]]) {
            start = pos[i];
            break;
        }
    for (int i = 0; i < -sum; i++) 
        cout << "(";
    for (int i = 0; i < n; i++)
        cout << s[(i + start) % n];
    for (int i = 0; i < sum; i++)
        cout << ")";
    cout << "\n";
    return 0;
}