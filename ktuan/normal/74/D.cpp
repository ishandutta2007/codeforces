#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

struct Data {
	int i, j;
	Data() {}
	Data(int i, int j) : i(i), j(j) {}
	bool operator<(Data d) const {
		if(i == -1) {
			return false;
		}
		else if(d.i == -1) return true;
		
		int len = j - i;
		int len2 = d.j - d.i;
		if(len != len2) return len > len2;
		else {
			if(j != d.j) return j > d.j;
			else return false;	
		}	
	}	
	
	Data operator+(Data d) {
		if(i == -1) return d;
		else if(d.i == -1) return *this;
		else {
			Data r;
			r.i = i;
			r.j = d.j;
			return r;	
		}
	}
};


struct Node {
	Data mid, le, ri;
	int sum;
	Node *left, *right;
};	

Node container[3000000];
int nct;

int n;
Node *root;

Data getmid(Node *n, int l, int r) {
	if(n == NULL) return Data(l, r);
	else return n -> mid;
}
Data getle(Node *n, int l, int r) {
	if(n == NULL) return Data(l, r);
	else return n -> le;
}
Data getri(Node *n, int l, int r) {
	if(n == NULL) return Data(l, r);
	else return n -> ri;
}
int getsum(Node *n, int l, int r) {
	if(n == NULL) return 0;
	else return n->sum;	
}

int getsum(Node *root, int le, int ri, int x, int y) {
	if(root == NULL) return 0; //max(0, min(y, ri) - max(x, le) + 1);
	if(x <= le && ri <= y) return root -> sum;
	int mi = (le + ri) / 2;
	int res = 0;
	if(x <= mi) res += getsum( root->left, le, mi, x, y);
	if(mi < y) res += getsum( root->right, mi+1, ri, x, y);
	return res;
}

void put(Node *&root, int le, int ri, int pos, int val) {
//	cout << "put " << le << " " << ri << " " << pos << " " << val << endl;
	if(root == NULL) root = container + nct++;
	if(le == ri) {
		root -> sum = val;
		if(val == 1) root -> mid = root -> le = root -> ri = Data(-1,-1);
		else root -> mid = root -> le = root -> ri = Data(le,ri);
	}
	else {
		int mi = (le + ri) / 2;
		if(pos <= mi) put( root->left, le, mi, pos, val);
		else put(root->right, mi+1, ri, pos, val);
		
		root->sum = getsum(root->left,le,mi) + getsum(root->right,mi+1,ri);
		
		root->le = getle(root->left,le,mi);
		if(getsum(root->left,le,mi)==0) root->le = Data(le,mi) + getle(root->right,mi+1,ri);
		
		root->ri = getri(root->right,mi+1,ri);
		if(getsum(root->right,mi+1,ri)==0) root->ri = getri(root->left,le,mi) + Data(mi+1,ri);
		
		root->mid = min(min(getmid(root->left,le,mi), getmid(root->right,mi+1,ri)), getri(root->left,le,mi) + getle(root->right,mi+1,ri));
	}
}

int main() {
	int q;
	scanf("%d%d", &n, &q);
	map<int,int> ma;
	Rep(kk,q) {
		int code;
		scanf("%d", &code);	
		if(code == 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			int res = getsum( root, 1, n, u, v);
			printf("%d\n", res);
		}
		else {
			if(!ma.count(code) || ma[code] == 0) {
				// tim va phu	
				Data d = getmid( root, 1, n);
				int id = (d.i + d.j + 1) / 2;
				// cout << "them " << id << endl;
				put( root, 1, n, id, 1);
				ma[code] = id;
			}
			else {
				int id = ma[code];
				// cout << "xoa " << id << endl;
				put( root, 1, n, id, 0);
				ma[code] = 0;	
			}
		}
	}
	return 0;	
}