#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

const double pi = 3.14159265358979323;

struct circle{
	circle(){ x = y = r = 0; }
	int x, y, r;

	bool operator == (const circle t) const{
		return x == t.x && y == t.y && r == t.r;
	}
}C[3];
bool cmpr(const circle& a, const circle& b){ return a.r > b.r; }

inline int sq(int a){ return a * a; }
inline double sq(double a){ return a * a; }

vector<double> A[3];
int par[3] = {0,1,2};
int find(int x)
{
	if (par[x] != x) par[x] = find(par[x]);
	return par[x];
}

double norm(double a)
{
	while (a < 0) a += 2 * pi;
	while (a >= 2 * pi) a -= 2 * pi;
	return a;
}

void in(int i, double set, double dif)
{
	double a = norm(set-dif);
	double b = norm(set+dif);

	A[i].push_back(a);
	A[i].push_back(b);
}

int main()
{
	int N; scanf("%d", &N);

	for (int i=0;i<N;i++){
		scanf("%d %d %d", &C[i].x, &C[i].y, &C[i].r);
	}
	sort(C, C+N, cmpr);

	for (int i=0;i<N;i++) for (int j=i+1;j<N;j++){
		int d2 = sq(C[i].x - C[j].x) + sq(C[i].y - C[j].y);
		int pr2 = sq(C[i].r + C[j].r);
		int mr2 = sq(C[i].r - C[j].r);

		if (pr2 < d2 || mr2 > d2) continue;

		par[find(j)] = find(i);

		int vx = C[j].x - C[i].x;
		int vy = C[j].y - C[i].y;

		double set = atan2(vy, vx);
		double dif = acos((double)(C[i].r * C[i].r + d2 - C[j].r * C[j].r) / (2 * C[i].r * sqrt((double)d2)));
		in(i, set, dif);

		set = set + pi;
		dif = acos((double)(C[j].r * C[j].r + d2 - C[i].r * C[i].r) / (2 * C[j].r * sqrt((double)d2)));
		in(j, set, dif);
	}

	int ans = 1, chk[3] ={0,};
	for (int i=0;i<N;i++){
		if (!chk[find(i)]) ans++;
		chk[find(i)] = 1;
	}

	vector<pair<double, double> > pt;
	for (int i=0;i<N;i++){
		if (A[i].empty()){
			continue;
		}

		vector<double> TEMP;
		sort(A[i].begin(), A[i].end());
		int sz = 1;
		TEMP.push_back(A[i][0]);
		for (int j=1;j<A[i].size();j++){
			if (A[i][j] - TEMP[sz-1] < 1e-9) continue;
			TEMP.push_back(A[i][j]);
			sz++;
		}
		for (auto d : TEMP){
			double x = C[i].x + cos(d) * C[i].r;
			double y = C[i].y + sin(d) * C[i].r;
			int g = 1;
			for (int i=0;i<pt.size();i++){
				if (abs(pt[i].first-x) < 1e-9 && abs(pt[i].second-y) < 1e-9) g = 0;
			}
			if (g) pt.push_back({x,y});
		}
		ans += sz;
	}
	ans -= pt.size();
	printf ("%d\n",ans);

	return 0;
}