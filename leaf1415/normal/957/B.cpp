#include <iostream>
#include <vector>

using namespace std;

int w, h;
char map[55][55];
vector<int> vecx[105], vecy[105];

int parent[105];

void init(){
	for(int i = 1; i <= 100; i++) parent[i] = i;
}

int root(int i)
{
	if(parent[i] == i) return i;
	return parent[i] = root(parent[i]);
}

void unite(int i, int j)
{
	int root_i = root(i), root_j = root(j);
	if(root_i == root_j) return;
	parent[root_i] = root_j;
}

bool same(int i, int j)
{
	return root(i) == root(j);
}

int main(void)
{
	cin >> h >> w;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> map[x][y];
		}
	}
	init();
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			if(map[x][y] == '#') unite(x, y+50);
		}
	}
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			if(map[x][y] == '#'){
				for(int i = 1; i <= w; i++){
					if(map[i][y] == '#') unite(x, i);
				}
				for(int i = 1; i <= h; i++){
					if(map[x][i] == '#') unite(y+50, i+50);
				}
			}
		}
	}
	
	for(int i = 1; i <= w; i++){
		vecx[root(i)].push_back(i);
	}
	for(int i = 1; i <= h; i++){
		vecy[root(i+50)].push_back(i);
	}
	
	char ans[55][55];
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			ans[x][y] = '.';
		}
	}
	
	for(int i = 1; i <= 100; i++){
		for(int j = 0; j < vecx[i].size(); j++){
			for(int k = 0; k < vecy[i].size(); k++){
				ans[vecx[i][j]][vecy[i][k]] = '#';
			}
		}
	}
	
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(ans[x][y] != map[x][y]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}