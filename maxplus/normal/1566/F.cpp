#include <algorithm>
#include <cstring>
#include <cstdio>
#include <array>

struct UnsafeInput {/*\n*/  UnsafeInput() {/*\n*/    fread(buf + 1, 1, sizeof buf - 1, stdin);/*\n*/  }/*\n*//*\n*/  template <typename T>/*\n*/  void operator()(T* b, size_t n) {/*\n*/    memset(b, 0, sizeof *b * n);/*\n*/    (*this)(b, b + n);/*\n*/  }/*\n*//*\n*/  template <typename ...Ts>/*\n*/  void operator()(Ts&... xs) {/*\n*/    ((*this)(&(xs = {}), &xs + 1), ...);/*\n*/  }/*\n*//*\n*/private:/*\n*/  char buf[1 << 23], *bufptr = buf;/*\n*//*\n*/  template <typename T>/*\n*/  void operator()(T* b, T* e) {/*\n*/    bool sgn = 0;/*\n*/    while (b != e) {/*\n*/      if (*++bufptr == '-') {/*\n*/        sgn = 1;/*\n*/      } else if (*bufptr < '0') {/*\n*/        *b++ *= sgn? -1: 1, sgn = 0;/*\n*/      } else {/*\n*/        *b = *b * 10 + *bufptr - '0';/*\n*/      }/*\n*/    }/*\n*/  }
} reader;

using namespace std;

constexpr uint32_t N = 2e5, C = 1e9 + 1, INF = C * 3;
int points[N];
array<int, 2> segments[N];

int main() {
  int t, n, m;
  reader(t);
  while (t--) {
    reader(n, m);
    reader(&*points, n);
    reader(&*segments->data(), m * 2);
    sort(points, points + n);
    sort(segments, segments + m);
    int i = n - 1, j = m - 1;
    array<uint32_t, 2> pans{}, cans{INF, INF};
    int minr = C;
    while (1) {
      if ((i != -1 || j == -1) && (i != n - 1 || j == m - 1)) {
        uint32_t ld = j != -1? max(segments[j][0] - points[i], 0): 0, rd = i != n - 1? max(points[i + 1] - minr, 0): 0;
        cans[0] = min({cans[0], pans[0] + rd + 2 * ld, pans[1] + 2 * rd + 2 * ld});
        cans[1] = min({cans[1], pans[0] + rd +     ld, pans[1] + 2 * rd +     ld});
      }
      if (j == -1) {
        break;
      } else if (i == -1 || points[i] < segments[j][0]) {
        minr = min(minr, segments[j--][1]);
      } else {
        pans = cans;
        cans.fill(INF);
        --i;
      }
    }
    printf("%u\n", cans[1]);
  }
  return 0;
}