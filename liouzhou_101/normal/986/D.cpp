#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

typedef pair<ll, int> pli;

#define X first
#define Y second

/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
rbtree T;
*/

#include <gmp.h>

extern "C" {
  // SPOJ, codechef, ideone (64-bit)
  const char* gmp_path = "/usr/lib64/libgmp.so.10";
  void* __libc_dlopen_mode(const char* x, int y);
  void* __libc_dlsym(void* x, const char* y);
  #define DLOPEN __libc_dlopen_mode
  #define DLSYM __libc_dlsym
}

namespace gmp {

void* p = DLOPEN(gmp_path, 2);
void* get(const char* name) { return DLSYM(p, name); }
#define D(name) const auto my_##name = (decltype(name)*) get("__g" #name)
D(mpz_init); D(mpz_init_set_ui); D(mpz_init_set); D(mpz_init_set_str);
D(mpz_clear); 
D(mpz_set); D(mpz_set_ui); 
D(mpz_swap);
D(mpz_set_str); D(mpz_get_str);
D(mpz_inp_str); D(mpz_out_str);

D(mpz_neg);
D(mpz_add); D(mpz_add_ui);
D(mpz_sub); D(mpz_sub_ui);
D(mpz_mul); D(mpz_mul_ui); D(mpz_mul_2exp);
D(mpz_tdiv_r); D(mpz_tdiv_q); D(mpz_tdiv_qr); D(mpz_tdiv_q_2exp);
D(mpz_divexact); D(mpz_divexact_ui);
D(mpz_pow_ui); 
D(mpz_sqrt);

D(mpz_xor); D(mpz_and); D(mpz_ior);
D(mpz_cmp);
#undef D

struct mpz {
  mpz() { my_mpz_init(n); }
  mpz(mp_limb_t v) { my_mpz_init_set_ui(n, v); }
  mpz(const mpz& v) { my_mpz_init_set(n, v.n); }
  mpz(const char* str) { my_mpz_init_set_str(n, str, 10); }
  ~mpz() { my_mpz_clear(n); }

  void set(const mpz& rhs) { my_mpz_set(n, rhs.n); }
  void set_ui(mp_limb_t i) { my_mpz_set_ui(n, i); }
  void inp_str(FILE* fp=stdin, int base=10) { my_mpz_inp_str(n, fp, base); }
  void set_str(char* str, mp_limb_t base=10) { my_mpz_set_str(n, str, base); }
  void get_str(char* str, mp_limb_t base=10) { my_mpz_get_str(str, base, n); }

  void print(FILE* fp=stdout) { my_mpz_out_str(fp, 10, n); }
  void println(FILE* fp=stdout) { print(fp); fprintf(fp, "\n"); }

  static void add(mpz& c, mpz& a, mpz& b) { my_mpz_add(c.n, a.n, b.n); }
  static void mul(mpz& c, mpz& a, mpz& b) { my_mpz_mul(c.n, a.n, b.n); }
  static void mul_ui(mpz& c, mpz& a, mp_limb_t b) { my_mpz_mul_ui(c.n, a.n, b); }
  static void sqrt(mpz& dest, mpz& src) { my_mpz_sqrt(dest.n, src.n); }
  static void divmod(mpz& q, mpz& r, mpz& n, mpz& d) { my_mpz_tdiv_qr(q.n, r.n, n.n, d.n); }
  static void div(mpz& q, mpz& n, mpz& d) { my_mpz_tdiv_q(q.n, n.n, d.n); }
  static void divexact(mpz &q, mpz& n, mpz& d) { my_mpz_divexact(q.n, n.n, d.n); }
  static void mod(mpz& r, mpz& n, mpz& d) { my_mpz_tdiv_r(r.n, n.n, d.n); }
  static void swap(mpz& a, mpz& b) { my_mpz_swap(a.n, b.n); }

  void negate() { my_mpz_neg(n, n); }
  void pow_ui(mp_limb_t e) { my_mpz_pow_ui(n, n, e); }
  void divexact_ui(mp_limb_t c) { my_mpz_divexact_ui(n, n, c); }
  void divexact(mpz& rhs) { my_mpz_divexact(n, n, rhs.n); }
  bool operator == (mpz& rhs) { return my_mpz_cmp(n, rhs.n) == 0; }
  bool operator <= (mpz& rhs) { return my_mpz_cmp(n, rhs.n) <= 0; }
  bool operator < (mpz& rhs) { return my_mpz_cmp(n, rhs.n) < 0; }
  mpz& operator *= (mpz& rhs) { my_mpz_mul(n, n, rhs.n); return *this; }
  mpz& operator *= (mp_limb_t rhs) { my_mpz_mul_ui(n, n, rhs); return *this; }
  mpz& operator <<= (int s) { my_mpz_mul_2exp(n, n, s); return *this; }
  mpz& operator >>= (int s) { my_mpz_tdiv_q_2exp(n, n, s); return *this; }

  mpz_t n;
};

} // namespace gmp

using namespace gmp;

const int MAXN = 5000010;

char s[MAXN], t[MAXN];

int main()
{
	mpz a;
	a.inp_str();
	a.get_str(s, 3);
	int n = strlen(s);
	
	t[0] = '1';
	for (int i = 1; i <= n; ++ i)
		t[i] = '0';
	
	int ans = 3*n;
	
	t[0] = '2';
	t[n] = 0;
	{
	mpz b(t);
	if (b < a)
	{
		printf("%d\n", 3*n);
		return 0;
	}
	}
	
	t[n-1] = 0;
	{
	mpz b(t);
	if (b < a)
	{
		printf("%d\n", 3*n-3+2);
		return 0;
	}
	}
	
	printf("%d\n", 3*n-3-3+2+2);
	
	return 0;
}