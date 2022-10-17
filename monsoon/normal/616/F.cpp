#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

template<class T, int A>
struct suffix_tree {
  struct node {
    int begin;
    int end;
    node* parent;
    node* link;
    node* adj[A];

    ll cost;

    node(int begin, int end, node* parent)
      : begin(begin), end(end), parent(parent), link(0), cost(0) {
      REP(i,A) adj[i] = 0;
    }
  };

  node* bot;
  node* root;
  vector<T> word;
  vector<int> begin;
  vector<node*> tops;
  static const int alph = A;

  suffix_tree() {
    bot = new node(-1, -1, 0);
    root = new node(-1, 0, bot);
    REP(i,A) bot->adj[i] = root;
    root->link = bot;
    begin.push_back(0);
  }

  void insert_word(const T* w, int len) {
    word.insert(word.end(), w, w+len);

    node* no = root;
    node* noc;
    int h = 0;
    node* oldR = 0;
    node* lastleaf = 0;
    node* firstleaf = 0;

    REP(i,len+1) {
      while (true) {
        bool finish = false;
        node* nor = no;
        if (h == 0) {
          finish = no == bot || i < len && no->adj[w[i]];
        } else if (i < len && w[i] == word[noc->begin + h]) {
          finish = true;
        } else {
          nor = new node(noc->begin, noc->begin + h, no);
          no->adj[word[noc->begin]] = nor;
          nor->adj[word[noc->begin + h]] = noc;
          noc->parent = nor;
          noc->begin += h;
        }

        if (i == len && !firstleaf) firstleaf = nor;
        if (finish) break;

        if (i < len) {
          node* R = new node(begin.back() + i, begin.back() + len, nor);
          nor->adj[w[i]] = R;
          if (!firstleaf) firstleaf = R;
          if (lastleaf) lastleaf->link = R;
          lastleaf = R;
        } else if (lastleaf) {
          lastleaf->link = nor;
          lastleaf = 0;
        }

        if (oldR) oldR->link = nor;
        oldR = nor;

        no = no->link;
        while (h && (noc = no->adj[word[nor->end - h]], h >= noc->end - noc->begin)) {
          h -= noc->end - noc->begin;
          no = noc;
        }
      }

      if (oldR) oldR->link = no;
      oldR = 0;

      if (i == len) break;

      if (h == 0) noc = no->adj[w[i]];
      if (++h == noc->end - noc->begin) {
        h = 0; no = noc;
      }
    }

    begin.push_back(begin.back() + len);
    tops.push_back(firstleaf);
  }
};

typedef suffix_tree<char,26> tree_t;

const int N = 510000;
int n,cost[N];
char s[N];
ll ans;
tree_t tree;

void rek(tree_t::node* no, int len) {
  len += no->end - no->begin;
  REP(i,tree_t::alph) if (no->adj[i]) {
    rek(no->adj[i], len);
    no->cost += no->adj[i]->cost;
  }
  ans = max(ans, ll(no->cost) * len);
}

int main() {
  scanf("%d",&n);
  REP(i,n) {
    scanf("%s",s);
    int m = strlen(s);
    REP(j,m) { s[j] -= 'a'; }
    tree.insert_word(s, m);
  }
  REP(i,n) scanf("%d",&cost[i]);

  REP(i,n) {
    tree_t::node* no = tree.tops[i];
    while (no != tree.root) {
      no->cost += cost[i];
      no = no->link;
    }
  }

  rek(tree.root, -1);

  printf("%lld\n", ans);
}