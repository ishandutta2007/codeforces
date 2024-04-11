#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

const long long mod = 1000000007;
char S[505];

void add(long long &a, long long b)
{
    a = (a + b) % mod;
}

vector<long long> andconv(vector<long long> p, vector<long long> q)
{
    int n = p.size();
    vector<long long> r(n,0);
    if (n <= 16){
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) add(r[i&j],p[i]*q[j]);
    }
    else{
        n /= 2;
        vector<long long> a(p.begin()+n,p.end());
        vector<long long> c(q.begin()+n,q.end());
        vector<long long> u = andconv(a,c);
        for (int i=0;i<n;i++){
            a[i] += p[i]; c[i] += q[i];
            if (a[i] >= mod) a[i] -= mod;
            if (c[i] >= mod) c[i] -= mod;
        }
        vector<long long> v = andconv(a,c);
        for (int i=0;i<n;i++){
            r[i+n] = u[i];
            r[i] = v[i] - u[i];
            if (r[i] < 0) r[i] += mod;
        }
    }
    return r;
}

vector<long long> orconv(vector<long long> p, vector<long long> q)
{
    int n = p.size();
    vector<long long> r(n,0);
    if (n <= 16){
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) add(r[i|j],p[i]*q[j]);
    }
    else{
        n /= 2;
        vector<long long> b(p.begin(),p.begin()+n);
        vector<long long> d(q.begin(),q.begin()+n);
        vector<long long> u = orconv(b,d);
        for (int i=0;i<n;i++){
            b[i] += p[i+n]; d[i] += q[i+n];
            if (b[i] >= mod) b[i] -= mod;
            if (d[i] >= mod) d[i] -= mod;
        }
        vector<long long> v = orconv(b,d);
        for (int i=0;i<n;i++){
            r[i+n] = v[i] - u[i];
            r[i] = u[i];
            if (r[i+n] < 0) r[i+n] += mod;
        }
    }
    return r;
}

vector<long long> go(int s, int e)
{
    vector<long long> r(1<<16);
    if (s == e){
        string mem = "ABCDabcd";
        for (int i=0;i<8;i++){
            if (S[s] != '?' && S[s] != mem[i]) continue;
            int c = 0, p = i % 4;
            for (int v=0;v<16;v++) if ((i < 4 ? v : ~v) & (1 << p)) c += 1 << v;
            r[c]++;
        }
    }
    else{
        int c = 0;
        for (int i=s;i<=e;i++){
            if (S[i] == '(') c++;
            else if (S[i] == ')') c--;
            if (c == 0){
                i++;
                vector<long long> a = go(s+1,i-2), b = go(i+2,e-1);
                if (S[i] == '&' || S[i] == '?'){
                    vector<long long> c = andconv(a,b);
                    for (int j=0;j<r.size();j++) r[j] += c[j];
                }
                if (S[i] == '|' || S[i] == '?'){
                    vector<long long> d = orconv(a,b);
                    for (int j=0;j<r.size();j++) r[j] += d[j];
                }
                for (int j=0;j<r.size();j++) if (r[j] >= mod) r[j] -= mod;
                break;
            }
        }
    }
    return r;
}

int main()
{
    scanf ("%s",S);
    int L = 0; while (S[L]) L++;

    vector<long long> u = go(0,L-1);

    int free = (1 << 16) - 1, fix = 0;
    int N; scanf ("%d",&N);
    for (int i=0;i<N;i++){
        int u = 0;
        for (int j=0;j<4;j++){
            int x; scanf ("%d",&x);
            if (x) u += 1 << j;
        }
        free -= (1<<u);
        int x; scanf ("%d",&x);
        if (x) fix += (1<<u);
    }

    long long ans = 0;
    for (int i=free;;i=(i-1)&free){
        ans = (ans + u[i+fix]);
        if (i == 0) break;
    }
    ans %= mod;
    printf ("%lld\n",ans);

    return 0;
}