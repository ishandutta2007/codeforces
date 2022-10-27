#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
	
	int w, h; std::cin >> h >> w;
	vector<string> picture(h);
	for(int i=0; i<h; i++) std::cin >> picture[i];
	vector<vector<bool> > should_be_plus(h, vector<bool>(w, false));
	
	for(int i=1; i<h-1; i++){
		for(int j=1; j<w-1; j++){
			if(picture[i][j] == '*' && picture[i-1][j] == '*' && picture[i+1][j] == '*'
				&& picture[i][j+1] == '*' && picture[i][j-1] == '*'){				
				int upend = i, downend = i, leftend = j, rightend = j;
				while(upend >= 0 && picture[upend][j] == '*') should_be_plus[upend--][j] = true;
				while(downend < h && picture[downend][j] == '*') should_be_plus[downend++][j] = true;
				while(leftend >= 0 && picture[i][leftend] == '*') should_be_plus[i][leftend--] = true;
				while(rightend < w && picture[i][rightend] == '*') should_be_plus[i][rightend++] = true;
				for(int i2=0; i2<h; i2++) for(int j2=0; j2<w; j2++){
					if(should_be_plus[i2][j2] != (picture[i2][j2] == '*')){
						cout << "NO\n";
						return 0;
					}
				}
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}