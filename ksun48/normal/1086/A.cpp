#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
set<pair<int,int> > path;
void make_path(int xa, int ya, int xm, int ym){
	path.insert({xa, ya});
	while(xa < xm){
		xa++;
		path.insert({xa, ya});
	}
	while(xa > xm){
		xa--;
		path.insert({xa, ya});
	}
	while(ya < ym){
		ya++;
		path.insert({xa, ya});
	}
	while(ya > ym){
		ya--;
		path.insert({xa, ya});
	}
}
int main(){
	int xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	int midx = xa + xb + xc - min(min(xa,xb),xc) - max(max(xa,xb),xc);
	int midy = ya + yb + yc - min(min(ya,yb),yc) - max(max(ya,yb),yc);
	make_path(xa, ya, midx, midy);
	make_path(xb, yb, midx, midy);
	make_path(xc, yc, midx, midy);
	cout << path.size() << '\n';
	for(auto x : path){
		cout << x.first << " " << x.second << '\n';
	}
}