#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
#define SZ 233333
const int MOD=1e9+7; //or any prime
ll qp(ll a,ll b)
{
    ll x=1; a%=MOD;
    while(b)
    {
        if(b&1) x=x*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return x;
}
namespace linear_seq {
    inline vector<int> BM(vector<int> x)
    {
        //ls: (shortest) relation sequence (after filling zeroes) so far
        //cur: current relation sequence
        vector<int> ls,cur;
        //lf: the position of ls (t')
        //ld: delta of ls (v')
        int lf,ld;
        for(int i=0;i<int(x.size());++i)
        {
            ll t=0;
            //evaluate at position i
            for(int j=0;j<int(cur.size());++j)
                t=(t+x[i-j-1]*(ll)cur[j])%MOD;
            if((t-x[i])%MOD==0) continue; //good so far
            //first non-zero position
            if(!cur.size())
            {
                cur.resize(i+1);
                lf=i; ld=(t-x[i])%MOD;
                continue;
            }
            //cur=cur-c/ld*(x[i]-t)
            ll k=-(x[i]-t)*qp(ld,MOD-2)%MOD/*1/ld*/;
            vector<int> c(i-lf-1); //add zeroes in front
            c.pb(k);
            for(int j=0;j<int(ls.size());++j)
                c.pb(-ls[j]*k%MOD);
            if(c.size()<cur.size()) c.resize(cur.size());
            for(int j=0;j<int(cur.size());++j)
                c[j]=(c[j]+cur[j])%MOD;
            //if cur is better than ls, change ls to cur
            if(i-lf+(int)ls.size()>=(int)cur.size())
                ls=cur,lf=i,ld=(t-x[i])%MOD;
            cur=c;
        }
        for(int i=0;i<int(cur.size());++i)
            cur[i]=(cur[i]%MOD+MOD)%MOD;
        return cur;
    }
    int m; //length of recurrence
//a: first terms
//h: relation
    ll a[SZ],h[SZ],t_[SZ],s[SZ],t[SZ];
//calculate p*q mod f
    inline void mull(ll*p,ll*q)
    {
        for(int i=0;i<m+m;++i) t_[i]=0;
        for(int i=0;i<m;++i) if(p[i])
                for(int j=0;j<m;++j)
                    t_[i+j]=(t_[i+j]+p[i]*q[j])%MOD;
        for(int i=m+m-1;i>=m;--i) if(t_[i])
                //miuns t_[i]x^{i-m}(x^m-\sum_{j=0}^{m-1} x^{m-j-1}h_j)
                for(int j=m-1;~j;--j)
                    t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%MOD;
        for(int i=0;i<m;++i) p[i]=t_[i];
    }
    inline ll calc(ll K)
    {
        for(int i=m;~i;--i)
            s[i]=t[i]=0;
        //init
        s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
        //binary-exponentiation
        while(K)
        {
            if(K&1) mull(s,t);
            mull(t,t); K>>=1;
        }
        ll su=0;
        for(int i=0;i<m;++i) su=(su+s[i]*a[i])%MOD;
        return (su%MOD+MOD)%MOD;
    }
    inline int work(vector<int> x,ll n)
    {
        if(n<int(x.size())) return x[n];
        vector<int> v=BM(x); m=v.size(); if(!m) return 0;
        for(int i=0;i<m;++i) h[i]=v[i],a[i]=x[i];
        return calc(n);
    }
}
using linear_seq::work;
ll k;
int n;
const int maxN = 2005;
bool bad[maxN][maxN];
const int SHIFT = 500;
const int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int dist[maxN][maxN];
int val[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        bad[x + SHIFT][y + SHIFT] = true;
    }
    memset(dist, -1, sizeof dist);
    dist[SHIFT][SHIFT] = 0;
    queue < pair < int, int > > q;
    q.push(make_pair(0, 0));
    int mx = 0;
    while (!q.empty()) {
        auto t = q.front();
        int x = t.first;
        int y = t.second;
        if (dist[x + SHIFT][y + SHIFT] <= 100) val[dist[x + SHIFT][y + SHIFT]]++;
        q.pop();
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < -500 || nx > 500 || ny < -500 || ny > 500) continue;
            if (dist[nx + SHIFT][ny + SHIFT] != -1) continue;
            if (bad[nx + SHIFT][ny + SHIFT]) continue;
            dist[nx + SHIFT][ny + SHIFT] = dist[x + SHIFT][y + SHIFT] + 1;
            //cout << nx << " " << ny << " " << x << " " << y << endl;
            q.push(make_pair(nx, ny));
        }
    }
    vector < int > all;
    for (int i = 0; i <= 100; i++) {
        if (i > 0) val[i] += val[i - 1];
        all.push_back(val[i]);
    }
    if ((ll)all.size() > k) cout << all[k];
    else cout << work(all, k);
    return 0;
}