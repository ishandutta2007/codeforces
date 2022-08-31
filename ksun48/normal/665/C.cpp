#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string c;
	cin >> c;
	for(int i = 1; i < c.size(); i++){
		if(c[i] == c[i-1]){
			while(1){
				c[i] = ((c[i]-'a')+1)%26 + 'a';
				if(i+1 < c.size() && c[i] == c[i+1]){
				} else {
					break;
				}
			}
		}
	}
	cout << c << endl;
}