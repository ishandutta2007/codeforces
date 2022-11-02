#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
const int N = 2e3+10;
const int M = 2e3;
int n,m,q,i,j,inv  = 500000004;
long long dp[N][M];
using pii = pair<int,int>;
using pll = pair<long long,long long>;
vector<pii> tree[N];
bool visit[N][M];
long long maxi[N];
long long total_maxi;
long long cur_max, prv = M-1;
vector<pll> com;
vector<int> index;
vector<pll> ori;

long long plusi(long long a, long long b)
{
    a = (a+b)%MOD;
    return a;
}

long long multi(long long a, long long b)
{
    a%=MOD; b%=MOD;
    a = (a*b)%MOD;
    return a;
}

long long swap_place(pll u, pll v)
{
    long long a = u.first, b = u.second;
    long long c = v.first, d = v.second;
    long long x;
    if(d>b)
        x = (a-c+d-b-1)/(d-b);
    else
        x = -1;
    return x;
}

int main()
{
    cin>>n>>m>>q;
    for(i=0;i<m;i++)
    {
        int a,b;
        long long c;
        cin>>a>>b>>c;
        tree[a-1].push_back({b-1,c});
        tree[b-1].push_back({a-1,c});
        maxi[a-1] = max(maxi[a-1],c);
        maxi[b-1] = max(maxi[b-1],c);
    }
    visit[0][0] = true;
    for(i=1;i<M;i++)
    {
        cur_max = 0;
        for(j=0;j<n;j++)
        {
            if(visit[j][i-1])
            {
                for(auto it: tree[j])
                {
                    int a = it.first;
                    int b = it.second;
                    visit[a][i] = true;
                    dp[a][i] = max(dp[a][i],dp[j][i-1] + b);
                    cur_max = max(cur_max,dp[a][i]);
                }
            }
        }
        if(i<=q)
            total_maxi = plusi(total_maxi,cur_max);
    }
    if(q<M)
        cout<<total_maxi%MOD;
    else
    {
        for(i=0;i<n;i++)
            ori.push_back({dp[i][M-1],maxi[i]});
        sort(ori.begin(),ori.end());
        pll previous = ori.back();
        com.push_back({previous.first,0});
        previous = com.back();
        for(i=0;i<n;i++)
        {
            pll u = ori.back();
            ori.pop_back();
            long long cur = swap_place(previous,u)+M-1;
            if(cur!=M-2)
            {
                while(cur<prv)
                {
                    index.pop_back();
                    com.pop_back();
                    prv = index.back();
                    previous = com.back();
                    cur = swap_place(previous,u)+M-1;
                }
                index.push_back(cur);
                com.push_back(u);
                prv = cur;
                previous = u;
            }
        }
        long long here = M;
        int pointer = 1;
        index.push_back(1e9+10);
        while(here < q+1)
        {
            if(index[pointer] <= q+1)
            {
                long long cur = 0LL;
                cur = multi(index[pointer]+here-2*M+1, index[pointer]-here);
                cur = multi(cur,inv);
                cur = multi(cur, com[pointer].second);
                long long base = multi(index[pointer]-here,com[pointer].first);
                total_maxi = plusi(total_maxi,cur);
                total_maxi = plusi(total_maxi,base);
                here = index[pointer];
            }
            else
            {
                long long cur = 0LL;
                cur = multi(q+1+here-2*M+1, q+1-here);
                cur = multi(cur,inv);
                cur = multi(cur, com[pointer].second);
                long long base = multi(q+1-here,com[pointer].first);
                total_maxi = plusi(total_maxi,cur);
                total_maxi = plusi(total_maxi,base);
                here = q+1;
            }
            pointer++;
        }
        cout<<total_maxi<<"\n";
    }
    return 0;
}