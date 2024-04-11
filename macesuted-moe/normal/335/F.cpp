#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;

map<long long, int> m;

typedef pair<long long, int> rec;

rec a[maxn];
priority_queue<long long, vector<long long>, greater<long long> > que;
queue<long long> tmp;
int cnt = 0;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        long long p;
        scanf("%lld", &p);
        m[p]++;
    }
    for (map<long long, int>::iterator i = m.begin(); i != m.end(); i++)
        a[cnt++] = (rec){i->first, i->second};
    sort(a, a + cnt, greater<rec>());
    int pre = 0;
    long long answer = 0;
    for (int i = 0; i < cnt; i++)
    {
        long long p = a[i].first;
        int m = a[i].second;
        answer += p * m;
        int tm = max(min(pre - ((int)que.size() << 1), m), 0);
        for (int j = 0; j < tm; j++)
            tmp.push(p);
        for (int j = tm; j < m && !que.empty(); j += 2)
        {
            int cac = que.top();
            que.pop();
            if (p > cac)
            {
                tmp.push(p);
                if (j != m - 1)
                    tmp.push(p);
            }
            if (p <= cac)
            {
                tmp.push(cac);
                if (j != m - 1 && (p << 1) >= cac)
                    tmp.push((p << 1) - cac);
            }
        }
        while (!tmp.empty())
        {
            que.push(tmp.front());
            tmp.pop();
        }
        pre += m;
    }
    while (!que.empty())
    {
        answer -= que.top();
        que.pop();
    }
    printf("%lld\n", answer);
    return 0;
}//new