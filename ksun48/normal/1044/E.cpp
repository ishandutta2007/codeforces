#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<vector<int> > arr;
typedef vector<pair<int,int> > step;
vector<vector<int> > moves;

vector<step> flip(vector<step> p){
	vector<step> q;
	for(step x : p){
		step y;
		for(auto a : x){
			y.push_back({a.second, a.first});
		}
		q.push_back(y);
	}
	return q;
}

vector<step> get_swap(int x1, int y1, int x2, int y2){
	assert(abs(x1-x2) + abs(y1-y2) == 1);
	if(x1 > x2) swap(x1, x2);
	if(y1 > y2) swap(y1, y2);
	if(x1 == x2) return flip(get_swap(y1, x1, y2, x2));
	vector<step> ans;
	int yz = y1 - 1;
	if(yz < 0) yz = y1 + 1;
	if(x1 == 0){
		ans.push_back({{x1, y1}, {x2, y1}, {x2+1, y1}, {x2+1, yz}, {x2, yz}, {x1, yz}});
		ans.push_back({{x2, yz}, {x2+1, yz}, {x2+1, y1}, {x2, y1}});
		ans.push_back({{x1, yz}, {x2, yz}, {x2, y1}, {x1, y1}});
	} else {
		ans.push_back({{x2, y1}, {x1, y1}, {x1-1, y1}, {x1-1, yz}, {x1, yz}, {x2, yz}});
		ans.push_back({{x1, yz}, {x1-1, yz}, {x1-1, y1}, {x1, y1}});		
		ans.push_back({{x2, yz}, {x1, yz}, {x1, y1}, {x2, y1}});
	}
	return ans;
}


vector<step> get_move(int x1, int y1, int x2, int y2, int dim){
	//cout << "Get " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	assert(abs(x1-x2) + abs(y1-y2) == 1);
	if(x1 == x2) return flip(get_move(y1, x1, y2, x2, arr.size()));
	vector<step> ans;
	int yz = y1 + 1;
	if(yz >= dim) yz = y1 - 1;
	ans.push_back({{x1,y1}, {x2,y1}, {x2,yz}, {x1,yz}});
	return ans;
}


void do_moves(vector<step> g){
	for(step a : g){
		vector<int> b;
		for(int p = 0; p < a.size(); p++){
			b.push_back(arr[a[p].first][a[p].second]);
		}
		moves.push_back(b);
		int r = arr[a.back().first][a.back().second];
		for(int p = a.size() - 1; p > 0; p--){
			arr[a[p].first][a[p].second] = arr[a[p-1].first][a[p-1].second];
		}
		arr[a[0].first][a[0].second] = r;
	}
	/*for(auto f : arr){
		for(auto g : f){
			cerr << g << " ";
		}
		cerr << endl;
	}
	cerr << endl;*/
}
//do_moves(get_swap(x1, y1, x2, y2));


int main(){
	int n, m;
	cin >> n >> m;
	arr.resize(n, vector<int>(m, -1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int num = 1 + i * m + j;
			int x = -1;
			int y = -1;
			for(int a = 0; a < n; a++){
				for(int b = 0; b < m; b++){
					if(arr[a][b] == num){
						x = a;
						y = b;
					}
				}
			}
			assert(x >= i);
			if(x == i) assert(y >= j);
			while(y < j){
				if(x == n-1 && x <= i + 1){
					do_moves(get_swap(x, y, x, y+1));
				} else {
					do_moves(get_move(x, y, x, y+1, m));
				}
				y++;
				assert(arr[x][y] == num);
			}
			while(y > j){
				if(x == n-1 && x <= i + 1){
					do_moves(get_swap(x, y, x, y-1));
				} else {
					do_moves(get_move(x, y, x, y-1, m));
				}
				y--;
				assert(arr[x][y] == num);				
			}
			while(x > i+1){
				do_moves(get_move(x, y, x-1, y, m));
				x--;
				assert(arr[x][y] == num);				
			}
			while(x > i){
				do_moves(get_swap(x, y, x-1, y));
				x--;
				assert(arr[x][y] == num);				
			}
			//cerr << "finished " << num << endl;
		}
	}
	cout << moves.size() << '\n';
	for(int i = 0; i < moves.size(); i++){
		cout << moves[i].size();
		for(int a : moves[i]){
			cout << " " << a;
		}
		cout << '\n';
	}
}