#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
int n;
cin >> n;
string stuff[n];
for(int i = 0; i < n; i++){
	cin >> stuff[i];
}
int ans = 0;
for(char c = 'a'; c <= 'z'; c++){
	for(char d = 'a'; d <= 'z'; d++){
		int l = 0;
		for(int i = 0; i < n; i++){
			int yes = 1;
			for(int r = 0; r < stuff[i].size(); r++){
				if(stuff[i][r] != c && stuff[i][r] != d){
					yes = 0;
				}
			}
			if(yes){
				l += stuff[i].size();
			}
		}
		ans = max(ans,l);
	}
}
cout << ans << endl;
}