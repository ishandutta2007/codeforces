#include <bits/stdc++.h>

using namespace std;

const int kMaxK = 14;
const int kMaxA = 1 << kMaxK;

int n;
int k;
int input_histogram[kMaxA];
int precalculated_popcount[kMaxA];

int precalculated_xors_num;
int precalculated_xors[kMaxA];

void PrecalculatePopcount() {
  for (int a = 0; a < kMaxA; ++a) {
    precalculated_popcount[a] = precalculated_popcount[a >> 1] + (a & 1);
    if (precalculated_popcount[a] == k) {
      precalculated_xors[precalculated_xors_num++] = a;
    }
  }
}

long long CountInterestingPairs() {
  long long total_interesting_pairs = 0ll;
  if (k == 0) {
    for (int a = 0; a < kMaxA; ++a) {
      int temp = input_histogram[a];
      total_interesting_pairs += temp * 1ll * (temp - 1) / 2;
    }
  } else {
    auto begin = precalculated_xors;
    auto end = precalculated_xors + precalculated_xors_num;

    for (int a = 0; a < kMaxA; ++a) {
      int second_values_count = 0;
      for (auto xor_value = begin; xor_value < end; ++xor_value) {
        second_values_count += input_histogram[a ^ (*xor_value)];
      }

      total_interesting_pairs += input_histogram[a] * 1ll * second_values_count;
    }

    total_interesting_pairs /= 2;
  }

  return total_interesting_pairs;
}

void Solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);

    ++input_histogram[a];
  }

  PrecalculatePopcount();
  long long answer = CountInterestingPairs();
  cout << answer << "\n";
}

int main() {
  Solve();

  return 0;
}