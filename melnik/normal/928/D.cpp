#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 300500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

struct Node {
	int sz;
	bool end;
	Node* sons[26];
	Node () {
		sz = 0;
		end = false;
		for (int i = 0; i < 26; ++i)
			sons[i] = nullptr;
	}
};

inline bool IsLetter(char x) {
	return x <= 'z' && x >= 'a';
}

inline int GetSize(Node* T) {
	return T ? T -> sz : 0;
}

char t[maxn];
string cur;
int ans;
int was_suggestion;
int was_turn;

void Add(Node* T, int pos) {
	if (pos == cur.size()) {
		// cout << cur << ' ' << was_suggestion << ' ' << was_turn << endl;
		if (!was_suggestion) {
			ans += cur.size();
			T -> sz += !T -> end;
			T -> end = true;
			return;
		}

		if (was_turn == -1) {
			ans += cur.size();
			T -> sz += !T -> end;
			T -> end = true;
			return;
		}
			
		if (!was_turn) {
			if (T -> end)
				ans += was_suggestion + 1;
			else
				ans += cur.size();
			T -> sz += !T -> end;
			T -> end = true;
			return;
		}
		
		int cnt = was_suggestion + 1 + cur.size() - was_turn;
		ans += min((int)cur.size(), cnt);

		T -> sz += !T -> end;
		T -> end = true;
		return;
	}

	if (pos && !was_suggestion && GetSize(T) == 1) {
		was_suggestion = pos;
		was_turn = 0;
	}
	int letter = cur[pos] - 'a';
	if (!T -> sons[letter]) {
		if (!was_turn)
			if (T -> end)
				was_turn = pos;
			else
				was_turn = -1;
		T -> sons[letter] = new Node();
	}
	Add(T -> sons[letter], pos + 1);
	T -> sz = 0;
	for (int i = 0; i < 26; ++i)
		T -> sz += GetSize(T -> sons[i]);
	T -> sz += T -> end;
}

Node* T = new Node();

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    char x;
    int n = 0;
    while ((x = getchar()) != EOF) 
    	t[n++] = x;
    
	int l, r;
	l = r = 0;
	while (l < n) {
		cur = "";
		while (r < n && IsLetter(t[r])) {
			cur += t[r];
			++r;
		}
		if (r - l) {
			// ans = 0;
			was_suggestion = 0;
			was_turn = 0;
			Add(T, 0);
			// cout << cur << ' ' << ans << ' ' << endl;
		}
		while (r < n && !IsLetter(t[r])) {
			++ans;
			++r;
		}
		l = r;
	}
	printf ("%d\n", ans);
    return 0;
}