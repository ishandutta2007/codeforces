/*input
100
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
// const int N =;

class Solver {

  int closeSq(int n) {
    int sq = sqrt(n);
    if ((sq + 1) * (sq + 1) <= n)
      return (sq + 1);
    return sq;
  }

  vector<int> tryX(int n) {
    int peak = closeSq((n - 1) * 2);
    vector<int> a;
    map<int, int> used;
    rloop(i, n - 1, 0) {
      while (true) {
        if (peak < 0)
          return vector<int>();
        int ret = peak * peak - i;
        if (used[ret] || ret >= n) {
          peak--;
          continue;
        }
        used[ret] = true;
        a.push_back(ret);
        break;
      }
    }
    reverse(a.begin(), a.end());
    return a;
  }

public:
  void operator()() {
    int n;
    cin >> n;
    auto ans = tryX(n);
    for (auto it : ans)
      cout << it << sp;
    cout << endl;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    Solver solver;
    solver();
  }
}