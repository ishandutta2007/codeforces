#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int num[max_n] = {0};

vector<int> v;

void factor(int a)
{
    v.clear();
    if (a == 1) return;
    for (int i = 2; i * i <= a; ++i)
    {
        if (a % i == 0)
        {
            v.push_back(i);
            a /= i;
            i--;
        }
    }
    v.push_back(a);
}


int main()
{
    //ifstream cin("input.txt");
    int n;
    cin >> n;
    int m[max_n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", m + i);
        if (m[i] == 1) continue;
        factor(m[i]);
        num[v[0]]++;
        for (int j = 1; j < v.size(); ++j)
        {
            if (v[j] != v[j - 1])
            num[v[j]]++;
        }
    }

    int ans = 1;

    for (int i = 2; i < max_n; ++i)
    {
        ans = max(ans, num[i]);
    }

    cout << ans;

    return 0;
}