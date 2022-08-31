#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1000000000

void matmul(int R[2][2], int A[2][2], int B[2][2]) {
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      R[i][j] = 0;
      for(int k = 0; k < 2; k++) {
        R[i][j] = (R[i][j] + (long long)A[i][k] * B[k][j]) % MOD;
      }
    }
  }
}

void shift(int* ff, int nm) {
  int A[2][2] = { {1, 0},
                  {0, 1} };
  int B[2][2] = { {0, 1},
                  {1, 1} };
  if(nm < 0) {
    B[0][0] = MOD - 1; B[0][1] = 1;
    B[1][0] =  1; B[1][1] = 0;
    nm = -nm;
  }

  int C[2][2];
  for(int i = 31 - __builtin_clz(nm); i >= 0; i--) {
    matmul(C, A, A);
    memcpy(A, C, sizeof(C));
    if(nm & 1 << i) {
      matmul(C, B, A);
      memcpy(A, C, sizeof(C));
    }
  }

  int nf[2];
  nf[0] = ((long long)ff[0] * A[0][0] + (long long)ff[1] * A[0][1]) % MOD;
  nf[1] = ((long long)ff[0] * A[1][0] + (long long)ff[1] * A[1][1]) % MOD;
  memcpy(ff, nf, sizeof(nf));
}

template<class T> struct splnode {
  typedef splnode<T> node_t;

  splnode() : P(NULL) {
    C[0] = C[1] = NULL;
    pull();
  }

  /* Add extra state here. */
  T f;
  T fadd;
  T fs[2];
  int ind;

  node_t* P;
  node_t* C[2];

  /* Pull state changes up the tree (e.g. pull subtree sums).  Also here is
   * where we fix parent pointers. */
  void pull() {
    if(C[0]) C[0]->P = this;
    if(C[1]) C[1]->P = this;

    fs[0] = 0;
    fs[1] = f;
    for(int i = 0; i < 2; i++) {
      if(C[i]) {
        int ff[2];
        memcpy(ff, C[i]->fs, sizeof(ff));
        shift(ff, C[i]->ind - ind);
        fs[0] = (fs[0] + ff[0]) % MOD;
        fs[1] = (fs[1] + ff[1]) % MOD;
      }
    }
  }

  /* Push state changes down the tree (e.g. push range updates). */
  void push() {
    for(int i = 0; i < 2; i++) {
      if(C[i]) {
        C[i]->f = (C[i]->f + fadd) % MOD;
        C[i]->fadd = (C[i]->fadd + fadd) % MOD;
      }
      fadd = 0;
    }
  }

  /* Return the direction of this relative its parent. */
  int up() {
    return !P ? -1 : (P->C[0] == this ? 0 : 1);
  }

  /* Simple zig step in the 'c' direction. */
  void zig(int c) {
    node_t* X = C[c];
    if(X->P = P) P->C[up()] = X;
    C[c] = X->C[1 - c];
    X->C[1 - c] = this;
    pull(); X->pull();
    if(P) P->pull();
  }

  /* Splay this up to the root. */
  node_t* splay(splnode<T>* rt = NULL) {
    for(push(); P != rt; ) {
      if(P->P != rt) P->P->push();
      P->push();
      push();

      int c1 = up();
      if(P->P == rt) {
        P->zig(c1);
      } else {
        int c2 = P->up();
        if(c1 == c2) {
          P->P->zig(c2);
          P->zig(c1);
        } else {
          P->zig(c1);
          P->zig(c2);
        }
      }
    }
    return this;
  }

  /* Return the max element of the subtree rooted at this. */
  node_t* last(splnode<T>* rt = NULL) {
    for(node_t* r = this; ; r = r->C[1]) if(!r->C[1]) return r->splay(rt);
  }

  /* Return the min element of the subtree rooted at this. */
  node_t* first(splnode<T>* rt = NULL) {
    for(node_t* r = this; ; r = r->C[0]) if(!r->C[0]) return r->splay(rt);
  }
};

template<class T>
splnode<T>* spl_subtree(splnode<T>* lft, splnode<T>* rht) {
  lft->splay();
  rht->splay(lft);
  return rht->C[0];
}

int get_suffix(splnode<int>* nd, int shft) {
  int ff[2];

  memcpy(ff, nd->splay()->fs, sizeof(ff));
  if(shft) {
    shift(ff, shft);
  }

  if(nd->C[0]) {
    int nf[2];
    memcpy(nf, nd->C[0]->fs, sizeof(nf));
    shift(nf, shft + nd->C[0]->ind - nd->ind);
    for(int i = 0; i < 2; i++) {
      ff[i] = (ff[i] + MOD - nf[i]) % MOD;
    }
  }
  return ff[1];
}

splnode<int> nodes[200010];

int main() {
  memset(nodes, 0, sizeof(nodes));
  nodes[0].C[1] = &nodes[1];

  int N, M; cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    nodes[i].ind = i;
    nodes[i].C[1] = &nodes[i + 1];
    cin >> nodes[i].f;
  }
  nodes[N + 1].ind = N + 1;

  for(int i = N + 1; i >= 0; i--) {
    nodes[i].pull();
  }

/*
  for(int i = 1; i <= N + 1; i++) {
    nodes[i].splay();
    cout << i << ": " << nodes[i].fs[0] << " : " << nodes[i].fs[1] << " : "
         << get_suffix(&nodes[i], 0) << endl;
  }
  for(int i = 1; i <= N + 1; i++) {
    nodes[i].splay();
    cout << i << ": " << nodes[i].fs[0] << " : " << nodes[i].fs[1] << " : "
         << get_suffix(&nodes[i], 0) << endl;
  }
*/

  for(int i = 0; i < M; i++) {
    int c; cin >> c;
    if(c == 1) {
      int j, v;
      cin >> j >> v;
      nodes[j].splay();
      nodes[j].f = v;
      nodes[j].pull();
    } else if(c == 2) {
      int lf, rh;
      cin >> lf >> rh;

      cout << (MOD + get_suffix(&nodes[lf], 0) -
              get_suffix(&nodes[rh + 1], rh - lf + 1)) % MOD << endl;
    } else if(c == 3) {
      int lf, rh, d;
      cin >> lf >> rh >> d;
      splnode<int>* nd = spl_subtree(&nodes[lf - 1], &nodes[rh + 1]);
      nd->fadd = (nd->fadd + d) % MOD;
      nd->P->pull();
      nd->P->P->pull();
    }
  }
  return 0;
}