#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Block {
	int h, w;
	string str;

	Block(int h_, int w_) : h(h_), w(w_), str(h_ * w_, ' ') {}
	const char& get(int y, int x) const { return str[y*w + x]; }
	char& get(int y, int x) { return str[y*w + x]; }
};

Block strBlock(string str) {
	Block res(3, str.size() + 4);
	for (int x = 1; x < res.w - 1; ++x) {
		res.get(0, x) = '-';
		res.get(2, x) = '-';
	}
	for (int y = 0; y < res.h; ++y) {
		res.get(y, 0) = '+';
		res.get(y, res.w - 1) = '+';
	}
	for (int i = 0; i < str.size(); ++i) res.get(1, 2 + i) = str[i];

	return res;
}

Block questionBlock(const Block& b) {
	Block res(b.h + 3, b.w + 6);
	for (int y = 0; y < b.h; ++y) {
		for (int x = 0; x < b.w; ++x) {
			res.get(y+3, x+3) = b.get(y, x);
		}
	}

	res.get(1, 0) = '+';
	res.get(2, 0) = '|';
	res.get(3, 0) = '|';
	res.get(4, 0) = '+';
	res.get(4, 1) = '-';
	res.get(4, 2) = '>';
	for (int x = 1; x < res.w - 2; ++x) res.get(1, x) = '-';
	res.get(1, res.w - 2) = '>';
	res.get(1, res.w - 1) = '+';
	res.get(2, res.w - 1) = '|';
	res.get(3, res.w - 1) = '|';
	res.get(4, res.w - 3) = '-';
	res.get(4, res.w - 2) = '>';
	res.get(4, res.w - 1) = '+';

	return res;
}

Block plusBlock(const Block& b) {
	Block res(b.h + 2, b.w + 6);
	for (int y = 0; y < b.h; ++y) {
		for (int x = 0; x < b.w; ++x) {
			res.get(y, x+3) = b.get(y, x);
		}
	}

	res.get(1, 0) = '+';
	res.get(1, 1) = '-';
	res.get(1, 2) = '>';
	res.get(1, res.w - 3) = '-';
	res.get(1, res.w - 2) = '>';
	res.get(1, res.w - 1) = '+';

	for (int y = 2; y < res.h - 1; ++y) {
		res.get(y, 0) = '|';
		res.get(y, res.w - 1) = '|';
	}

	res.get(res.h - 1, 0) = '+';
	res.get(res.h - 1, 1) = '<';
	for (int x = 2; x < res.w - 1; ++x) res.get(res.h - 1, x) = '-';
	res.get(res.h - 1, res.w - 1) = '+';

	return res;
}

Block starBlock(const Block& b) {
	Block res(b.h + 5, b.w + 6);
	for (int y = 0; y < b.h; ++y) {
		for (int x = 0; x < b.w; ++x) {
			res.get(y+3, x+3) = b.get(y, x);
		}
	}
	
	res.get(1, 0) = '+';
	res.get(2, 0) = '|';
	res.get(3, 0) = '|';
	res.get(4, 0) = '+';
	res.get(4, 1) = '-';
	res.get(4, 2) = '>';
	for (int x = 1; x < res.w - 2; ++x) res.get(1, x) = '-';
	res.get(1, res.w - 2) = '>';
	res.get(1, res.w - 1) = '+';
	res.get(2, res.w - 1) = '|';
	res.get(3, res.w - 1) = '|';
	res.get(4, res.w - 3) = '-';
	res.get(4, res.w - 2) = '>';
	res.get(4, res.w - 1) = '+';

	for (int y = 5; y < res.h - 1; ++y) {
		res.get(y, 0) = '|';
		res.get(y, res.w - 1) = '|';
	}

	res.get(res.h - 1, 0) = '+';
	res.get(res.h - 1, 1) = '<';
	for (int x = 2; x < res.w - 1; ++x) res.get(res.h - 1, x) = '-';
	res.get(res.h - 1, res.w - 1) = '+';

	return res;
}

Block orBlock(const vector<Block>& bs) {
	int res_h = -1, res_w = 6;
	for (const Block& b : bs) {
		res_h += 1 + b.h;
		res_w = max(res_w, b.w + 6);
	}

	Block res(res_h, res_w);

	int cur_y = 0;
	for (int j = 0; j < bs.size(); ++j) {
		for (int y = 0; y < bs[j].h; ++y) {
			for (int x = 0; x < bs[j].w; ++x) {
				res.get(y + cur_y, x + 3) = bs[j].get(y, x);
			}
		}
		res.get(cur_y + 1, 0) = '+';
		res.get(cur_y + 1, 1) = '-';
		res.get(cur_y + 1, 2) = '>';
		res.get(cur_y + 1, res.w - 2) = '>';
		res.get(cur_y + 1, res.w - 1) = '+';
		for (int x = 3 + bs[j].w; x < res.w - 2; ++x) res.get(cur_y + 1, x) = '-';

		if (j+1 < bs.size()) {
			for (int y = cur_y + 2; y < cur_y + bs[j].h + 2; ++y) {
				res.get(y, 0) = '|';
				res.get(y, res.w - 1) = '|';
			}
			cur_y += bs[j].h + 1;
		}
	}
	return res;
}

