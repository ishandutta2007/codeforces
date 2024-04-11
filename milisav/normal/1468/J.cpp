#include<bits/stdc++.h>

using namespace std;

#define pb push_back


struct edge
{
    int x;
    int y;
    int z;
};

const int maxi = 1e6 + 10;
edge a[maxi];
string s;
int gr[maxi];
vector<int> v[maxi];
long long k;
int n, m;
int comp;

void ocisti()
{
    for (int i = 1;i<=n;i++)
    {
        v[i].clear();
        v[i].pb(i);
        gr[i] = i;
    }

    comp = n;
}

bool cmp(edge x, edge y)
{
    return x.z < y.z;
}

int merge(int x, int y)
{
    x = gr[x];
    y = gr[y];

    if (x == y) return 0;

    if (v[x].size() < v[y].size()) swap(x, y);

    for (int i :v[y])
    {
      v[x].pb(i);
      gr[i] = x;
    }
    v[y].clear();
    comp--;

    return 1;
}

void solve()
{
    scanf("%d%d%lld",&n,&m,&k);

    ocisti();

    for (int i = 1;i<=m;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y, &a[i].z);

    sort(a+1, a+m+1, cmp);

    int poz  = -1;

    for (int i = 1;i<=m;i++)
    {
        if (a[i].z > k)
        {
            poz = i;
            break;
        }

        int val = merge(a[i].x, a[i].y);
    }


    if (comp == 1)
    {
        if (poz==-1)
        {
            printf("%lld\n", k - a[m].z);
            return;
        }

        printf("%lld\n", min(a[poz].z - k, k - a[poz-1].z));
        return;
    }

    long long sum = 0;

    for (int i = poz;i<=m;i++)
    {
        int val = merge(a[i].x, a[i].y);
        if (val) sum+=a[i].z-k;
    }

    printf("%lld\n", sum);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
        solve();
    return 0;
}