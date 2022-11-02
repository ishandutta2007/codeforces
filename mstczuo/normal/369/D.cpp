# include <iostream>
# include <cstdio>
# include <queue>
# include <cstring>
using namespace std;
# define x first
# define y second
# define mp make_pair
const int N = 3001;
queue<pair<int,int> > q;

short c[N], d[N]; int n, m;
bool v[N][N];

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) scanf("%hd", &c[i]);
	for(int i=n-1; i>=0; i--) d[i] = max(d[i+1], c[i]);
	memset(v, 0, sizeof(v));

	q.push(mp(0,1)); v[0][1] = true; 
	int ls = 1; pair<int,int> t;

	while(m--) {
		while(ls--) {
			t = q.front(); q.pop();
			if(t.y >= n) continue;

			if(c[t.x]>0 && d[t.y]>0) 
				if (!v[t.y+1][t.y+2])
					v[t.y+1][t.y+2] = true,
					q.push(mp(t.y+1,t.y+2));

			if(c[t.x]>0 && d[t.y]!=100) 
				if (!v[t.x][t.y+1])
					v[t.x][t.y+1] = true,
					q.push(mp(t.x,t.y+1));
					
			if(c[t.x]!=100 && d[t.y]>0)
				if (!v[t.y][t.y+1])
					v[t.y][t.y+1] = true,
					q.push(mp(t.y,t.y+1));
		}
		ls = q.size();
	}
	long long ans = 0;
	for(int i=0; i<n+1; i++)
		for(int j=i+1; j<=n+2; j++)
			if(v[i][j]) ans++;
	cout << ans << endl;
	return 0;
}