#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int mod = 998244353;
const int K = 19;
const int K_N = (1 << (K + 1));
vector <vector <int> > nodes[K_N];
int len[K_N];
int have[K_N];
void go_to(int v, int s, int i, int k)
{
    if(i == k)
    {
        if(have[s])
        {
            nodes[v].push_back({0, 0, K_N});
        }
        else
        {
            nodes[v].push_back({-1, -1, -1});
        }
        return;
    }
    else
    {
        go_to(v * 2, s * 2, i + 1, k);
        go_to(v * 2 + 1, s * 2 + 1, i + 1, k);
        int t1 = (1 << (k - i - 1));
        for(int u = 0; u < (1 << (k - i)); u++)
        {
            int u1 = u & ((1 << (k - i - 1)) - 1);
            if(nodes[v * 2][u1][0] == -1 && nodes[v * 2 + 1][u1][0] == -1)
            {
                nodes[v].push_back({-1, -1, -1});
            }
            else if(nodes[v * 2][u1][0] == -1)
            {
                if(u & t1)
                {
                    nodes[v].push_back(nodes[v * 2 + 1][u1]);
                }
                else
                {
                    nodes[v].push_back({nodes[v * 2 + 1][u1][0] + t1, nodes[v * 2 + 1][u1][1] + t1, nodes[v * 2 + 1][u1][2]});
                }
            }
            else if(nodes[v * 2  + 1][u1][0] == -1)
            {
                if(u & t1)
                {
                    nodes[v].push_back({nodes[v * 2][u1][0] + t1, nodes[v * 2][u1][1] + t1, nodes[v * 2][u1][2]});
                }
                else{
                    nodes[v].push_back(nodes[v * 2][u1]);
                }
            }
            else
            {
                if(u & (1 << (k - i - 1)))
                {
                    int d1 = min(nodes[v * 2][u1][2], nodes[v * 2 + 1][u1][2]);
                    d1 = min(d1, nodes[v * 2][u1][0] + t1 - nodes[v * 2 + 1][u1][1]);
                    nodes[v].push_back({nodes[v * 2 + 1][u1][0], nodes[v * 2][u1][1] + t1, d1});
                }
                else
                {
                    int d1 = min(nodes[v * 2][u1][2], nodes[v * 2 + 1][u1][2]);
                    d1 = min(d1, nodes[v * 2 + 1][u1][0] + t1 - nodes[v * 2][u1][1]);
                    nodes[v].push_back({nodes[v * 2][u1][0], nodes[v * 2 + 1][u1][1] + t1, d1});
                }
            }
        }/*
        cout << v << " " << s << "\n";
        for(auto vec : nodes[v])
        {
            cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";
        }*/
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        have[x] = 1;
    }
    go_to(1, 0, 0, k);
    for(int i = 0; i < (1 << k); i++)
    {
        cout << nodes[1][i][2] << " ";
    }
    return 0;
}