# include <cstdio>
# include <vector>
# include <cstdlib>
# include <ctime>
using namespace std;

int lx = -100000000;
int ly = -100000000;
int mx = 100000000;
int my = 100000000;
int pv;

int get(int x,int y) {
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

bool test_line_y(int y) {
	if(y > my) return false;
	if(get(pv, y) != 0) return false;
	return true;
}

bool test_line_x(int x) {
	if(x > mx) return false;
	if(get(x, pv) != 0) return false;
	return true;
}

vector<int> X;
vector<int> Y;

int main() {
	srand((unsigned)time(NULL));
	while(true) {
		pv = rand();
		if(get(pv, pv) != 0) break;
	}
	int d = get(lx, ly);
	int cx = lx + d, cy = ly + d;
	if(test_line_x(cx)) X.push_back(cx);
	if(test_line_y(cy)) Y.push_back(cy);
	lx = cx, ly = cy;
	while(lx <= mx && ly <= my) {
		int p;
		for(p = 1; lx + p <= mx && ly + p <= my; p = p << 1) {
			d = get(lx + p, ly + p);
			if(d == p) continue;
			int cx = lx + p + d, cy = ly + p + d;
			if(test_line_x(cx)) {
				X.push_back(cx); 
				if(test_line_y(cy)) Y.push_back(cy); 
			} else Y.push_back(cy); 
			lx = cx, ly = cy, p = 0;
			break;
		}
		if(lx + p > mx || ly + p > my) break;
	}
	printf("1 %d %d\n", (int)X.size(), (int)Y.size());
	fflush(stdout);
	for(auto x: X) printf("%d ", x); puts("");
	fflush(stdout);
	for(auto y: Y) printf("%d ", y); puts("");
	fflush(stdout);
	return 0;
}