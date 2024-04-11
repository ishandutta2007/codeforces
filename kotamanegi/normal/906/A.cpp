#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int gogo[60] = {};
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < 26;++i) {
		gogo[i] = 1;
	}
	int ans = 0;
	int do_all = -1;
	for (int i = 0;i < n;++i) {
		string a, b;
		cin >> a >> b;
		if (a == "!") {
			if (do_all != -1) ans++;
			int gege[60] = {};
			for (int q = 0;q < b.length();++q) {
				gege[b[q] - 'a'] |= gogo[b[q] - 'a'];
			}
			for (int q = 0;q < 50;++q) {
				gogo[q] = gege[q];
			}
		}
		else if (a == "?") {
			if (do_all != -1&&do_all != b[0] - 'a') ans++;
			gogo[b[0] - 'a'] = 0;
		}else if(a == "."){
			for (int i = 0;i < b.length();++i) {
				gogo[b[i] - 'a'] = 0;
			}
		}
		int bad = -1;
		for (int i = 0;i < 26;++i) {
			if (gogo[i]) {
				if (bad != -1) bad = 100;
				else bad = i;
			}
		}
		if (bad != 100) {
			do_all = bad;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
static uint32_t x = 1;
static uint32_t y = 111;
static uint32_t z = 222;
static uint32_t w = 333;
uint32_t xor128(void) {
	uint32_t t;
	t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
int x_move[4] = { 1,0,-1,0 };
int y_move[4] = { 0,1,0,-1 };
class Grid {
public:
	int known_grid[10000][10000] = {};
	int start_up(long long seed) {
		x = seed;
		y = 111;
		z = 222;
		w = 333;
		now_x = 1;
		now_y = 1;
		for (int i = 1;i <= grid_size_x;++i) {
			for (int q = 1;q <= grid_size_y;++q) {
				grid[i][q] = ((rand() % 3)/2);
				fail[i][q] = 0;
				known_grid[i][q] = 2;
			}
		}
		for (int i = 0;i <= max(grid_size_x, grid_size_y) + 1;++i) {
			grid[i][0] = 1;
			grid[0][i] = 1;
			grid[grid_size_x + 1][i] = 1;
			grid[i][grid_size_y + 1] = 1;
			known_grid[i][0] = 1;
			known_grid[0][i] = 1;
			known_grid[grid_size_x + 1][i] = 1;
			known_grid[i][grid_size_y + 1] = 1;
		}
		grid[1][1] = 0;
		grid[grid_size_x][grid_size_y] = 0;
		queue<pair<int, int>> wow;
		wow.push(make_pair(1, 1));
		while (wow.empty() == false) {
			pair<int, int> now = wow.front();
			wow.pop();
			if (fail[now.first - 1][now.second] == 0 && grid[now.first - 1][now.second] == 0) {
				fail[now.first - 1][now.second] = 1;
				wow.push(make_pair(now.first - 1, now.second));
			}
			if (fail[now.first + 1][now.second] == 0 && grid[now.first + 1][now.second] == 0) {
				fail[now.first + 1][now.second] = 1;
				wow.push(make_pair(now.first + 1, now.second));
			}
			if (fail[now.first][now.second-1] == 0 && grid[now.first][now.second-1] == 0) {
				fail[now.first][now.second-1] = 1;
				wow.push(make_pair(now.first, now.second-1));
			}
			if (fail[now.first][now.second + 1] == 0 && grid[now.first][now.second + 1] == 0) {
				fail[now.first][now.second + 1] = 1;
				wow.push(make_pair(now.first, now.second + 1));
			}
		}
		if (fail[grid_size_x][grid_size_y] == false) {
			start_up(seed + 1);
		}
		now_y = 0;
		make_move(2);
		moved = 0;
		started = 1;
		known_grid[1][1] = 0;
		return 0;
	}
	int make_move(int n) {//n={0,1,2,3},move={L,U,R,D}
		moved++;
		if (n == 0) {
			now_y--;
		}
		else if (n == 1) {
			now_x--;
		}
		else if (n == 2) {
			now_y++;
		}
		else {
			now_x++;
		}
		if (grid[now_x][now_y] == 1) {
			//cout << "" << endl;
			if (n == 0) {
				now_y++;
			}
			else if (n == 1) {
				now_x++;
			}
			else if (n == 2) {
				now_y--;
			}
			else {
				now_x--;
			}
		}
		for (int i = 0;i < 4;++i) {
			int foo = 0;
			for (int q = 1;foo == 0;++q) {
				now_x += q*x_move[i];
				now_y += q*y_move[i];
				if (now_x == grid_size_x&&now_y == grid_size_y) {
					//cout << "Score:" << moved+q << endl;
					final_ans += moved + q;
					started = 0;
				}
				if (grid[now_x][now_y] == 1) {
					known_grid[now_x][now_y] = 1;
					foo = 1;
				}
				else {
					known_grid[now_x][now_y] = 0;
				}
				now_x-= q*x_move[i];
				now_y -= q*y_move[i];
			}
		}
		for (int i = 0;i <= grid_size_x + 1;++i) {
			for (int q = 0;q <= grid_size_y + 1;++q) {
				if (now_x == i&&now_y == q) {
					cout << "Y";
				}
				else if(i == grid_size_x && q == grid_size_y){
					cout << "G";
				}
				else if (known_grid[i][q] == 1) {
					cout << "#";
				}
				else if (known_grid[i][q] == 0) {
					cout << " ";
				}
				else if (known_grid[i][q] == 2) {
					cout << "?";
				}
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
	int move_up() {
		make_move(1);
		return 0;
	}
	int move_left() {
		make_move(0);
		return 0;
	}
	int move_right() {
		make_move(2);
		return 0;
	}
	int move_down() {
		make_move(3);
		return 0;
	}
	int now_x = 1;
	int now_y = 1;
	int started = 0;
	long long final_ans = 0;
private:
	int moved = 0;
	const int grid_size_x = 5;
	const int grid_size_y = 5;
	int grid[1000][1000] = {};
	int fail[1000][1000] = {};
};
auto grid = new Grid;
int visited[2000][2000] = {};
int dfs(int x, int y) {
	if (visited[x + 1][y] == 0&&grid -> known_grid[x+1][y] == 0) {
		visited[x + 1][y] = true;
		grid->move_down();
		if (grid->started == 0) return 1;
		int wow = dfs(x + 1, y);
		if (wow == 1) return 1;
		grid->move_up();
	}
	if (visited[x - 1][y] == 0 && grid->known_grid[x - 1][y] == 0) {
		visited[x - 1][y] = true;
		grid->move_up();
		if (grid->started == 0) return 1;
		int wow = dfs(x - 1, y);
		if (wow == 1) return 1;
		grid->move_down();
	}
	if (visited[x][y + 1] == 0 && grid->known_grid[x][y + 1] == 0) {
		visited[x][y + 1] = true;
		grid->move_right();
		if (grid->started == 0) return 1;
		int wow = dfs(x, y + 1);
		if (wow == 1) return 1;
		grid->move_left();
	}
	if (visited[x][y - 1] == 0 && grid->known_grid[x][y - 1] == 0) {
		visited[x][y - 1] = true;
		grid->move_left();
		if (grid->started == 0) return 1;
		int wow = dfs(x, y - 1);
		if (wow == 1) return 1;
		grid->move_right();
	}
	return 0;
}
int main() {
	int seed;
	int now_x = 0, now_y = 0;
	long long mew = 0;
	while (mew <= 1000000) {
		int tmp;
		cin >> tmp;
		if (grid->started == 0) {
			now_x = 1;
			now_y = 1;
			mew += 100;
			grid->start_up(tmp);
			for (int i = 0;i <= 100;++i) {
				for (int q = 0;q <= 100;++q) {
					visited[i][q] = 0;
				}
			}
			if (mew % 10000 == 0) {
				cout << grid->final_ans/(mew/10) << endl;
			}
		}
		visited[1][1] = true;
		dfs(1, 1);
	}
	int tmp;
	cin >> tmp;
	return 0;
}
*/