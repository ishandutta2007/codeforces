#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint T;
bool prime[1000005];
vector<llint> vec;

int main(void)
{
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 1000005; i++){
		if(!prime[i]) vec.push_back(i);
	}
		
	cin >> T;
	llint a, b;
	for(int t = 0; t < T; t++){
		cin >> a >> b;
		if(a-b > 1){
			cout << "NO" << endl;
			continue;
		}
		llint x = 2*b+1;
		for(int i = 0; i < vec.size(); i++){
			if(x % vec[i]) continue;
			if(x/vec[i] > 1){
				cout << "NO" << endl;
			}else{
				cout << "YES" << endl;
			}
			goto end;
		}
		cout << "YES" << endl;
		end:;
	}
	
	return 0;
}