#include <bits/stdc++.h>
#include <assert.h>
#define PB push_back
#define MP make_pair
#define UNDEF -1LL
using namespace std;
typedef long long ll;

typedef struct Node {
  int begin;
  int end;
  int depth; // distance in characters from root to this node
  ll cost;
  Node *parent;
  map<int,Node*> children;
  Node *suffixLink; 
} Node;

Node *init(int begin, int end, int depth, Node *parent) {
  Node *x = new Node;
  x->begin = begin;
  x->end = end;
  x->parent = parent;
  x->depth = depth;
  x->suffixLink = NULL;
  x->cost=0;
  return x;
}

Node *buildSuffixTree(int *a, int n) {
  Node *root = init(0,0,0,NULL);
  Node *node = root;
  for (int i = 0, tail = 0; i < n; i++,tail++) {
    Node *last = NULL;
    while (tail >= 0) {
      Node *ch = node->children[a[i-tail]];
      while (ch != NULL && tail >= ch->end - ch->begin) {
        tail -= ch->end - ch->begin;
        node = ch;
        ch = ch->children[a[i-tail]];
      }
      if (ch == NULL) {
        node->children[a[i]] = init(i,n,node->depth + node->end - node->begin, node);
        if (last != NULL) last->suffixLink = node;
        last = NULL;
      }
      else {
        int t = a[ch->begin + tail];
        if (t == a[i]) {
          if (last != NULL) last->suffixLink = node;
          break;
        }
        else {
          Node *splitNode = init(ch->begin, ch->begin + tail, node->depth + node->end - node->begin, node);
          splitNode->children[a[i]] = init(i, n, ch->depth + tail, splitNode);
          splitNode->children[t] = ch;
          ch->begin += tail;
          ch->depth += tail;
          ch->parent = splitNode;
          node->children[a[i - tail]] = splitNode;
          if (last != NULL) last->suffixLink = splitNode;
          last = splitNode;
        }
      }
      if (node == root) {
        --tail;
      }
      else {
        node = node->suffixLink;
      }
    }
  }
  return root;
}

/*void dfs(Node *x,string s) {
  vector<Node*> v;
  for (ll i = 0; i < ALPHABETLEN; i++) {
    Node *y = x->children[i];
    if (y != NULL) {
      v.PB(y);
      dfs(y,s);
    }
  }
  for (int i = x->begin; i < x->end; i++) {
    printf("%c", s[i]);
  }
  printf(" has depth %d begin %d end %d cost %lld. has children: ",x->depth,x->begin,x->end,x->cost);
  for (auto& y: v) {
    for (int i = y->begin; i < y->end; i++) {
      printf("%c", s[i]);
    }
    printf(" ");
  }
  printf("\n");
}*/
const ll mm=5e5+4;
const ll ms=1e5+4;
map<ll,ll> h;
int *s;
void dfs1(Node *x) {
	auto it=h.lower_bound(x->begin);
	ll idx=it->first;
  /*for (int i = x->begin; i < x->end; i++) {
  	if (s[i]<26) printf("%c",s[i]+'a');
    else printf("%d,", s[i]);
  }
  printf(" has depth %d begin %d end %d cost %lld idx %lld and has children ",x->depth,x->begin,x->end,x->cost,idx);
  for (auto &got:x->children) {
    Node *y = got.second;
    if (y==NULL) continue;
    for (int i = y->begin; i < y->end; i++) {
  		if (s[i]<26) printf("%c",s[i]+'a');
    	else printf("%d,", s[i]);
    }
    printf(" ");
  }
  printf("\n");*/
	if (x->begin<=idx&&idx<x->end) {
		//printf("is being reduced with %lld to cost %lld\n",idx,it->second);
		x->end=idx;
		x->cost+=it->second;
		x->children.clear();
	}
	else {
  	for (auto &got:x->children) {
  		auto y=got.second;
  	  if (y != NULL) {
  	    dfs1(y);
  	  }
  	}
  }
}
ll final=0;
ll dfs2(Node *x) {
  for (auto &got:x->children) {
  	auto y=got.second;
    if (y != NULL) {
      x->cost+=dfs2(y);
    }
  }
  ll len=x->depth+(x->end)-(x->begin);
  assert(len>=0);
  if (x->begin!=x->end) final=max(final,((ll)x->cost) * len);
  /*for (int i = x->begin; i < x->end; i++) {
  	if (s[i]<26) printf("%c",s[i]+'a');
    else printf("%d,", s[i]);
  }
  printf(" has depth %d begin %d end %d cost %lld len:%lld cand:%lld and has children ",x->depth,x->begin,x->end,x->cost,len,x->cost * len);
  for (auto &got:x->children) {
    Node *y = got.second;
    if (y==NULL) continue;
    for (int i = y->begin; i < y->end; i++) {
  		if (s[i]<26) printf("%c",s[i]+'a');
    	else printf("%d,", s[i]);
    }
    printf(" ");
  }
  printf("\n");*/
  return x->cost;
}
string t[ms];
ll c[ms];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; cin>>n;
  for (ll i=0;i<n;i++) cin>>t[i];
  for (ll i=0;i<n;i++) cin>>c[i];
  ll slen=0;
  for (ll i=0;i<n;i++) {
  	slen+=t[i].length()+1;
  }
  //string s;
	s=new int[slen];
	ll x=0;
	for (ll i=0;i<n;i++) {
		for (ll y=0;y<t[i].length();y++) {
			s[x]=t[i][y]-'a';
			++x;
		}
		s[x]=26+i;
		h[x]=c[i];
		++x;
	}
	Node *root = buildSuffixTree(s,slen);
	//cout<<s<<endl;
	//dfs(root,s);
	dfs1(root);
	//dfs(root,s);
	dfs2(root);
	//dfs(root,s);
	printf("%lld\n",final);
}