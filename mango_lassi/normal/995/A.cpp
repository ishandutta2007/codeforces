#include <iostream>
#include <vector>

const int N = 50;
const int K = 2*N;
int cur[N][4];
int car_tx[K];
int car_ty[K];

std::vector<std::pair<int, std::pair<int, int>>> res;

void move(int x, int y, int tx, int ty) {
	if (cur[x][y] == -1) return;
	res.push_back({cur[x][y] + 1, {ty + 1, tx + 1}});
	cur[tx][ty] = cur[x][y];
	cur[x][y] = -1;
}

int oth(int y) {
	return (y == 1 ? 2 : 1);
}
int norm(int y) {
	if (y == 0) return 1;
	if (y == 1) return 0;
	if (y == 2) return 3;
	if (y == 3) return 2;
}

void moveEmptyTo(int tx, int ty, int ax, int ay, int& ex, int& ey) {
	if (ay == ey) {
		move(ex, oth(ey), ex, ey);
		ey = oth(ey);
	}

	int dx = tx - ex;
	if (dx < 0) dx = -1;
	if (dx > 0) dx = 1;
	
	while(ex != tx) {
		move(ex + dx, ey, ex, ey);
		ex += dx;
	}

	if (ey != ty) {
		move(ex, ty, ex, ey);
	}
}
void moveTo(int x, int y, int tx, int ty, int& ex, int& ey) {
	int dx = tx - x;
	if (dx < 0) dx = -1;
	if (dx > 0) dx = 1;
	
	while(x != tx) {
		moveEmptyTo(x + dx, y, x, y, ex, ey);
		move(x, y, x + dx, y);
		ex = x;
		ey = y;
		x += dx;
	}
	if (y != ty) {
		moveEmptyTo(x, ty, x, y, ex, ey);
		move(x, y, x, ty);
		ex = x;
		ey = y;
		y = ty;
	}
}

int main() {
	int n, k;
	std::cin >> n >> k;
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < n; ++x) {
			std::cin >> cur[x][y];
			--cur[x][y];
			if (cur[x][y] != -1) {
				if (y == 0 || y == 3) {
					car_tx[cur[x][y]] = x;
					car_ty[cur[x][y]] = y;
				}
			}
		}
	}
	
	int empty_x = -1;
	int empty_y = -1;
	for (int x = 0; x < n; ++x) {
		if (cur[x][0] == cur[x][1]) {
			move(x, 1, x, 0);
		}
		if (cur[x][3] == cur[x][2]) {
			move(x, 2, x, 3);
		}
		if (cur[x][1] == -1) {
			empty_x = x;
			empty_y = 1;
		} else if (cur[x][2] == -1) {
			empty_x = x;
			empty_y = 2;
		}
	}
	if (empty_x == -1 && empty_y == -1) {
		std::cout << "-1\n";
	} else {
		while(true) {
			bool change = false;
			for (int x = 0; x < n; ++x) {
				if (cur[x][1] != -1) {
					int car = cur[x][1];
					change = true;
					moveTo(x, 1, car_tx[car], norm(car_ty[car]), empty_x, empty_y);
					move(car_tx[car], norm(car_ty[car]), car_tx[car], car_ty[car]);
					break;
				}
				if (cur[x][2] != -1) {
					int car = cur[x][2];
					change = true;
					moveTo(x, 2, car_tx[car], norm(car_ty[car]), empty_x, empty_y);
					move(car_tx[car], norm(car_ty[car]), car_tx[car], car_ty[car]);
					break;
				}
			}
			if (! change) break;
		}
		std::cout << res.size() << '\n';
		for (auto it : res) {
			std::cout << it.first << ' ' << it.second.first << ' ' << it.second.second << '\n';
		}
	}
}






/*

0 0 0 4
0 0 0 4
5 0 0 3
0 5 0 3


6
1 1 1
2 2 1
4 4 1
3 4 4
5 2 3
5 2 4

*/