Block concatBlock(const Block& a, const Block& b) {
	if (a.w == 0) return b;
	if (b.w == 0) return a;

	Block res(max(a.h, b.h), a.w + b.w + 2);
	for (int y = 0; y < a.h; ++y) {
		for (int x = 0; x < a.w; ++x) res.get(y, x) = a.get(y, x);
	}
	for (int y = 0; y < b.h; ++y) {
		for (int x = 0; x < b.w; ++x) res.get(y, x + a.w + 2) = b.get(y, x);
	}
	res.get(1, a.w) = '-';
	res.get(1, a.w + 1) = '>';
	return res;
}

Block inBlock(const Block& b) {
	Block res(b.h, b.w + 6);
	for (int y = 0; y < b.h; ++y) {
		for (int x = 0; x < b.w; ++x) res.get(y, x + 3) = b.get(y, x);
	}
	res.get(1, 0) = 'S';
	res.get(1, 1) = '-';
	res.get(1, 2) = '>';
	res.get(1, res.w - 3) = '-';
	res.get(1, res.w - 2) = '>';
	res.get(1, res.w - 1) = 'F';
	return res;
}

Block parse(int a, int b, const string& str) {
	// Find OR's
	int cou = 0;
	vector<int> splits = {a-1};
	for (int i = a; i <= b; ++i) {
		if (str[i] == '(') ++cou;
		if (str[i] == ')') --cou;
		if (str[i] == '|' && cou == 0) splits.push_back(i);
	}
	splits.push_back(b+1);

	if (splits.size() > 2) {
		vector<Block> blocks;
		for (int j = 0; j + 1 < splits.size(); ++j) blocks.emplace_back(parse(splits[j] + 1, splits[j+1]-1, str));
		return orBlock(blocks);
	}

	// Read one token
	if (str[a] == '(') {
		cou = 1;
		int j = a+1;
		for (; cou > 0; ++j) {
			if (str[j] == '(') ++cou;
			else if (str[j] == ')') --cou;
		}

		Block cur = parse(a+1, j-2, str);
		while(j <= b && (str[j] == '+' || str[j] == '?' || str[j] == '*')) {
			if (str[j] == '+') cur = plusBlock(cur);
			if (str[j] == '?') cur = questionBlock(cur);
			if (str[j] == '*') cur = starBlock(cur);
			++j;
		}
		if (j <= b) return concatBlock(cur, parse(j, b, str));
		else return cur;
	}

	int j = a+1;
	while(j <= b && ('A' <= str[j] && str[j] <= 'Z')) ++j;
	
	if (j == b+1) {
		string tmp(j-a, '_');
		for (int i = 0; i < j-a; ++i) tmp[i] = str[a+i];
		return strBlock(tmp);
	}

	if ((j > a+1) && (str[j] == '+' || str[j] == '?' || str[j] == '*')) {
		--j;
		string tmp(j-a, '_');
		for (int i = 0; i < j-a; ++i) tmp[i] = str[a+i];
		return concatBlock(strBlock(tmp), parse(j, b, str));
	} else {
		string tmp(j-a, '_');
		for (int i = 0; i < j-a; ++i) tmp[i] = str[a+i];
		Block cur = strBlock(tmp);

		while(j <= b && (str[j] == '+' || str[j] == '?' || str[j] == '*')) {
			if (str[j] == '+') cur = plusBlock(cur);
			if (str[j] == '?') cur = questionBlock(cur);
			if (str[j] == '*') cur = starBlock(cur);
			++j;
		}
		if (j <= b) return concatBlock(cur, parse(j, b, str));
		else return cur;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	/*
	Block n = strBlock("N");
	Block e = strBlock("E");
	Block er = strBlock("ER");
	Block c = strBlock("C");
	Block is = strBlock("IS");
	Block cha = strBlock("CHA");
	Block ll = strBlock("LL");
	Block enging = strBlock("ENGING");

	Block e_q = questionBlock(e);
	Block c_p_p = plusBlock(plusBlock(c));
	Block first = concatBlock(concatBlock(concatBlock(n, e_q), er), c_p_p);

	Block is_s = starBlock(is);
	Block second = questionBlock(is_s);
	
	Block third = concatBlock(concatBlock(cha, ll), enging);
	
	Block join = orBlock({first, second, third});
	Block res = inBlock(join);
	*/

	string str;
	cin >> str;
	Block bl = parse(0, (int)str.size() - 1, str);
	Block res = inBlock(bl);

	cout << res.h << ' ' << res.w << '\n';
	for (int y = 0; y < res.h; ++y) {
		for (int x = 0; x < res.w; ++x) {
			cout << res.get(y, x);
		}
		cout << '\n';
	}

	
}