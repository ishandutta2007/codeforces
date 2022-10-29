#include <iostream>

using namespace std;

struct interv {
	int left;
	int right;
};

interv v[101];
bool ady[101][101];

void ref(int k) {
	int a,b,c,d;
	ady[k][k] = true;
	c = v[k].left;
	d = v[k].right;
	for(int i=1; i<k; ++i) {
		a = v[i].left;
		b = v[i].right;
		ady[i][k]=(a>c&&a<d)||(b>c&&b<d);
		ady[k][i]=(c>a&&c<b)||(d>a&&d<b);
	}
	
	for(int i=1; i<k; ++i) {
		for(int j=1; j<k; ++j) {
			ady[j][k] = ady[j][k] || (ady[j][i] && ady[i][k]);
			ady[k][j] = ady[k][j] || (ady[k][i] && ady[i][j]);
		}
	}
	
	for(int i=1; i<=k; ++i)
		for(int j=1; j<=k; ++j)
			ady[i][j] = ady[i][j] || (ady[i][k] && ady[k][j]);
	
}

int main() {
	int n, k, l, r, op;
	cin >> n;
	k = 1;
	for(int i=1; i<=n; i++) {
		cin >> op >> l >> r;
		if(op==1) {
			v[k].left = l;
			v[k].right = r;
			ref(k);
			++k;
		}
		else
			cout << (ady[l][r]?"YES":"NO") << endl;
	}
}