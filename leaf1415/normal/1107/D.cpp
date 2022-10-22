#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> vec;
bool map[5205][5205];
int l[5205][5205], u[5205][5205];

void enc(int i, int j, int x)
{
	if(x&8) map[i][j] = true;
	if(x&4) map[i][j+1] = true;
	if(x&2) map[i][j+2] = true;
	if(x&1) map[i][j+3] = true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(n % i == 0) vec.push_back(i);
	}
	
	char c; int x;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j+=4){
			cin >> c;
			if(c <= '9') x = c - '0';
			else x = c - 'A' + 10;
			enc(i, j, x);
		}
	}
	
	for(int k = (int)vec.size()-1; k >= 0; k--){
		int p = vec[k];
		for(int i = 1; i <= n; i+=p){
			for(int j = 1; j <= n; j+=p){
				
				bool flag = true;
				for(int di = 0; di < p; di++){
					for(int dj = 0; dj < p; dj++){
						if(map[i+di][j+dj] != map[i][j]){
							flag = false;
							goto end;
						}
					}
				}
				end:;
				if(!flag) goto end2;
			}
		}
		cout << p << endl;
		return 0;
		end2:;
	}
	
	return 0;
}