#include <bits/stdc++.h>
using namespace std;

const int Maxa = 55;
const int Maxb = 615;
const int Maxc = 615;
const int nil = 305;
const int Inf = 1000000000;

struct pos {
	int x, y, z;
	pos(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
	bool operator <(const pos &u) const {
		if (x != u.x) return x < u.x;
		if (y != u.y) return y < u.y;
		return z < u.z;
	}
};

typedef pair <int, pos> ip;

string s;
int dist[Maxa][Maxb][Maxc];

int main()
{
	cin >> s;
	reverse(s.begin(), s.end());
	s += "000";
	fill((int*)dist, (int*)dist + Maxa * Maxb * Maxc, Inf);
	dist[int(s.length()) - 1][nil][nil] = 0;
	priority_queue <ip> Q;
	Q.push(ip(0, pos(int(s.length()) - 1, nil, nil)));
	while (!Q.empty()) {
		pos v = Q.top().second;
		int d = -Q.top().first; Q.pop();
		if (dist[v.x][v.y][v.z] != d) continue;
		if (v.x == 0 && v.y == nil) { printf("%d\n", d); return 0; }
		pos u;
		if (v.x > 0) {
			u = pos(v.x - 1, nil + (v.y - nil) * 10 + int(s[v.x - 1] - '0') - (v.z - nil), v.z);
			if (0 <= u.x && 0 <= u.y && u.y < Maxb)
				if (d < dist[u.x][u.y][u.z]) {
					dist[u.x][u.y][u.z] = d;
					Q.push(ip(-d, u));
				}
		}
		u = pos(v.x, v.y + 1, v.z - 1);
		int cand = d + v.x + 1;
		if (0 <= u.y && u.y < Maxb && 0 <= u.z && u.z < Maxc)
			if (cand < dist[u.x][u.y][u.z]) {
				dist[u.x][u.y][u.z] = cand;
				Q.push(ip(-cand, u));
			}
		u = pos(v.x, v.y - 1, v.z + 1);
		cand = d + v.x + 1;
		if (0 <= u.y && u.y < Maxb && 0 <= u.z && u.z < Maxc)
			if (cand < dist[u.x][u.y][u.z]) {
				dist[u.x][u.y][u.z] = cand;
				Q.push(ip(-cand, u));
			}
	}
    return 0;
}