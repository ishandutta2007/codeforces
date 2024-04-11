#include <iostream>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

int T;
int h, w, n;
char c[105][105];
int need[105];
int ans[105][105];

bool get(int &x, int &y)
{
	if(y % 2){
		if(x < w) x++;
		else y++;
	}
	else{
		if(x > 1) x--;
		else y++;
	}
	return y <= h;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w >> n;
		
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				ans[x][y] = -1;
			}
		}
		
		int cnt = 0;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> c[x][y];
				if(c[x][y] == 'R') cnt++;
			}
		}
		
		for(int i = 0; i < n; i++){
			need[i] = cnt/n;
			if(i < cnt%n) need[i]++;
		}
		
		int x = 1, y = 1, id = 0;
		do{
			ans[x][y] = id;
			if(c[x][y] == 'R') need[id]--;
			if(need[id] <= 0) id++;
		}while(get(x, y));
		
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				if(ans[x][y] >= n) ans[x][y] = n-1;
			}
		}
		
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				if(ans[x][y] < 26) cout << (char)(ans[x][y]+'a');
				else if(ans[x][y] < 52) cout << (char)((ans[x][y]-26)+'A');
				else cout << (char)(ans[x][y]-52+'0');
			}
			cout << endl;
		}
	}
	
	return 0;
}