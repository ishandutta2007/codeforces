#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

#undef M_PI
const double M_PI = 3.1415926535897932384626433;


const int MaxN = (1<<18);

using LD = double;

struct CD {
  LD a, b;
  
  CD() : a(0), b(0) {};
  CD(LD a_, LD b_) : a(a_), b(b_) {}
  CD operator+(const CD& other) const { return CD(a+other.a, b+other.b); }
  CD operator-(const CD& other) const { return CD(a-other.a, b-other.b); }
  CD& operator*=(const CD& other) {
    LD x = a;
    a = x*other.a - b*other.b;
    b = x*other.b + b*other.a;
    return *this;
  }
  CD operator*(const CD& other) const {
    return CD(a, b) *= other;
  }
};

//using CD = complex<LD>;

CD poly1[MaxN], poly2[MaxN], val[MaxN], result[MaxN];

inline unsigned rev_bits(unsigned val, int num_bits) {
  unsigned mask = 0x0000FFFF;  // 00000000000000001111111111111111
  val = ((val&mask)<<16) | ((val>>16) & mask);
  mask = 0x00FF00FF;           // 00000000111111110000000011111111
  val = ((val&mask)<<8) | ((val>>8) & mask);
  mask = 0x0F0F0F0F;           // 00001111000011110000111100001111
  val = ((val&mask)<<4) | ((val>>4) & mask);
  mask = 0x33333333;           // 00110011001100110011001100110011
  val = ((val&mask)<<2) | ((val>>2) & mask);
  mask = 0x55555555;           // 01010101010101010101010101010101
  val = ((val&mask)<<1) | ((val>>1) & mask);
  return (val >> (32-num_bits));
}

void fft(const CD* from, CD* to, int depth, bool inv) {
  int N = (1<<depth);

  for (int i = 0; i < N; i++) to[rev_bits(i, depth)] = from[i];
  for (int l = 1; l <= depth; l++) {
    int step = (1<<l);
    LD ang = (inv?1:-1) * 2*M_PI / step;
    CD root{cos(ang), sin(ang)};

    for (int pos = 0; pos < N; pos += step) {
      CD omega{1, 0};

      for (int k = 0; k < step/2; k++) {
        CD a = to[pos+k],
           b = omega*to[pos+k+step/2];
        to[pos+k] = a+b;
        to[pos+k+step/2] = a-b;
        omega *= root;
      }
    }
  }

  if (inv) {
    for (int i = 0; i < N; i++) to[i] *= CD{1./N, 0};
  }
}

int N, M, k;
char str[MaxN], pattern[MaxN];

void input() {
  scanf("%d%d%d%s%s", &N, &M, &k, str, pattern);
}


const map<char,int> mapper = {{'A',0}, {'C',1}, {'G',2}, {'T',3}};


CD values[MaxN];

int main() {
  input();

  //fill(isGood, isGood+N-M+1, true);

  int sz = 1, dpth = 0;
  /* N instead of N + M should not work, but somehow does (too weak tests?) */
  while (sz <= N) { sz *= 2; dpth++; }

  for (char c: vector<char>{'A', 'C', 'G', 'T'}) {
    int totalOccur = 0;
    for (int i = 0; i < M; i++) {
      if (pattern[i] == c) totalOccur++;
    }

    int numOccur = 0;
    for (int i = -k; i < N; i++) {
      if (i+k < N && str[i+k] == c) numOccur++;
      if (i >= 0) poly1[i] = (numOccur > 0) ? CD{1,0} : CD{0,0};

      if (i >= k && str[i-k] == c) numOccur--;
    }

    for (int i = 0; i < M; i++) {
      poly2[M-i-1] = (pattern[i] == c) ? CD{1,0} : CD{0,0};
    }


    /* mozna, bo to real-valued polys */
    for (int i = 0; i < sz; i++) {
      //cerr << i << " " << poly1[i] << " " << poly2[i];
      poly1[i] = poly1[i] * CD{0.5, -0.5} + poly2[i] * CD{0.5, 0.5};
      //cerr << " " << poly1[i] << endl;
    }

    fft(poly1, val, dpth, false);

    for (int i = 0; i < sz; i++) {
      values[i] = values[i] + val[i] * val[i];
    }

    /*fft(values, result, dpth, true);
    for (int i = 0; i < N + M; i++) {
      cerr << "    " << result[i] << endl;
    }
    cerr << endl;*/
  }

  fft(values, result, dpth, true);

  int res = 0;
  for (int i = 0; i < N; i++) {
    if (result[i].a + 0.5 > M) {
      res++;
    }
  }

  printf("%d\n", res);
}