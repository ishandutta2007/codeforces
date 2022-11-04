#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 300005, SIG = 26, LMX = 19;

struct aho_corasick {
	struct Node {
		Node *sig[SIG], *fail;
		int finish, cnt;

		Node () : fail(this), finish(0), cnt(0) {
			for (int i = 0; i < SIG; i++)
				sig[i] = this;
		}

		Node (Node *root) : fail(root), finish(0), cnt(0) { 
			for (int i = 0; i < SIG; i++)
				sig[i] = root;
		}
	};

	Node *root;

	aho_corasick() { reset(); }

	void reset () {
		root = new Node;
	}

	void insert (string &s, int ind) {
		Node *u = root;

		for (char c : s) {
			c -= 'a';

			if (u->sig[c] == root) {
				u->sig[c] = new Node(root);
				u->sig[c]->finish = -1;
			}

			u = u->sig[c];
		}

		u->finish = ind;
		u->cnt++;
	}

	Node* getFail (Node *u, int c) {
		while (u != root && u->sig[c] == root)
			u = u->fail;
		return u->sig[c];
	}

	void build () {
		queue<Node*> q;
		
		for (int i = 0; i < SIG; i++)
			if (root->sig[i] != root)
				q.push(root->sig[i]);

		while (q.size()) {
			Node *u = q.front();
			q.pop();

			for (int i = 0; i < SIG; i++) {
				Node *v = u->sig[i];

				if (v != root) {
					v->fail = getFail(u->fail, i);
					v->cnt += v->fail->cnt;
					q.push(v);
				}
			}
		}
	}

	int match (string &t) {
		Node *u = root;
		int res = 0;

		for (int i = 0; i < t.size(); i++) {
			char c = t[i] - 'a';
			
			if (u->sig[c] != root)
				u = u->sig[c];
			else
				u = getFail(u->fail, c);
			res += u->cnt;
		}

		return res;
	}
};

typedef vector<string*> vs;

struct dynamic_aho_corasick {
	aho_corasick ac[LMX];
	vs s[LMX];
	int exi;

	dynamic_aho_corasick () : exi(0) {}

	int insert (string &str) {
		int j = 0;
		while (exi & (1 << j)) j++;
		s[j].push_back(new string(str));

		for (int i = 0; i < j; i++) {
			for (string *t : s[i]) s[j].push_back(t);
			s[i].clear();
			ac[i].reset();
		}

		for (string *t : s[j])
			ac[j].insert(*t, 1);
		ac[j].build();

		exi++;
	}

	int match (string &t) {
		int res = 0;

		for (int i = 0; i < LMX; i++)
			if (exi & (1 << i))
				res += ac[i].match(t);

		return res;
	}
};

dynamic_aho_corasick pos, neg;
string s;
int n, op;
char c;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &op);
		
		s.clear();
		getchar();
		while ((c = getchar()) != '\n' && c != EOF)
			s.push_back(c);

		if (op == 1) pos.insert(s);
		else if (op == 2) neg.insert(s);
		else printf("%d\n", pos.match(s) - neg.match(s));
		fflush(stdout);
	}

	return 0;
}