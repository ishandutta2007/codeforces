#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200005;

int m[max_n];

vector<int> d;

int main()
{
    int n, k, kneg = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        //scanf("%d", m + i);
        cin >> m[i];
        if (m[i] < 0) kneg++;
    }
    if (kneg > k)
    {
        cout << -1;
        return 0;
    }
    if (kneg == 0)
    {
        cout << 0;
        return 0;
    }
    int lastneg = -1;
    for(int i = 0; i < n; i++)
    {
        if (m[i] >= 0) continue;
        if (lastneg != -1)
        {
            int dist = i - lastneg - 1;
            if (dist > 0) d.push_back(dist);
        }
        lastneg = i;
    }
    int lastdist = -1;
    if (lastneg != -1)
    {
        int dist = n - lastneg - 1;
        if (dist > 0) lastdist = dist;
    }
    //for (int i = 0; i < d.size(); i++) cout << d[i] << ' ';
    /*if (d.size() == 0)
    {
        cout << 1;
        return 0;
    }*/
    int have = k - kneg;
    int curans = 0;
    if (m[0] < 0) curans++;
    for (int i = 1; i < n; i++)
    {
        if (m[i] >=0 && m[i - 1] < 0) curans++;
        if (m[i] <0 && m[i - 1] >= 0) curans++;

    }

    // without last
    int ans1 = curans;
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] > have) break;
        else
        {
            ans1-=2;
            have -= d[i];
        }
    }

    int ans2 = curans;
    have = k - kneg;
    if (lastdist != -1 && lastdist <= have)
    {
        have -= lastdist;
        ans2--;
    }
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] > have) break;
        else
        {
            ans2-=2;
            have -= d[i];
        }
    }

   // cout << ans1 << endl;
   // cout << ans2 << endl;
    cout << min(ans1, ans2);
    return 0;
}