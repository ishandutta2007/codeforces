#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> pii;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m;
int t[milion];
bool debug = 0;
class SplayTree {
private:
	struct node 
	{
		node* left; node* right; node* parent;
		pii value;
	};

	typedef node* pnode;

	static pnode attach(pnode x, pnode L, pnode R)
	{
		//if (debug) cout << "Attachuje: " << get(x) << ' ' << get(L) << ' ' << get(R) << endl;
		x -> left = L; x -> right = R;
		if (L) L -> parent = x;
		if (R) R -> parent = x;
		return x;
	}

	inline bool dir(pnode x)
	{
		return ((x -> parent) -> right == x);
	}


	void rot(pnode x)
	{
		pnode p, g;
		p = x -> parent;
		g = p -> parent;
		bool gdzie = (g?dir(p):0);
		if (!dir(x)) //z lewo do gory
		{
			pnode B = x -> right;
			p = attach(p, B, p -> right);
			x = attach(x, x -> left, p);
		}
		else //z prawo do gory
		{
			pnode B = x -> left;
			p = attach(p, p -> left, B);
			x = attach(x, p, x -> right);
		}
		if (g && !gdzie) g = attach(g, x, g -> right);
		else if (g && gdzie) g = attach(g, g -> left, x);
		else if (!g) x -> parent = nullptr;
	}

	void splay(pnode x)
	{
		while (x -> parent)
		{
			pnode p = x -> parent;
			pnode g = p -> parent;
			if (!g) 
			{
				rot(x);
				if (debug) cout << "Zig\n";
			}
			else if (dir(p) == dir(x)) 
			{
				rot(p), rot(x);
				if (debug) cout << "Zig zig\n";
			}
			else 
			{
				rot(x), rot(x);
				if (debug) cout << "Zig zag\n";
			}
		}
		root = x;
		x -> parent = nullptr;
	}

	pnode createNewNode(pii value)
	{
		pnode tmp = new node();
		tmp -> value = value;
		return tmp;
	}
	
public:
	SplayTree() : root(nullptr) {}
	static pii get(pnode x) {return (x == nullptr?mp(INT_MIN, INT_MIN) : x -> value); }
	pnode root;
	void insert(pii value)
	{
		pnode help = createNewNode(value);
		pnode par = nullptr, tmp = root;
		if (!tmp)
		{
			root = help; return;
		}
		bool direction = 1;
		while (tmp)
		{
			par = tmp; 
			if (value > tmp -> value) direction = 1, tmp = tmp -> right;
			else direction = 0, tmp = tmp -> left;
		}
		
		if (direction) attach(par, par -> left, help);
		else attach(par, help, par -> right);
		splay(help);
	}
	
	pnode getMax()
	{
		pnode tmp = root;
		if (!tmp) return nullptr;
		while (tmp -> right) tmp = tmp -> right;
		splay(tmp);
		return tmp;
	}
	
	pnode lower_bound(pii value)
	{
		pnode tmp = root;
		if (!tmp) return nullptr;
		pnode LB = nullptr, lv = tmp; pii ret = mp(INT_MAX, INT_MAX);
		while (tmp)
		{
			lv = tmp;
			if (tmp -> value >= value && tmp -> value <= ret) ret = tmp -> value, LB = tmp;
			if (tmp -> value < value) tmp = tmp -> right;
			else tmp = tmp -> left;
		}
		splay(lv);
		if (ret >= value) return LB;
		return nullptr;
	}
	
	pnode search(pii value)
	{
		pnode help = lower_bound(value);
		if (!help) return nullptr;
		splay(help);
		if (help -> value == value) return help;
		return nullptr;
	}

	static SplayTree join(SplayTree L, SplayTree R)
	{
		if (!L.root) return R;
		if (!R.root) return L;
		L.getMax();
		L.attach(L.root, L.root -> left, R.root);
		return L;
	}

	/*static pair <SplayTree, SplayTree> split(SplayTree x, int k) //wszystko co < k leci z lewej strony
	{
		if (!x.root) return mp(SplayTree(), SplayTree());
		pnode tmp = x.lower_bound(k);
		if (!tmp) return mp(SplayTree(), x);
		SplayTree sec = SplayTree();
		sec.root = x.root -> right;
		if (sec.root) sec.root -> parent = nullptr;
		
		attach(x.root, x.root -> left, nullptr);
		return make_pair(x, sec);
	}*/
	
	void erase(pii value)
	{
		pnode tmp = search(value);
		if (tmp == nullptr) return;
		SplayTree L, R;
		if (tmp -> left)
		{
			L.root = tmp -> left;
			L.root -> parent = nullptr;
		}
		if (tmp -> right)
		{
			R.root = tmp -> right;
			R.root -> parent = nullptr;
		}

		delete tmp;
		*this = join(L, R);
	}
	
	pii get_lower_bound(pii value)
	{
		pnode tmp = lower_bound(value);
		if (!tmp) return mp(inf, inf);
		return tmp -> value;
	}
	static void print(pnode x)
	{
		if (x == nullptr) return;
		print(x -> left);
		cout << "Widze wierzcholek: " << x -> value.e1 << ' ' << x -> value.e2 << endl;
		print(x -> right);
	}

};

SplayTree tree;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> t[i], tree.insert(mp(t[i], i));
	int people = 0;
	vector <int> wyn;
	wyn.clear();
	bool da_sie = true;
	for (int i=1; i<=n; ++i)
	{
		pii help = mp(people, -inf);
		pii tmp = tree.get_lower_bound(help);
		if (tmp.e1 == people)
		{
			tree.erase(tmp);
			wyn.pb(tmp.e2);
			++people;
		}
		else
		{
			if (people > 2) people -= 3, --i;
			else 
			{
				da_sie = false;
				break;
			}
		}	
	}
	if (da_sie) 
	{
		cout << "Possible" <<endl;
		for (int i=0; i<(int)wyn.size(); ++i) cout << wyn[i] << ' ';
	}
	else cout << "Impossible";
}