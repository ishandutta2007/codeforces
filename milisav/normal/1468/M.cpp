#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using namespace std;

#define pb push_back

const int maxi = 2e5 + 10;
const int block = 250;
int n;
int l[maxi];
bitset<maxi> cnt[maxi/block + 20];
vector<int> g[maxi],g1[maxi];
int cn[maxi];
vector<int> v[maxi];
int id[maxi];
int cur;
int poklapa[maxi];
map<int, int> mp, mp1;

mt19937 rng(time(0));

void ocisti()
{
    for (int i = 1; i<=n; i++){
        g[i].clear();
        g1[i].clear();
    }

    for(auto x:mp) {
        v[x.second].clear();
    }
    mp.clear();
    mp1.clear();

}

void solve()
{
    scanf("%d", &n);
    ocisti();

    cur = 0;
    int p = 0;

    for (int i = 1; i<=n; i++)
    {
        scanf("%d",&l[i]);

        for (int j = 1; j<=l[i]; j++)
        {
            int x;
            scanf("%d",&x);
            if (!mp[x])
            {
                mp[x] = ++p;
                x = p;
            } else
            x = mp[x];
            mp1[x]++;
            g1[i].pb(x);
        }
    }
    for (int i = 1; i<=n; i++){

        for (int j:g1[i])
        /*if (mp1[j]>1)*/ g[i].pb(j);

        if (l[i] <= block)
        {
            for (int j:g[i])
                for (int l:g[i])
                    if (l < j) v[l].push_back(j);
        } else
        {
            id[++cur] = i;

            cnt[cur].reset();

            /*for (int j = 1;j<maxi;j++)
                cnt[cur][j] = 0;*/

            for (int j:g[i])
                cnt[cur][j] = 1;
        }
    }

    int x=-1,y=-1;


    bool nasao=false;

    for(auto tc:mp) {
        int i=tc.second;
        for(int j:v[i]) {
            cn[j]++;
            if(cn[j]==2) {
                x=i;
                y=j;
                nasao=true;
            }
        }
        for(int j:v[i]) {
            cn[j]=0;
        }
        if(nasao) {
            break;
        }
    }


    if (nasao)
    {
        int poz1 = 0;
        int poz2 = 0;
        for (int i = 1;i<=n;i++)
            if (l[i] <= block)
        {
            for (int j:g[i])
                for (int l:g[i]){
                    if (l==x && j==y)
                    {
                        if (!poz1) poz1 = i;else poz2 = i;
                    }
                }
        }

        printf("%d %d\n", poz1, poz2);
        return;
    }
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=cur;j++)
            poklapa[j] = 0;

        for (int j:g[i])
            for (int l = 1;l<=cur;l++)
            if (cnt[l][j]) poklapa[l]++;

        for (int l = 1;l<=cur;l++)
            if (poklapa[l] > 1 && id[l] !=i)
        {
            printf("%d %d\n", min(id[l], i), max(id[l], i));
            return;
        }
    }

    printf("-1\n");
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}