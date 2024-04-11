#include<cstdio>
#include<vector>
using namespace std;
unsigned long long kth_root(unsigned long long a, int k) {
  if(k == 1) return a;
  auto check = [&](unsigned int x) {
    unsigned long long mul = 1;
    for(int j = 0; j < k; j++) {
	  if(mul>a/x)return false;
	  mul*=x;
    }
    return true;
  };
  unsigned long long ret = 0;
  for(int i = 31; i >= 0; i--) {
    if(check(ret | (1u << i))) ret |= 1u << i;
  }
  return ret;
}

vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

template< long long LIM = 100000000000LL >
struct PrimeCount {
private:
  long long sq;
  vector< bool > prime;
  vector< long long > prime_sum, primes;

  long long p2(long long x, long long y) {
    if(x < 4) return 0;
    long long a = pi(y);
    long long b = pi(kth_root(x, 2));
    if(a >= b) return 0;
    long long sum = (a - 2) * (a + 1) / 2 - (b - 2) * (b + 1) / 2;
    for(long long i = a; i < b; i++) sum += pi(x / primes[i]);
    return sum;
  }

  long long phi(long long m, long long n) {
    if(m < 1) return 0;
    if(n > m) return 1;
    if(n < 1) return m;
    if(m <= primes[n - 1] * primes[n - 1]) return pi(m) - n + 1;
    if(m <= primes[n - 1] * primes[n - 1] * primes[n - 1] && m <= sq) {
      long long sx = pi(kth_root(m, 2));
      long long ans = pi(m) - (sx + n - 2) * (sx - n + 1) / 2;
      for(long long i = n; i < sx; ++i) ans += pi(m / primes[i]);
      return ans;
    }
    return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
  }

public:

  PrimeCount() : sq(kth_root(LIM, 2)), prime_sum(sq + 1) {
    prime = prime_table(sq);
    for(int i = 1; i <= sq; i++) prime_sum[i] = prime_sum[i - 1] + prime[i];
    primes.reserve(prime_sum[sq]);
    for(int i = 1; i <= sq; i++) if(prime[i]) primes.push_back(i);
  }

  long long pi(long long n) {
    if(n <= sq) return prime_sum[n];
    long long m = kth_root(n, 3);
    long long a = pi(m);
    return phi(n, a) + a - 1 - p2(n, m);
  }
};
long long N;
main()
{
	scanf("%lld",&N);
	PrimeCount<>pc;
	int K=kth_root(N,3);
	long long ans=pc.pi(K);
	int sq=kth_root(N,2);
	vector<bool>pre=prime_table(sq);
	int prv=0;
	for(int i=1;i<=sq;i++)if(pre[i])
	{
		long long cnt=pc.pi(N/i);
		ans+=cnt-++prv;
	}
	printf("%lld\n",ans);
}