#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define all(v) (v).begin(), (v).end()
typedef long long lld;

int N, M;
int D[MAXN], E[MAXN];
char S[MAXN];

struct NODE{
	NODE(): cnt(0), f(0){ memset(nxt, 0, sizeof(nxt)); }
	int cnt;
	NODE *nxt[26], *f;
} *root1, *root2;

void add(NODE *root, const string &s)
{
	NODE *now = root;
	for (char c: s){
		if (!now->nxt[c-'a']) now->nxt[c-'a'] = new NODE();
		now = now->nxt[c-'a'];
	}
	now->cnt++;
}

void build_aho_corasick(NODE *root)
{
	queue <NODE*> que;
	root->f = root;
	for (int i=0;i<26;i++) if (root->nxt[i]){
		root->nxt[i]->f = root;
		que.push(root->nxt[i]);
	}
	while (!que.empty()){
		NODE *q = que.front(); que.pop();
		q->cnt += q->f->cnt;
		for (int i=0;i<26;i++) if (q->nxt[i]){
			NODE *f = q->f;
			while (f != root && !f->nxt[i]) f = f->f;
			if (f->nxt[i]) f = f->nxt[i];
			q->nxt[i]->f = f;
			que.push(q->nxt[i]);
		}
	}
}

int main()
{
	cin >> S+1 >> M; N = strlen(S+1);
	root1 = new NODE();
	root2 = new NODE();
	for (int i=1;i<=M;i++){
		string s; cin >> s;
		add(root1, s);
		reverse(all(s));
		add(root2, s);
	}
	build_aho_corasick(root1);
	build_aho_corasick(root2);
	NODE *now = root1;
	for (int i=1;i<=N;i++){
		int c = S[i]-'a';
		while (now != root1 && !now->nxt[c]) now = now->f;
		if (now->nxt[c]) now = now->nxt[c];
		D[i] = now->cnt;
	}
	now = root2;
	for (int i=N;i;i--){
		int c = S[i]-'a';
		while (now != root2 && !now->nxt[c]) now = now->f;
		if (now->nxt[c]) now = now->nxt[c];
		E[i] = now->cnt;
	}
	lld ans = 0;
	for (int i=1;i<N;i++) ans += (lld)D[i]*E[i+1];
	cout << ans << endl;
}