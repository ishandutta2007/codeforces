#include <iostream>
#define llint long long

using namespace std;

llint n, k;

int main(void)
{
	cin >> n >> k;
	if(n > k*(k-1)){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	for(int i = 1; i < k; i++){
		for(int j = 0; j < k; j++){
			cout << j+1 << " " << (j+i)%k+1 << endl;
			n--;
			if(n == 0) goto end;
		}
	}
	end:;
	return 0;
}