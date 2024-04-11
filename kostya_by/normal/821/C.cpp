#include <bits/stdc++.h>

using namespace std;

const int kBufferSize = 10;

int n;

int removed_num;
set<int> sorted_part;
vector<int> unsorted_part;

string buffer_s;
char buffer[kBufferSize];

int StackTop() {
  if (!unsorted_part.empty()) {
    return unsorted_part.back();
  }

  return *sorted_part.begin();
}

void StackSort() {
  for (int x : unsorted_part) {
    sorted_part.insert(x);
  }
  unsorted_part.clear();
}

void StackPop() {
  if (!unsorted_part.empty()) {
    unsorted_part.pop_back();
    return;
  }

  sorted_part.erase(sorted_part.begin());
}

void Solve() {
  scanf("%d", &n);
  removed_num = 0;

  int answer = 0;
  for (int i = 0; i < 2 * n; ++i) {
    scanf("%s", buffer);

    switch (buffer[0]) {
      case 'a': {
        int x; scanf("%d", &x);
        unsorted_part.push_back(x);
        break;
      }

      case 'r': {
        ++removed_num;
        if (StackTop() != removed_num) {
          StackSort();
          ++answer;
        }
        StackPop();

        break;
      }
    }
  }

  printf("%d\n", answer);
}

int main() {
  Solve();

  return 0;
}