#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vvi x0, x1, y0, y1, z0, z1;
	vvvi output;
	vvvi what;
	const vector<int> dx = {1, -1, 0, 0, 0, 0};
	const vector<int> dy = {0, 0, 1, -1, 0, 0};
	const vector<int> dz = {0, 0, 0, 0, 1, -1};

	int n, m, p;
	cin >> n >> m >> p;
	x0.assign(m, vi(p, 0));
	x1.assign(m, vi(p, 0));
	y0.assign(n, vi(p, 0));
	y1.assign(n, vi(p, 0));
	z0.assign(n, vi(m, 0));
	z1.assign(n, vi(m, 0));
	output.assign(n, vvi(m, vi(p, -1)));
	what.assign(n, vvi(m, vi(p, 0)));
	for(int i = 0; i < m; i++) for(int j = 0; j < p; j++) cin >> x0[i][j];
	for(int i = 0; i < m; i++) for(int j = 0; j < p; j++) cin >> x1[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < p; j++) cin >> y0[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < p; j++) cin >> y1[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> z0[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> z1[i][j];

	auto fail = [](){
		cout << -1 << '\n';
		exit(0);
	};

	auto cons = [&](int x, int y, int z, int id){
		if(id == 0) return x0[y][z];
		if(id == 1) return x1[y][z];
		if(id == 2) return y0[x][z];
		if(id == 3) return y1[x][z];
		if(id == 4) return z0[x][y];
		if(id == 5) return z1[x][y];
		assert(false);
	};

	vector<vector<int> > q;
	auto add = [&](int x, int y, int z, int id){
		// cerr << x << ' ' << y << ' ' << z << ' ' << id << '\n';
		int f = cons(x, y, z, id);
		if(x < 0 || y < 0 || z < 0 || x >= n || y >= m || z >= p){
			// cerr << x << ' ' << y << ' ' << z << ' ' << id << ' ' << f << '\n';
			if(f > 0) fail();
			return;
		}
		what[x][y][z] |= (1 << id);
		q.push_back({x, y, z});
	};
	int s = 0;
	for(int i = 0; i < m; i++) for(int j = 0; j < p; j++) { add(0, i, j, 0); add(n-1, i, j, 1); }
	for(int i = 0; i < n; i++) for(int j = 0; j < p; j++) { add(i, 0, j, 2); add(i, m-1, j, 3); }
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) { add(i, j, 0, 4); add(i, j, p-1, 5); }

	while(s < (int)q.size()){
		vector<int> r = q[s];
		s++;
		int x = r[0];
		int y = r[1];
		int z = r[2];
		vector<int> needs;
		for(int f = 0; f < 6; f++){
			if((what[x][y][z] >> f) & 1) needs.push_back(cons(x, y, z, f));
		}
		for(int a : needs){
			if(a == 0) output[x][y][z] = 0;
			for(int b : needs){
				if(a != b) output[x][y][z] = 0;
			}
		}
		if(output[x][y][z] == 0){
			for(int f = 0; f < 6; f++){
				if((what[x][y][z] >> f) & 1){
					int nx = x + dx[f];
					int ny = y + dy[f];
					int nz = z + dz[f];
					add(nx, ny, nz, f);
				}
			}
			what[x][y][z] = 0;
		}
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) for(int k = 0; k < p; k++){
		if(output[i][j][k] == -1){
			vector<int> needs;
			for(int f = 0; f < 6; f++){
				if((what[i][j][k] >> f) & 1) needs.push_back(cons(i, j, k, f));
			}
			for(int a : needs){
				assert(a != 0);
				for(int b : needs){
					assert(a == b);
				}
			}
			output[i][j][k] = (needs.empty() ? 0 : needs.front());
		}
		cout << output[i][j][k] << ' ';
	}
	cout << '\n';
}