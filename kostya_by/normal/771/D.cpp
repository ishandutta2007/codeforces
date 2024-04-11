#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 80;
const int kCharClasses = 3;

int n;
string s;
int classes[kMaxN];
int f[kMaxN][kMaxN][kMaxN][kCharClasses];

int total_classes_cnt[kCharClasses];

int classes_cnt[kCharClasses];
int next_id[kCharClasses];

void Solve() {
  memset(f, -1, sizeof(f));

  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; ++i) {
    char c = s[i - 1];
    int& class_id = classes[i];

    if (c == 'K') {
      class_id = 0;
    } else if (c == 'V') {
      class_id = 1;
    } else {
      class_id = 2;
    }

    ++total_classes_cnt[class_id];
  }

  f[0][0][0][2] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int a = 0; a <= i; ++a) {
      if (a > total_classes_cnt[0]) {
        continue;
      }

      for (int b = 0; a + b <= i; ++b) {
        if (b > total_classes_cnt[1]) {
          continue;
        }

        int c = i - a - b;
        if (c > total_classes_cnt[2]) {
          continue;
        }

        classes_cnt[0] = a;
        classes_cnt[1] = b;
        classes_cnt[2] = c;
        memset(next_id, -1, sizeof(next_id));

        // cerr << a << " " << b << " " << c << "\n";
        // cerr << "... ";

        int h = 0;
        for (int j = 1; j <= n; ++j) {
          int class_id = classes[j];
          --classes_cnt[class_id];

          if (classes_cnt[class_id] < 0) {
            if (next_id[class_id] == -1) {
              next_id[class_id] = h;
            }
            ++h;
          }

          // cerr << h << " ";
        }
        // cerr << "\n";

        for (int ch = 0; ch < kCharClasses; ++ch) {
          if (f[i][a][b][ch] == -1) {
            continue;
          }

          // cerr << i << " " << a << " " << b << " " << ch << " " << f[i][a][b][ch] << "\n";

          for (int next_ch = (ch == 1); next_ch < kCharClasses; ++next_ch) {
            if (next_id[next_ch] == -1) {
              continue;
            }

            // cerr << " -> " << next_ch << " : " << next_id[next_ch] << "\n";

            int value = f[i][a][b][ch] + next_id[next_ch];

            int next_a = a;
            int next_b = b;
            if (next_ch == 0) {
              ++next_a;
            } else if (next_ch == 1) {
              ++next_b;
            }

            int& dst = f[i + 1][next_a][next_b][next_ch];
            if (dst == -1) {
              dst = value;
            }
            dst = min(dst, value);
          }
        }
      }
    }
  }

  int answer = -1;
  for (int ch = 0; ch < kCharClasses; ++ch) {
    int value = f[n][total_classes_cnt[0]][total_classes_cnt[1]][ch];

    if (value == -1) {
      continue;
    }

    if (answer == -1) {
      answer = value;
    }
    answer = min(answer, value);
  }

  cout << answer << "\n";
}

int main() {
  Solve();
  return 0;
}