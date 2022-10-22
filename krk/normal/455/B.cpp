#include <cstdio>
#include <cstring>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef struct node *pnode;

const int Maxl = 26;
const int Maxn = 100005;

struct node {
	pnode ch[Maxl];
	bool canwin, canlose;
	node() { 
		for (int i = 0; i < Maxl; i++) ch[i] = NULL;
		canwin = canlose = false;
	}
};

int n, k;
char str[Maxn];
int slen;
pnode trie;

void Add(pnode tr, int ind)
{
	if (ind == slen) return;
	int let = str[ind] - 'a';
	if (tr->ch[let] == NULL)
		tr->ch[let] = new node();
	Add(tr->ch[let], ind + 1);
}

bool Leaf(pnode tr)
{
	for (int i = 0; i < Maxl; i++)
		if (tr->ch[i] != NULL) return false;
	return true;
}

void Solve(pnode tr)
{
	if (Leaf(tr)) { tr->canwin = false; tr->canlose = true; }
	else for (int i = 0; i < Maxl; i++) if (tr->ch[i] != NULL) {
			Solve(tr->ch[i]);
			tr->canwin |= !tr->ch[i]->canwin;
			tr->canlose |= !tr->ch[i]->canlose;
		}
}

void Erase(pnode trie)
{
	for (int i = 0; i < Maxl; i++)
		if (trie->ch[i] != NULL) {
			Erase(trie->ch[i]); delete trie->ch[i];
		}
}

void First() { printf("First\n"); }

void Second() { printf("Second\n"); }

int main()
{
	trie = new node();
	scanf("%d %d", &n, &k);
	while (n--) {
		scanf("%s", str); slen = strlen(str);
		Add(trie, 0);
	}
	Solve(trie);
	if (!trie->canwin) Second();
	else if (trie->canlose) First();
	else if (k % 2) First();
		 else Second();
	Erase(trie); delete trie;
	return 0;
}