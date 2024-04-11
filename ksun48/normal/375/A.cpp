#include<iostream>
#include<cstring>
#include <vector>
using namespace std;
typedef long long LL;

int main(){
	char str[1100000];
	cin >> str;
	int n = strlen(str);
	int freq[10];
	for(int i = 0; i < 10; i++) freq[i] = 0;
	for(int i = 0; i < n; i++){
		freq[str[i]-'0']++;
	}
	freq[1]--;
	freq[6]--;
	freq[8]--;
	freq[9]--;
	vector<int> vec;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < freq[i]; j++) vec.push_back(i);
	}
	int stuff[7];
	stuff[0] = 1869;
	stuff[1] = 1968;
	stuff[2] = 1689;
	stuff[3] = 6891;
	stuff[4] = 1698;
	stuff[5] = 1986;
	stuff[6] = 1896;
	int mod1[6];
	mod1[0] = 1;
	mod1[1] = 3;
	mod1[2] = 2;
	mod1[3] = 6;
	mod1[4] = 4;
	mod1[5] = 5;
	int cur = 0;
	for(int i = 0; i < vec.size(); i++){
		cur = (cur+vec[i]*mod1[i%6])%7;
	}
	int k = mod1[(vec.size())%6];
	int rr = -1;
	for(int i = 0; i < 7; i++){
		if((cur+stuff[i]*k)%7 == 0){
			rr = i;
		}
	}
	if(rr == -1){
		cout << 0 << endl;
		return 0;
	}
	cout << stuff[rr];
	for(int i = vec.size()-1; i >= 0; i--){
		cout << vec[i];
	}
	cout << endl;
	return 0;
}