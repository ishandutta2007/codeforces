#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
 
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    vector<int> vid[2];
};

const ll MAXNODES=8e5+400;
int _nodeidx=0;
struct TrieNode _memTrieNode[MAXNODES];

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	_nodeidx++;
	return &_memTrieNode[_nodeidx-1];
}
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key, int length, int type, int id)
{
    int level;
    int index;
 
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf

    pCrawl->vid[type].PB(id);
}

long long final=0;
vector<pll> vfinal;
char name[(int)8e5+2];
pair<vector<int>*,vector<int>* > dfs(struct TrieNode *v, int depth) {
	vector<pair<vector<int>*,vector<int>* >> res;
	{
		auto got=MP(&(v->vid[0]), &(v->vid[1]));
		res.PB(got);
	}
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		struct TrieNode *child = v->children[i];
		if (child!=NULL) {
			auto got=dfs(child,depth+1);
			res.PB(got);
		}
	}
	pair<vector<int>*,vector<int>* > target;
	target=res[0];
	for (ll i=0;i<res.size();i++) {
		auto got=res[i];
		if ((got.fst)->size() > (target.fst)->size()) target.fst=got.fst;
		if ((got.snd)->size() > (target.snd)->size()) target.snd=got.snd;
	}
	for (ll i=0;i<res.size();i++) {
		auto got=res[i];
		if (got.fst!=target.fst) {
			for (auto &w:*(got.fst)) (target.fst)->PB(w);
		}
		if (got.snd!=target.snd) {
			for (auto &w:*(got.snd)) (target.snd)->PB(w);
		}
	}
	ll match=min((target.fst)->size(),(target.snd)->size());
	auto fit=target.fst->rbegin(),sit=target.snd->rbegin();
	for (ll i=0;i<match;i++) {
		vfinal.PB(MP(*fit,*sit));
		++fit;++sit;
	}
	{
		ll newsz=target.fst->size()-match;
		target.fst->resize(newsz);
	}
	{
		ll newsz=target.snd->size()-match;
		target.snd->resize(newsz);
	}
	final+=((long long)depth)*match;
	return target;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d\n",&n);
	struct TrieNode *root = getNode();
	for (int type=0;type<2;type++)
	for (ll id=1;id<=n;id++) {
		scanf("%s\n",name);
		insert(root, name, strlen(name),type,id);
	}
	dfs(root,0);
	printf("%lld\n",final);
	for (auto &w:vfinal) {
		printf("%d %d\n",w.fst,w.snd);
	}
}