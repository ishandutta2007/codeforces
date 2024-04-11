#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int N = 5e5 + 10;
struct vec {
    db x, y;
    vec(){ x = y = 0;}
    vec(db X, db Y){x = X, y = Y;}
    friend vec operator + (vec a, vec b) {
        return vec(a.x + b.x, a.y + b.y);
    }
    friend vec operator - (vec a, vec b) {
        return vec(a.x - b.x, a.y - b.y);
    }
    friend db operator * (vec a, vec b) {
        return a.x * b.y - a.y * b.x;
    }
    friend vec operator / (vec v, db t) {
        return vec(v.x / t, v.y / t);
    }
    friend vec operator * (vec v, db t) {
        return vec(v.x * t, v.y * t);
    }
  
}p[N];
int n;
int id[N];
int ans[N], tot = 0, vis[N];
  
typedef vec poi;
db dist(poi v) {
    return v.x * v.x + v.y * v.y;
}

int cmp(int a, int b) {
	if(p[a].x != p[b].x) return p[a].x < p[b].x;
	return p[a].y < p[b].y;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y, id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	int now = 1;
	for(int i = 2; i <= n; i++) {
		ans[++tot] = now;
		vis[now] = 1;
		int mx = now;
		for(int j = 1; j <= n; j++) {
			if(vis[j]) continue;
			if(dist(p[now] - p[mx]) < dist(p[now] - p[j])) mx = j;
		}
		now = mx;
	}
	ans[++tot] = now;
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
    return 0;
}