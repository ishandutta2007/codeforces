#include <iostream>
#define N 1001
#define f first
#define s second

using namespace std;

int64_t w[N], h[N];

int main()
{
    int n;
    int64_t sw = 0, sq = 1000000000000000ll;
    int64_t tw = sw, mh = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i] >> h[i];
        if (w[i] > h[i])
            swap(w[i], h[i]);
        sw += w[i];
    }
    for (int i = 0; i < n; ++i)
    {
        tw = sw, mh = 0;
        for (int j = 0; j < n; ++j)
            if (h[j] > h[i])
                tw += h[j] - w[j], mh = max(mh, w[j]);
            else
                mh = max(mh, h[i]);
        sq = min(sq, tw * mh);
    }
    tw = sw, mh = 0;
    for (int j = 0; j < n; ++j)
        tw += h[j] - w[j], mh = max(mh, w[j]);
    cout << min(sq, tw * mh);
    return 0;
}