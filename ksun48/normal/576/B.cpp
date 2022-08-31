#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int p[n+1];
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		if(p[i] == i){
			cout << "YES" << endl;
			for(int j = 1; j <= n; j++){
				if(j != i) cout << i << " " << j << endl;
			}
			return 0;
		}
	}
	for(int i = 1; i <= n; i++){
		if(p[p[i]] == i){
			int nums[n];
			for(int z = 1; z <= n; z++) nums[z] = -1;
			nums[i] = 2;
			nums[p[i]] = 2;
			for(int z = 1; z <= n; z++){
				if(nums[z] == -1){
					int cur = z;
					int q = 0;
					while(1){
						if(nums[cur] == -1){
							nums[cur] = q;
							q = 1-q;
							cur = p[cur];
						} else {
							if(nums[cur] != q){
								cout << "NO" << endl;
								return 0;
							} else {
								break;
							}
						}
					}
				}
			}
			cout << "YES" << endl;
			cout << i << " " << p[i] << endl;
			for(int z = 1; z <= n; z++){
				if(nums[z] == 0){
					cout << z << " " << i << endl;
				} else if(nums[z] == 1){
					cout << z << " " << p[i] << endl;
				}
			}
			return 0;

		}
	}
	cout << "NO" << endl;
	return 0;
}