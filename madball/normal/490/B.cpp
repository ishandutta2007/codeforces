#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Note {
	int first, last;
	Note() {}
	Note(int f, int l): first(f), last(l) {}
	operator int() const {
		return first;
	}
};

class Comp {
public:
	bool operator()(Note const &n1, Note const &n2) const {
		return n1.last < n2.last;
	}
};

int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	Note cur;
	set<Note> notes1;
	set<Note, Comp> notes2;
	for (int i = 0; i < n; i++) {
		cin >> cur.first >> cur.last;
		notes1.insert(cur);
		notes2.insert(cur);
	}

	vector<int> res(n);
	cur = (*notes1.begin());
	set<Note>::iterator it;
	set<Note, Comp>::iterator it2;
	int i = 1;
	for (; i < res.size() - 2; i += 2) {
		cur = *notes1.lower_bound(Note(cur.last, cur.last));
		res[i] = cur.first;
	}
	res[i] = cur.last;

	for (it = notes1.begin(); it != notes1.end(); it++) {
		it2 = notes2.lower_bound(Note((*it).first, (*it).first));
		if ((it2 == notes2.end()) || ((*it2).last != (*it).first)) {
			cur = (*it);
			break;
		}
	}
	
	res[0] = cur.first;
	for (i = 2; i < res.size(); i += 2) {
		res[i] = cur.last;
		if (i + 2 >= res.size())
			break;
		cur = *notes1.lower_bound(Note(cur.last, cur.last));
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ' ';

	return 0;
}