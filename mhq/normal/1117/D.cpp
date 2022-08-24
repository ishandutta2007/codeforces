#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int maxN = 305;
int f[maxN];
#define pb push_back
#define SZ 233333

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int inv(int a) {
    return pw(a, mod - 2);
}

int n, m;
// berlekamp-massey from TLE
const int MOD=mod; //or any prime

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    ll n;
    int m;
    cin >> n >> m;
    vector < int > f(maxN, 0);
    f[0] = 1;
    for (int i = 1; i < maxN; i++) {
        f[i] = f[i - 1];
        if (i >= m) f[i] = sum(f[i], f[i - m]);
    }
    cout << linear_seq::work(f, n);
}