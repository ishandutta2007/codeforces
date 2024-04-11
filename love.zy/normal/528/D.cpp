
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

const int mod=2146959361;
const int root=19;
const int maxn=1048576;

inline int mul(int a, int b, int mod){ return (long long)a*b%mod; }
int power(int a, int b, int mod){
	int ret = 1;
	for (int t = a; b; b >>= 1){
		if (b & 1)ret = mul(ret, t, mod);
		t = mul(t, t, mod);
	}
	return ret;
}
int cal_root(int mod)
{
	int factor[20], num = 0, m = mod - 1, s = m;
	for (int i = 2; i * i <= s; i++){
		if (s % i == 0){
			factor[num++] = i;
			while (s % i == 0)s /= i;
		}
	}
	if (s != 1)factor[num++] = s;
	for (int i = 2;; i++){
		int j = 0;
		for (; j < num && power(i, m / factor[j], mod) != 1; j++);
		if (j == num)return i;
	}
}
template<int MOD, int ROOT>
void fft_main(int a[], int len, bool reverse)
{
	for (int i = 1, j = len / 2; i < len - 1; i++) {
		if (i < j) swap(a[i], a[j]);
		for (int k = len; j < k; k >>= 1, j ^= k);
	}
	for (int i = 1, s = 1; s < len; i++, s <<= 1){
		int t = (MOD - 1) / (s * 2);
		int step = power(ROOT, reverse ? MOD - 1 - t : t, MOD);
		for (int j = 0; j < len; j += 2 * s){
			int cur = 1;
			for (int k = j; k < j + s; k++){
				int u = a[k], t = mul(cur, a[k + s], MOD);
				a[k] = (unsigned int)(u + t) % MOD;
				a[k + s] = (unsigned int)(u - t + MOD) % MOD;
				cur = mul(cur, step, MOD);
			}
		}
	}
	if (reverse){
		int t = power(len, MOD - 2, MOD);
		for (int i = 0; i < len; i++)
			a[i] = mul(a[i], t, MOD);
	}
}
//mod(mod<2^30)2^(logn+1)
//modm*2^k+12^k>=2*n
template<int MOD, int ROOT>
void fft(int a[], int b[], int n)
{
	int len = 1;
	while (len < 2 * n)len <<= 1;
	memset(a + n, 0, sizeof(int)*(len - n));
	memset(b + n, 0, sizeof(int)*(len - n));
	fft_main<MOD, ROOT>(a, len, 0);
	fft_main<MOD, ROOT>(b, len, 0);
	for (int i = 0; i < len; i++)
		a[i] = mul(a[i], b[i], MOD);
	fft_main<MOD, ROOT>(a, len, 1);
}
template<int MOD, int ROOT>
void fft(int a[], int n)
{
	int len = 1;
	while (len < 2 * n)len <<= 1;
	memset(a + n, 0, sizeof(int)*(len - n));
	fft_main<MOD, ROOT>(a, len, 0);
	for (int i = 0; i < len; i++)
		a[i] = mul(a[i], a[i], MOD);
	fft_main<MOD, ROOT>(a, len, 1);
}
//167772161, 469762049, 754974721, 2146959361
//3 3 11 19
char s[maxn],t[maxn];
int a[maxn],b[maxn],ans[maxn];
int n,m,k;
int pre[maxn];

void solve(char c)
{
    for(int i=0;i<1048576;i++)a[i]=b[i]=pre[i]=0;
    for(int i=0;i<n;i++)
        if(s[i]==c)
        {
            pre[max(i-k,0)]++;
            pre[min(i+k+1,n)]--;
        }
    for(int i=0;i<n;i++)
    {
        if(i>0)pre[i]+=pre[i-1];
        if(pre[i]>0)a[i]=1;
    }
    for(int i=m-1;i>=0;i--)
        if(t[i]==c)b[m-1-i]=1;
    fft<mod,root>(a,b,n);
    for(int i=0;i<1048576;i++)ans[i]+=a[i];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",s);scanf("%s",t);
    solve('A');solve('T');solve('G');solve('C');
    int da=0;
    for(int i=0;i<2*n;i++)
        if(ans[i]>=m)da++;
    printf("%d\n",da);
    return 0;
}