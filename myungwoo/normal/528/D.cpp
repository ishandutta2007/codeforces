#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

const double my_pi = 3.141592653589;
#define MAXL 200005
typedef complex<double> base;

void fft(vector <base> &a, bool invert)
{
    int n = sz(a);
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*my_pi/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}

void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < max(sz(a),sz(b))) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

void my_fft(vector <int> &a, vector <int> &b, vector <int> &c)
{
    vector <int> my_a, my_b, res;
    int n = sz(a);
    for (int i=0;i<n;i++) my_a.pb(0), my_b.pb(0);
    for (int i=0;i<n;i++) my_a.pb(a[i]), my_b.pb(b[i]);
    for (int i=0;i<n;i++) my_a.pb(0); my_b.pb(0);
    multiply(my_a, my_b, res);
    c.clear();
    for (int i=n+n;i<n+n+n;i++) c.pb(res[i]);
}

int N, M, K;
int C[MAXL], num[128];
int chk[MAXL];
char A[MAXL], P[MAXL];

int main()
{
    ios_base::sync_with_stdio(false);
    num['A'] = 0, num['C'] = 1, num['G'] = 2, num['T'] = 3;
    cin >> N >> M >> K >> A+1 >> P+1;
    vector <int> cnt(4, 0);
    for (int i=1;i<=N;i++){
        cnt[num[A[i]]]++;
        if (i-K-1 > 0) cnt[num[A[i-K-1]]]--;
        for (int j=0;j<4;j++) if (cnt[j]) C[i] |= (1 << j);
    }
    cnt.clear(); cnt.resize(4, 0);
    for (int i=N;i;i--){
        cnt[num[A[i]]]++;
        if (i+K+1 <= N) cnt[num[A[i+K+1]]]--;
        for (int j=0;j<4;j++) if (cnt[j]) C[i] |= (1 << j);
    }
    for (int i=0;i<4;i++){
        int tot = 0;
        vector <int> a(N, 0), b(N, 0);
        for (int j=1;j<=N;j++) a[j-1] = (bool)(C[j] & (1 << i));
        for (int j=1;j<=M;j++) b[M-j] = (num[P[j]] == i), tot += b[M-j];
        vector <int> c;
        my_fft(a, b, c);
        for (int i=M-1;i<N;i++) if (c[i] == tot) chk[i]++; 
    }
    int ans = 0;
    for (int i=0;i<N;i++) if (chk[i] == 4) ans++;
    printf("%d\n", ans);
}