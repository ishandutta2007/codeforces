#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007
#define TH 10000000

using namespace std;

llint T;
llint h, w;
char c[65][65];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> c[x][y];
			}
		}
		bool Pflag = false, Aflag = false;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				if(c[x][y] == 'A') Aflag = true;
				else Pflag = true;
			}
		}
		if(!Aflag){
			cout << "MORTAL" << "\n";
			continue;
		}
		if(!Pflag){
			cout << 0 << "\n";
			continue;
		}
		
		llint ans = 4;
		for(int x = 1; x <= w; x++){
			bool flag = true, flag2 = false;
			for(int y = 1; y <= h; y++){
				if(c[x][y] == 'P') flag = false;
				else flag2 = true;
			}
			if(flag){
				if(x == 1 || x == w) ans = min(ans, 1LL);
				else ans = min(ans, 2LL);
			}
			if(flag2 && (x == 1 || x == w)) ans = min(ans, 3LL);
		}
		for(int y = 1; y <= h; y++){
			bool flag = true, flag2 = false;
			for(int x = 1; x <= w; x++){
				if(c[x][y] == 'P') flag = false;
				else flag2 = true;
			}
			if(flag){
				if(y == 1 || y == h) ans = min(ans, 1LL);
				else ans = min(ans, 2LL);
			}
			if(flag2 && (y == 1 || y == h)) ans = min(ans, 3LL);
		}
		if(c[1][1] == 'A' || c[1][h] == 'A' || c[w][h] == 'A' || c[w][1] == 'A') ans = min(ans, 2LL);
		
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}