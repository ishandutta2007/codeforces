#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int ans[30][2000];

int main(){
	int n,m;
	string s;
	cin >> n >> s >> m;
	vector<int> v(2*n);
	for(int i=0;i<n;i++){
		v[i] = s[i]-'a';
	}
	for(int i=0;i<26;i++){
		for(int j=1;j<=n;j++){
			int k = 0;
			int s = 0;
			int count = j;
			int mx =0;
			int len=0;
			while(1){
				if(k==n){
					mx = max(mx,len);
					break;
				}
				if(v[k]==i){
					k+=1;
					len += 1;
					mx = max(mx,len);
				}else{
					if(count>0){
						k += 1;
						len +=1;
						count -=1;
						mx = max(mx,len);
					}else{
						while(1){
							if(v[s]==i){
								s+=1;
								len-=1;
							}else{
								s+=1;
								len-=1;
								count +=1;
								break;
							}
						}
					}
				}
			}
			ans[i][j] = mx;
		}
	}

	for(int i=0;i<m;i++){
		int q;
		char x;
		cin >> q >> x;
		cout << ans[x-'a'][q] << endl;
	}
	return 0;
}