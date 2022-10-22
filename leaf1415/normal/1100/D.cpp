#include <iostream>

using namespace std;

int px, py;
int x[1005], y[1005];
int mat[1005][1005];
int vx[] = {1, 1, 0, -1, -1, -1, 0, 1}, vy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int main(void)
{
	cin >> px >> py;
	for(int i = 1; i <= 666; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= 666; i++) mat[x[i]][y[i]] = 1;
	
	bool flag = false;
	int dir;
	int cntxy = 0, cntXY = 0, cntxY = 0, cntXy = 0;
	while(1){
		if(!flag && px == 500 && py == 500){
			flag = true;
			for(int i = 1; i <= 666; i++){
				if(x[i] < 500 && y[i] < 500) cntxy++;
				if(x[i] < 500 && y[i] > 500) cntxY++;
				if(x[i] > 500 && y[i] < 500) cntXy++;
				if(x[i] > 500 && y[i] > 500) cntXY++;
			}
			if(cntXY+cntXy+cntxY >= 499) dir = 7;
			else if(cntXY+cntxy+cntxY >= 499) dir = 5;
			else if(cntXY+cntXy+cntxy >= 499) dir = 1;
			else dir = 3;
		}
		if(!flag){
			if(px < 500) px++;
			else if(px > 500) px--;
			if(py < 500) py++;
			else if(py > 500) py--;
			cout << px << " " << py << endl;
		}else{
			
			for(int i = 0; i < 8; i++){
				int d = (dir+i)%8;
				int nx = px + vx[d], ny = py + vy[d];
				if(nx <= 0 || nx > 999 || ny <= 0 || ny > 999) continue;
				if(mat[nx][ny]) continue;
				px = nx, py = ny;
				break;
			}
			cout << px << " " << py << endl;
		}
		
		int k, rx, ry;
		cin >> k >> rx >> ry;
		if(k == -1) break;
		
		mat[x[k]][y[k]] = 0;
		x[k] = rx, y[k] = ry;
		mat[x[k]][y[k]] = 1;
	}
	
	return 0;
}