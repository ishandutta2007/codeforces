#include <iostream>
#define llint long long
#define MAX 1000000000000000000

using namespace std;

llint T;
llint n, k;
llint cap[35];
llint need[65];

int main(void)
{
	for(int i = 1; i < 35; i++){  //up to 30
		cap[i] = cap[i-1] + (1LL<<(2*(i-1)));
		if(cap[i] > MAX) break;
	}
	for(int i = 1; i < 65; i++){  //up to 58
		need[i] = need[i-1] + (1LL<<((i-1)+1)) - 1;
		if(need[i] > MAX) break;
	}
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		if(n > 31){
			cout << "YES" << " " << n-1 << endl;
			continue;
		}
		
		//cout << cap[n] << endl;
		if(k > cap[n]){
			cout << "NO" << endl;
			continue;
		}
		for(int i = 0; i <= 31; i++){
			//cout << need[i] << " " << cap[n] - cap[n-i]*((1<<(i+1))-1) << endl;
			if(need[i] > k) break;
			if(k <= cap[n] - cap[n-i]*((1LL<<(i+1))-1)){
				cout << "YES" << " " << n-i << endl;
				goto end;
			}
		}
		cout << "NO" << endl;
		end:;
	}
	return 0;
}