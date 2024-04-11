#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 3005;
const int Inf = 1000000000;

int n;
pair <int, string> seq[Maxn];
int h[Maxn], togive = Inf;
int sorted[Maxn], len;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> seq[i].second >> seq[i].first;
    sort(seq, seq + n);
    int i;
    for (i = 0; i < n && seq[i].first <= i; i++) {
        h[i] = togive;
        if (i == 0) { sorted[len++] = togive--; continue; }
        int ind = len - 1 - seq[i].first;
        int delta = togive - 1 - sorted[ind];
        for (int j = 0; j < i; j++)
            if (h[j] <= sorted[ind]) h[j] += delta;
        for (int j = 0; j <= ind; j++) sorted[j] += delta;
        len++;
        for (int j = len - 2; j >= ind + 1; j--) sorted[j + 1] = sorted[j];
        sorted[ind + 1] = h[i];
        togive = sorted[0] - 1;
    }
    if (i < n) cout << "-1\n";
    else for (int i = 0; i < n; i++)
             cout << seq[i].second << " " << h[i] << endl;
    return 0;
}