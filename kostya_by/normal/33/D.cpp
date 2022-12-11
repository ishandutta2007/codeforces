#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct Tknight
{
    long long x, y;
    int id;
    void scan()
    {
        cin >> x >> y;
      //   cout << x << " " << y << endl;
    }
};

struct Tround
{
    long long x, y, r;
    void scan()
    {
        cin >> r >> x >> y;
     //   cout << x << " " << y << " " << r << endl;
    }
};

long long sqr(long long a)
{
    return a * a;
}

Tknight kk[1111];
Tround rr[1111];
int n, m, k;
vector<int> graf[1111];
int dist[1111][1111];
bool used[1111];
queue<int> qq;

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) kk[i].scan();
    // cout << "-------------------------------------" << endl;
    for (int i = 0; i < m; i++) rr[i].scan();
    // cout << "-------------------------------------" << endl;
    for (int i = 0; i < m; i++)
    {
        int res = -1;
        for (int j = 0; j < m; j++)
        {
            if (rr[j].r <= rr[i].r) continue;
            long long d1 = sqr(rr[i].x - rr[j].x) + sqr(rr[i].y - rr[j].y);
            long long r1 = sqr(rr[i].r) + sqr(rr[j].r) - 2 * rr[i].r * rr[j].r;
            //cout << i << " " << j << " " << d1 << " " << r1 << endl;
            bool fl = (r1 > d1);
            if (fl == false) continue;
            if (res == -1) res = j;
            if (rr[res].r > rr[j].r) res = j;
        }
        if (res == -1) res = m;
        //cout << i << " " << res << endl;
        graf[i].push_back(res);
        graf[res].push_back(i);
    }
    //cout << "-------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        int res = -1;
        for (int j = 0; j < m; j++)
        {
            long long d1 = sqr(kk[i].x - rr[j].x) + sqr(kk[i].y - rr[j].y);
            long long r1 = sqr(rr[j].r);
            bool fl = (r1 > d1);
            if (fl == false) continue;
            if (res == -1) res = j;
            if (rr[res].r > rr[j].r) res = j;
        }
        if (res == -1) res = m;
       // cout << i << " " << res << endl;
        kk[i].id = res;
    }
    for (int i = 0; i < 1111; i++)
        for (int j = 0; j < 1111; j++)
            dist[i][j] = -1;
    for (int i = 0; i <= m; i++)
    {
        qq.push(i);
        dist[i][i] = 0;
        while (qq.size() != 0)
        {
            int v = qq.front();
            qq.pop();
            for (int j = 0; j < graf[v].size(); j++)
            {
                int now = graf[v][j];
                //cout << v << " " << now << endl;
                if (dist[i][now] != -1) continue;
                dist[i][now] = dist[i][v] + 1;
                qq.push(now);
            }
        }
        //cout << "------------------" << endl;
    }
    /*for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++) cout << dist[i][j] << " ";
        cout << endl;
    }
    cout << "-------------------------------------" << endl;*/
   /* for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < graf[i].size(); j++) cout << graf[i][j] << " ";
        cout << endl;
    }*/
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int aa = kk[a - 1].id, bb = kk[b - 1].id;
        //cout << aa << " " << bb << endl;
        printf("%d\n", dist[aa][bb]);
    }
    return 0;
}