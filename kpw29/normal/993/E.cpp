#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
typedef complex<long double> Complex;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int maxn = 200100;
typedef vector <ll> vi;
int tab[maxn];
ll wynik[maxn];
typedef complex<double> C;

struct fft_double {
  double PI = 3.141592653589793;
  using Complex = complex<double>;

  vector<Complex> dftn;
  vector<Complex> dfts;

  vector<Complex> pom;

  vector<Complex> a1;
  vector<Complex> a2;
  vector<Complex> b1;
  vector<Complex> b2;

  vector<double> cosi;
  vector<Complex> omega;

  fft_double() {}

  // @n to maksymalna suma rozmiarw mnoonych wielomianw.
  fft_double(int n, bool chce_dokladne) {
    n = potenga(n);
    dftn.resize(n + 1, 0);
    dfts.resize(n + 1, 0);
    pom.resize(n + 1, 0);
    if (chce_dokladne) {
      a1.resize(n + 1, 0);
      a2.resize(n + 1, 0);
      b1.resize(n + 1, 0);
      b2.resize(n + 1, 0);
    }
    cosi.resize(n + 1, 0);
    omega.resize(n + 1, 0);
  }

  inline int potenga(int v) {
    for (int i = 1; ; i *= 2) {
      if (i >= v) {
        return i;
      }
    }
    assert(false);
  }

  inline void dft(int n, int kier) {
    int n2 = n - 1;
    int s = 0;
    int p;
    int g;
    for (int i = 2; i <= n; i *= 2) {
      dftn.swap(dfts);
      p = n / i;
      if (kier) {
        g = 0;
        for (int j = 0; j < n; j++) {
          dftn[j] = dfts[(2 * (j - s) + s) & n2] +
                    omega[g] * dfts[(2 * (j - s) + p + s) & n2];
          s++;
          if (s == p) {
            g = j + 1;
            s = 0;
          }
        }
      } else {
        g = n;
        for (int j = 0; j < n; j++) {
          dftn[j] = dfts[(2 * (j - s) + s) & n2] +
                    omega[g] * dfts[(2 * (j - s) + p + s) & n2];
          s++;
          if (s == p) {
            g = n - j - 1;
            s = 0;
          }
        }
      }
    }
  }

  void licz_omegi(int n1) {
    double kat = 2.0 * PI / n1;
    int n2 = n1 - 1;
    int dod = 3 * n1 / 4;
    for (int i = 0; i <= n1; i++)
      cosi[i] = cos(kat * i);
    for (int i = 0; i <= n1; i++)
      omega[i] = Complex(cosi[i], cosi[(i + dod) & n2]);
  }

  vi fft(vi &jed, vi &dwa) {
    int n1 = potenga(jed.size() + dwa.size());
    licz_omegi(n1);
    for (int i = 0; i < (int) jed.size(); i++)
      dftn[i] = jed[i];
    for (int i = (int) jed.size(); i < n1; i++)
      dftn[i] = 0;
    dft(n1, 1);
    for (int i = 0; i < n1; i++)
      pom[i] = dftn[i];
    for (int i = 0; i < (int) dwa.size(); i++)
      dftn[i] = dwa[i];
    for (int i = (int) dwa.size(); i < n1; i++)
      dftn[i] = 0;
    dft(n1, 1);
    for (int i = 0; i < n1; i++)
      dftn[i] *= pom[i];
    dft(n1, 0);
    vi ret;
    for (int i = 0; i < n1; i++)
      ret.push_back(llround(dftn[i].real() / n1));
    return ret;
  }
};

fft_double janusz((1 << 19), false);
void solve(int x, int y)
{
	if (x == y) 
	{
		wynik[tab[x]]++;
		return;
	}
	
	int mid = (x + y) / 2;
	solve(x, mid);
	solve(mid+1, y);
	
	vi lewo; lewo.resize(mid - x + 1 + 1, 0);
	vi prawo; prawo.resize(y - mid + 1, 0);
	int tmp = 0;
	for (int i=mid; i>=x; --i)
	{
		tmp += tab[i];
		lewo[tmp]++;
	}
	
	tmp = 0;
	for (int i = mid + 1; i <= y; ++i)
	{
		tmp += tab[i];
		prawo[tmp]++;
	}

	vi help;
	if (prawo.size() > 15) help = janusz.fft(lewo, prawo);
	else
	{
		help.resize(lewo.size() + prawo.size(), 0);
		for (int i=0; i<(int)lewo.size(); ++i)
			for (int j=0; j<(int)prawo.size(); ++j)
				help[i + j] += lewo[i] * prawo[j];
	}
	for (int i=0; i<(int)help.size(); ++i) 
	{
		//cout << help[i] << ' '; 
		wynik[i] += help[i];
	}
}
int n, x;
int32_t main()
{
	boost; cin.tie(0); cout.tie(0);
	cin >> n >> x;
	FOR(i, 1, n)
	{
		cin >> tab[i];
		if (tab[i] < x) tab[i] = 1;
		else tab[i] = 0;
	}
	
	solve(1, n);
	FOR(i, 0, n) cout << wynik[i] << ' ';
}