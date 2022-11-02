#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int pointer = 0, can = 0;
	for(int i=1;i<min(n,k);i++) {
		if(s[pointer] < s[i])
			break;
		else if(s[pointer] > s[i]) {
			can = i;
			pointer = 0;
		}
		else {
			pointer++;
			if(pointer == can+1)
				pointer = 0;
		}
	}
	pointer = 0;
	while(k--) {
		cout<<s[pointer];
		pointer++;
		if(pointer == can+1)
			pointer = 0;
	}
	return 0;
}