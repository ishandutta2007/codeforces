#include <cstdio>
#include <vector>
#include <utility>

static constexpr int kMaxN = 3001;

int n;
int k;
char config[kMaxN];

int n_batches;
int total_swaps;
std::vector<int> batches[kMaxN];


void InputData() {
  scanf("%d%d", &n, &k);
  scanf("%s", config);
}

void DecomposeSort() {
  n_batches = 0;
  total_swaps = 0;
  while (true) {
    for (int i = 0; i + 1 < n; ++i) {
      if (config[i] == 'R' && config[i + 1] == 'L') {
        batches[n_batches].push_back(i);
      }
    }

    if (batches[n_batches].empty()) {
      break;
    }

    for (int i : batches[n_batches]) {
      using std::swap;
      swap(config[i], config[i + 1]);
    }

    total_swaps += batches[n_batches].size();
    ++n_batches;
  }
}

void OutputData() {
  if (k < n_batches || k > total_swaps) {
    printf("-1\n");
    return;
  }

  int total_additional_batches = k - n_batches;

  int swaps_made = 0;
  for (int i = 0; i < n_batches; ++i) {
    int n_available_batches = batches[i].size() - 1;
    int n_additional_batches =
        std::min(total_additional_batches, n_available_batches);

    for (int j = 0; j < n_additional_batches; ++j) {
      printf("1 %d\n", batches[i][j] + 1);
    }
    total_additional_batches -= n_additional_batches;

    int n_swaps_left = batches[i].size() - n_additional_batches;
    if (!n_swaps_left) {
      continue;
    }

    printf("%d", n_swaps_left);
    for (int j = n_additional_batches; j < batches[i].size(); ++j) {
      printf(" %d", batches[i][j] + 1);
    }
    printf("\n");
  }
}

void Solve() {
  InputData();
  DecomposeSort();
  OutputData();
}

int main() {
  Solve();

  return 0;
}