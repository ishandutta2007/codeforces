#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1001;
const int kBufferSize = 1000001;

const char kStartCeil = 'X';
const char kOccupiedCeil = '*';

const int kUnreachableCeil = -1;

const int kDirectionsNum = 4;
const int kDx[kDirectionsNum] = {1, 0, 0, -1};
const int kDy[kDirectionsNum] = {0, -1, 1, 0};
const char kDletter[] = "DLRU";

const char kImpossibleVerdict[] = "IMPOSSIBLE";

struct Ceil {
  int x;
  int y;
};

int n;
int m;
int k;
char field[kMaxN][kMaxN];
int distance_from_start[kMaxN][kMaxN];
char output_buffer[kBufferSize];

Ceil FindStart() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == kStartCeil) {
        return {i, j};
      }
    }
  }
  exit(1);
}

void Bfs(const Ceil& start, int distance[][kMaxN]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      distance[i][j] = kUnreachableCeil;
    }
  }

  distance[start.x][start.y] = 0;
  queue<Ceil> _queue;
  _queue.push(start);
  while (!_queue.empty()) {
    Ceil ceil = move(_queue.front());
    _queue.pop();

    for (int i = 0; i < kDirectionsNum; ++i) {
      Ceil neighbour = {ceil.x + kDx[i], ceil.y + kDy[i]};

      if (min(neighbour.x, neighbour.y) < 0 ||
          neighbour.x >= n ||
          neighbour.y >= m ||
          field[neighbour.x][neighbour.y] == kOccupiedCeil ||
          distance[neighbour.x][neighbour.y] != kUnreachableCeil) {
        continue;
      }

      distance[neighbour.x][neighbour.y] = distance[ceil.x][ceil.y] + 1;
      _queue.push(move(neighbour));
    }
  }
}

void GreedyCycleSearch(Ceil ceil, int distance[][kMaxN], char output_buffer[]) {
  for (int i = 0; i < k; ++i) {
    bool move_is_made = false;
    for (int j = 0; j < kDirectionsNum; ++j) {
      Ceil neighbour = {ceil.x + kDx[j], ceil.y + kDy[j]};

      if (min(neighbour.x, neighbour.y) < 0 ||
          neighbour.x >= n ||
          neighbour.y >= m ||
          field[neighbour.x][neighbour.y] == kOccupiedCeil ||
          i + 1 + distance[neighbour.x][neighbour.y] > k) {
        continue;
      }

      output_buffer[i] = kDletter[j];
      ceil = move(neighbour);
      move_is_made = true;
      break;
    }

    if (!move_is_made) {
      if (i == 0) {
        printf("%s\n", kImpossibleVerdict);
        exit(0);
      }

      cerr << "Failed to make move #" << i + 1 << "\n";
      exit(1);
    }
  }
}

void Solve() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", field[i]);
  }

  if (k % 2) {
    printf("%s\n", kImpossibleVerdict);
    return;
  }

  Ceil start = FindStart();
  Bfs(start, distance_from_start);
  GreedyCycleSearch(start, distance_from_start, output_buffer);

  printf("%s\n", output_buffer);
}

int main() {
  Solve();

  return 0;
}