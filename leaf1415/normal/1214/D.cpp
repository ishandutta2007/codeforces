#include <iostream>
#include <string>
#define llint long long
#define P(x, y) ((y)*w+(x))

using namespace std;

llint h, w;
char c[1000005];
bool reach[1000005];
bool used[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> c[P(x, y)];
		}
	}
	
	reach[P(w-1, h-1)] = true;
	for(int y = h-1; y >= 0; y--){
		for(int x = w-1; x >= 0; x--){
			if(!reach[P(x, y)]) continue;
			if(c[P(x, y)] == '#'){
				reach[P(x, y)] = false;
				continue;
			}
			if(x-1 >= 0) reach[P(x-1, y)] = true;
			if(y-1 >= 0) reach[P(x, y-1)] = true;
		}
	}
	if(!reach[P(0, 0)]){
		cout << 0 << endl;
		return 0;
	}
	
	/*for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cout << reach[P(x, y)];
		}
		cout << endl;
	}*/
	
	int x = 0, y = 0;
	while(x != w-1 || y != h-1){
		if(x+1 < w && reach[P(x+1, y)]) x++;
		else y++;
		used[P(x, y)] = true;
	}
	used[P(w-1, h-1)] = false;
	
	x = 0, y = 0;
	while(x != w-1 || y != h-1){
		if(y+1 < h && reach[P(x, y+1)]) y++;
		else x++;
		if(used[P(x, y)]){
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 2 << endl;
	
	return 0;
}