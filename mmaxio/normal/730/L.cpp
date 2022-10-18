#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>

#include <unordered_map>

using namespace std;

#ifdef LOCAL
#define debug_flag 1
#else
#define debug_flag 0
#endif

template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p)
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<vector<T>>& v)
{

	os << "[" << endl;
	bool first = true;
	for (typename std::vector<vector<T>>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it << endl;
	}
	os << "]" << endl;
	return os;
}

typedef long long int int64;

const int N = (int)4e5 + 100;
const int LOGN = 20;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;

const int PLUS = 0;
const int MUL = 1;
const int NUMBER = 2;

int mod_add(int a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

int mod_sub(int a, int b)
{
	a -= b;
	if (a < 0)
		a += mod;
	return a;
}

int mod_mul(int a, int b)
{
	return (int64)a * b % mod;
}

struct SparseTable
{
	int min_val[N][LOGN];
	int max_pow2[N];

	SparseTable()
	{

	}

	void init(int n, int arr[])
	{
		fill(max_pow2, max_pow2 + N, 0);

		for (int i = 2; i < N; i *= 2)
			max_pow2[i] = 1;

		for (int i = 1; i < N; i++)
			max_pow2[i] += max_pow2[i - 1];

		for (int i = 0; i < N; i++)
		{
			if (i < n)
				min_val[i][0] = arr[i];
			else
				min_val[i][0] = INF;
		}

		for (int st = 1; st < LOGN; st++)
		{
			for (int i = 0; i + (1 << (st - 1)) < N; i++)
			{
				min_val[i][st] = min(min_val[i][st - 1], min_val[i + (1 << (st - 1))][st - 1]);
			}
		}
	}

	int get_min(int a, int b)
	{
		assert(0 <= a);
		assert(a <= b);
		assert(b < N);

		int len = b - a + 1;
		int p = max_pow2[len];
		return min(min_val[a][p], min_val[b - (1 << p) + 1][p]);
	}
};

bool not_inter(int l, int r, int a, int b)
{
	return l > b || r < a;
}

bool is_in(int l, int r, int a, int b)
{
	return a <= l && r <= b;
}

struct SumTree
{
	int pow2;
	vector<int> sum;

	SumTree()
	{

	}

	void init(int n)
	{
		pow2 = 1;
		while (pow2 < n)
			pow2 *= 2;

		sum.resize(pow2 * 2);
	}

	void set(int pos, int val)
	{
		pos += pow2;
		sum[pos] = val;
		pos /= 2;

		while (pos >= 1)
		{
			sum[pos] = mod_add(sum[pos * 2], sum[pos * 2 + 1]);
			pos /= 2;
		}
	}

	int get_sum(int a, int b)
	{
		assert(0 <= a);
		assert(a <= b);
		assert(b < N);

		return get_sum(1, 0, pow2 - 1, a, b);
	}

	int get_sum(int v, int l, int r, int a, int b)
	{
		if (not_inter(l, r, a, b))
			return 0;
		if (is_in(l, r, a, b))
			return sum[v];
		int m = (l + r) / 2;
		return mod_add(get_sum(v * 2, l, m, a, b),
			get_sum(v * 2 + 1, m + 1, r, a, b));
	}
};

struct MulTree
{
	int pow2;
	vector<int> mul;

	MulTree()
	{

	}

	void init(int n)
	{
		pow2 = 1;
		while (pow2 < n)
			pow2 *= 2;

		mul.resize(pow2 * 2, 1);
	}

	void set(int pos, int val)
	{
		pos += pow2;
		mul[pos] = val;
		pos /= 2;

		while (pos >= 1)
		{
			mul[pos] = mod_mul(mul[pos * 2], mul[pos * 2 + 1]);
			pos /= 2;
		}
	}

	int get_mul(int a, int b)
	{
		assert(0 <= a);
		assert(a <= b);
		assert(b < N);

		return get_mul(1, 0, pow2 - 1, a, b);
	}

	int get_mul(int v, int l, int r, int a, int b)
	{
		if (not_inter(l, r, a, b))
			return 1;
		if (is_in(l, r, a, b))
			return mul[v];
		int m = (l + r) / 2;
		return mod_mul(get_mul(v * 2, l, m, a, b),
			get_mul(v * 2 + 1, m + 1, r, a, b));
	}
};

struct BracketsChecker
{
	int n;
	int bal[N];
	SparseTable sparse_table;

	BracketsChecker()
	{

	}

	void init(string exp)
	{
		n = (int)exp.length();
		int cur_bal = 0;

		for (int i = 0; i < n; i++)
		{
			if (exp[i] == '(')
				cur_bal++;
			if (exp[i] == ')')
				cur_bal--;
			bal[i] = cur_bal;
		}

		sparse_table.init(n, bal);
	}

	bool is_correct(int a, int b)
	{
		assert(0 <= a);
		assert(a <= b);
		assert(b < N);

		int a_bal = 0;
		if (a != 0)
			a_bal = bal[a - 1];

		int min_bal = sparse_table.get_min(a, b);

		int b_bal = bal[b];

		return a_bal == min_bal && min_bal == b_bal;
	}
};

struct DigitItem
{
	int value;
	int pow10;

	DigitItem() : value(), pow10() {}
	DigitItem(int _value, int _pow10) : value(_value), pow10(_pow10) {}

	DigitItem merge(const DigitItem &other) const
	{
		int new_value = mod_add(other.value, mod_mul(value, other.pow10));
		int new_pow10 = mod_mul(pow10, other.pow10);
		return DigitItem(new_value, new_pow10);
	}
};

struct DigitTree
{
	int pow2;
	vector<DigitItem> tree;

	DigitTree()
	{

	}

	void init(string expr)
	{
		int n = (int)expr.size();

		pow2 = 1;
		while (pow2 < n)
			pow2 *= 2;

		tree.resize(pow2 * 2);
		for (int i = 0; i < pow2; i++)
		{
			if (i < n && isdigit(expr[i]))
				tree[pow2 + i] = DigitItem(expr[i] - '0', 10);
			else
				tree[pow2 + i] = DigitItem(0, 1);
		}

		for (int i = pow2 - 1; i >= 1; i--)
			tree[i] = tree[i * 2].merge(tree[i * 2 + 1]);
	}

	DigitItem get(int a, int b)
	{
		return get(1, 0, pow2 - 1, a, b);
	}

	DigitItem get(int v, int l, int r, int a, int b)
	{
		if (not_inter(l, r, a, b))
			return DigitItem(0, 1);

		if (is_in(l, r, a, b))
			return tree[v];

		int m = (l + r) / 2;
		return get(v * 2, l, m, a, b).merge(get(v * 2 + 1, m + 1, r, a, b));
	}
};

DigitTree digit_tree;

struct Token
{
	int type;
	int value;
	int real_a, real_b;

	Token() : type(), value(), real_a(), real_b() {}

	Token(int _type, int _value, int _real_a, int _real_b) :
		type(_type), value(_value), real_a(_real_a), real_b(_real_b) {}

	int solve(int a, int b)
	{
		if (a == real_a && b == real_b)
			return value;
		DigitItem digit_item = digit_tree.get(a, b);
		return digit_item.value;
	}
};

int get_pos(const vector<int> &real_a_list, int a)
{
	return upper_bound(real_a_list.begin(), real_a_list.end(), a) - real_a_list.begin() - 1;
}


struct PlusItem
{
	int value;
	int real_a, real_b;
	MulTree mul_tree;
	vector<Token> tokens;
	vector<int> real_a_list;

	PlusItem()
	{

	}

	PlusItem(vector<Token> _tokens)
	{
		assert(!_tokens.empty());
		assert(_tokens[0].type == NUMBER);
		assert(_tokens.back().type == NUMBER);

		real_a = _tokens[0].real_a;
		real_b = _tokens.back().real_b;

		tokens = vector<Token>();
		real_a_list = vector<int>();
		value = 1;
		for (Token token : _tokens)
		{
			if (token.type == NUMBER)
			{
				real_a_list.push_back(token.real_a);
				tokens.push_back(token);
				value = mod_mul(value, token.value);
			}
			else
				assert(token.type == MUL);
		}

		mul_tree.init((int)tokens.size());
		for (int i = 0; i < (int)tokens.size(); i++)
			mul_tree.set(i, tokens[i].value);
	}

	int solve(int a, int b)
	{
		int block_a = get_pos(real_a_list, a);
		int block_b = get_pos(real_a_list, b);

		if (block_a == block_b)
			return tokens[block_a].solve(a, b);

		int mid = 1;
		if (block_a + 1 <= block_b - 1)
			mid = mul_tree.get_mul(block_a + 1, block_b - 1);

		int val_a = tokens[block_a].solve(a, tokens[block_a].real_b);
		int val_b = tokens[block_b].solve(tokens[block_b].real_a, b);

		int ans = mod_mul(mid, mod_mul(val_a, val_b));

		return ans;
	}
};

struct BracketItem
{
	int value;
	int real_a, real_b;
	SumTree sum_tree;
	vector<PlusItem> plus_items;
	vector<int> real_a_list;

	BracketItem()
	{

	}

	BracketItem(vector<Token> _tokens)
	{
		assert(!_tokens.empty());
		assert(_tokens[0].type == NUMBER);
		assert(_tokens.back().type == NUMBER);

		real_a = _tokens[0].real_a;
		real_b = _tokens.back().real_b;

		value = 0;
		plus_items = vector<PlusItem>();
		real_a_list = vector<int>();

		_tokens.push_back(Token(PLUS, 0, 0, 0));
		vector<Token> cur_tokens;

		for (Token token : _tokens)
		{
			if (token.type == PLUS)
			{
				PlusItem plus_item = PlusItem(cur_tokens);
				cur_tokens.clear();
				plus_items.push_back(plus_item);
				value = mod_add(value, plus_item.value);
				real_a_list.push_back(plus_item.real_a);
			}
			else
			{
				cur_tokens.push_back(token);
			}
		}

		sum_tree.init(plus_items.size());
		for (int i = 0; i < (int)plus_items.size(); i++)
			sum_tree.set(i, plus_items[i].value);
	}

	int solve(int a, int b)
	{
		int block_a = get_pos(real_a_list, a);
		int block_b = get_pos(real_a_list, b);

		if (block_a == block_b)
			return plus_items[block_a].solve(a, b);

		int mid = 0;
		if (block_a + 1 <= block_b - 1)
			mid = sum_tree.get_sum(block_a + 1, block_b - 1);

		int val_a = plus_items[block_a].solve(a, plus_items[block_a].real_b);
		int val_b = plus_items[block_b].solve(plus_items[block_b].real_a, b);

		int ans = mod_add(mid, mod_add(val_a, val_b));
		
		return ans;
	}
};

string read_string()
{
	char buf[N];
	scanf("%s", buf);
	return string(buf);
}

string expr;
BracketsChecker brackets_checker;
int r_bracket[N];
int cover_bracket[N];
BracketItem bracket_items[N];

void match_brackets()
{
	vector<int> open_brackets;
	for (int i = 0; i < (int)expr.length(); i++)
	{
		char c = expr[i];
		
		if (c == '(')
			open_brackets.push_back(i);

		if (c == ')')
		{
			assert(!open_brackets.empty());
			r_bracket[open_brackets.back()] = i;
			open_brackets.pop_back();
		}
	}

	assert(open_brackets.empty());
}

Token parse(int l, int r)
{
	assert(expr[l] == '(');
	assert(expr[r] == ')');

	vector<Token> token_list;

	int ptr = l + 1;
	while (ptr < r)
	{
		if (expr[ptr] == '+')
		{
			cover_bracket[ptr] = l;
			token_list.push_back(Token(PLUS, 0, ptr, ptr));
			ptr++;
		}
		else if (expr[ptr] == '*')
		{
			cover_bracket[ptr] = l;
			token_list.push_back(Token(MUL, 0, ptr, ptr));
			ptr++;
		}
		else if (expr[ptr] == '(')
		{
			int to_l = ptr;
			int to_r = r_bracket[ptr];
			Token token = parse(to_l, to_r);
			token_list.push_back(token);
			ptr = to_r + 1;

			cover_bracket[to_l] = l;
			cover_bracket[to_r] = l;
		}
		else
		{
			assert(isdigit(expr[ptr]));
			
			int value = 0;
			int old_ptr = ptr;

			while (ptr < r && isdigit(expr[ptr]))
			{
				cover_bracket[ptr] = l;

				value = mod_mul(value, 10);
				value = mod_add(value, expr[ptr] - '0');
				ptr++;
			}

			token_list.push_back(Token(NUMBER, value, old_ptr, ptr - 1));
		}
	}

	BracketItem bracket_item = BracketItem(token_list);
	bracket_item.real_a = l;
	bracket_item.real_b = r;
	bracket_items[l] = bracket_item;

	return Token(NUMBER, bracket_item.value, bracket_item.real_a, bracket_item.real_b);
}

int solve(int a, int b)
{
	if (!brackets_checker.is_correct(a, b))
		return -1;

	if (expr[a] == '+' || expr[a] == '*')
		return -1;

	if (expr[b] == '+' || expr[b] == '*')
		return -1;

	int l_br = cover_bracket[a];
	int r_br = cover_bracket[b];
	
	assert(l_br == r_br);

	int ans = bracket_items[l_br].solve(a, b);
	
	return ans;
}

void solve()
{
	expr = read_string();
	expr = "(" + expr + ")";

	brackets_checker.init(expr);

	match_brackets();

	digit_tree.init(expr);

	parse(0, (int)expr.length() - 1);

	int q;
	scanf("%d", &q);

	for (int it = 0; it < q; it++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int ans = solve(a, b);
		printf("%d\n", ans);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}