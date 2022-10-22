#include <iostream>
#define llint long long

using namespace std;

int T;
int cap[2][3];
int a[8], b[8], b2[8];
int p[] = {7, 3, 5, 1, 6, 2, 4};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 3; j++){
				cin >> cap[i][j];
			}
		}
		for(int i = 0; i < 7; i++) cin >> a[p[i]];
		
		bool flag = false; int rem[3];
		for(int i = 0; i <= a[3]; i++){
			for(int j = 0; j <= a[5]; j++){
				for(int k = 0; k <= a[6]; k++){
					b[3] = i, b[5] = j, b[6] = k;
					rem[0] = cap[0][0] - b[3] - b[5];
					rem[1] = cap[0][1] - b[3] - b[6];
					rem[2] = cap[0][2] - b[5] - b[6];
					
					b[7] = min(a[7], min(min(rem[0], rem[1]), rem[2]));
					rem[0] -= b[7], rem[1] -= b[7], rem[2] -= b[7];
					if(b[7] < 0) continue;
					b[1] = min(a[1], rem[0]), b[2] = min(a[2], rem[1]), b[4] = min(a[4], rem[2]);
					
					for(int l = 1; l < 8; l++) b2[l] = a[l]-b[l];
				
					if(b2[1]+b2[3]+b2[5]+b2[7] > cap[1][0]) continue;
					if(b2[2]+b2[3]+b2[6]+b2[7] > cap[1][1]) continue;
					if(b2[4]+b2[5]+b2[6]+b2[7] > cap[1][2]) continue;
					
					flag = true;
					goto end;
				}
			}
		}
		end:;
		if(flag){
			for(int i = 0; i < 7; i++) cout << b[p[i]] << " ";
			cout << endl;
		}
		else cout << -1 << endl;
	}
	
	return 0;
}