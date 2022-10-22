#include <iostream>
#include <vector>

using namespace std;

struct Move{
	int i, r, c;
	Move(){}
	Move(int a, int b, int d){
		i = a, r = b, c = d;
	}
};

int n, k;
int map[5][55];
vector<Move> ans;
int rem;

void rot()
{
	int pi, pj;
	for(int i = 2; i <= 3; i++){
		for(int j = 1; j <= n; j++){
			if(map[i][j] == 0){
				pi = i, pj = j;
			}
		}
	}
	
	int si = pi, sj = pj, tmp = map[si][sj];
	for(int i = 1; i <= 2*n; i++){
		//cout << pi << " " << pj << endl;
		int ni, nj;
		if(pi == 2){
			if(pj >= 2) ni = 2, nj = pj-1;
			else ni = 3, nj = 1;
		}
		else{
			if(pj < n) ni = 3, nj = pj+1;
			else ni = 2, nj = n;
		}
		if(i < 2*n){
			if(map[ni][nj] != 0){
				ans.push_back(Move(map[ni][nj], pi, pj));
				map[pi][pj] = map[ni][nj];
				map[ni][nj] = 0;
			}
		}
		else{
			if(tmp != 0){
				ans.push_back(Move(tmp, pi, pj));
				map[pi][pj] = tmp;
			}
		}
		pi = ni, pj = nj;
		//if(pi == si && pj == sj) break;
	}
}

void check()
{
	for(int i = 1; i <= n; i++){
		if(map[2][i] && map[2][i] == map[1][i]){
			ans.push_back(Move(map[2][i], 1, i));
			map[2][i] = 0;
			rem--;
		}
		if(map[3][i] && map[3][i] == map[4][i]){
			ans.push_back(Move(map[3][i], 4, i));
			map[3][i] = 0;
			rem--;
		}
	}
}

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= n; j++){
			cin >> map[i][j];
		}
	}
	rem = k;
	
	bool flag = false;
	for(int i = 2; i <= 3; i++){
		for(int j = 1; j <= n; j++){
			if(map[i][j] == 0){
				flag = true;
			}
		}
	}
	if(!flag){
		check();
		if(rem == k){
			cout << -1 << endl;
			return 0;
		}
	}
	
	while(rem > 0){
		check();
		if(rem == 0) break;
		rot();
		
		/*cout << rem << endl;
		for(int i = 2; i <= 3; i++){
			for(int j = 1; j <= n; j++){
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	
	pass:;
	cout << (int)ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].i << " " << ans[i].r << " " << ans[i].c << endl;
	}
	
	return 0;
}