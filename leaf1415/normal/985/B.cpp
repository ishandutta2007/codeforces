#include <iostream>

using namespace std;

int h, w;
char mat[2005][2005];
bool used[2005];

int main(void)
{
	cin >> h >> w;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> mat[x][y];
		}
	}
	
	for(int x = 0; x < w; x++){
		int pos = -1;
		for(int y = 0; y < h; y++){
			if(mat[x][y] == '1'){
				if(pos == -1) pos = y;
				else goto pass;
			}
		}
		used[pos] = true;
		pass:;
	}
	
	for(int i = 0; i < h; i++) if(!used[i]){
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;
	return 0;
}