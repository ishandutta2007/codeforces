#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAXN (1 << 17)

int A[MAXN];
int B[MAXN];

struct tnode {
  tnode() : cnt(0), lft(nullptr), rht(nullptr) {
  }

  tnode(tnode* tr) {
    if (tr) {
      cnt = tr->cnt;
      lft = tr->lft;
      rht = tr->rht;
    } else {
      cnt = 0;
      lft = nullptr;
      rht = nullptr;
    }
  }

  int cnt;
  tnode* lft;
  tnode* rht;
};

tnode* tree_insert(tnode* tr, int A, int B, int x) {
  tnode* r = new tnode(tr);
  if (A + 1 == B) {
    ++r->cnt;
    return r;
  }

  int M = (A + B) / 2;
  if (x < M) {
    r->lft = tree_insert(r->lft, A, M, x);
  } else {
    r->rht = tree_insert(r->rht, M, B, x);
  }

  r->cnt = (r->lft ? r->lft->cnt : 0) +
           (r->rht ? r->rht->cnt : 0);
  return r;
}

int tree_query(tnode* tr, int A, int B, int a, int b) {
  if (!tr) {
    return 0;
  }
  if (a <= A && B <= b) {
    return tr->cnt;
  } else if (b <= A || B <= a) {
    return 0;
  }

  int M = (A + B) / 2;
  return tree_query(tr->lft, A, M, a, b) +
         tree_query(tr->rht, M, B, a, b);
}

int main() {
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    B[i] = N;
    cin >> A[i];
  }

  map<int, vector<int> > eqv;
  for (int i = 0; i < N; i++) {
    eqv[A[i]].push_back(i);
  }

  for (auto& i : eqv) {
    for (int j = 0; j + K < i.second.size(); j++) {
      B[i.second[j]] = i.second[j + K];
    }
  }

  vector<tnode*> roots(N + 1, nullptr);

  for (int i = N - 1; i >= 0; i--) {
    roots[i] = tree_insert(roots[i + 1], 0, MAXN, B[i]);
  }

  int last = 0;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    int l = (x + last) % N;
    int r = (y + last) % N;
    if (l > r) swap(l, r);
    r++;

    last = (r - l) - tree_query(roots[l], 0, MAXN, 0, r);
    cout << last << '\n';
  }
  return 0;
}