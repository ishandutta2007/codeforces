#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string t;
	cin >> t;
	int a, b;
	for(int i = 0; i < 27; i++){
		for(int j = 0; j < i; j++){
			if(t[i] == t[j]){
				a = i;
				b = j;
			}
		}
	}
	if(a - b == 1){
		cout << "Impossible\n" << endl;
		return 0;
	}
	char s1[13];
	char s2[13];
	int c = a-b-1;
	s1[c/2] = t[a];
	int p = c/2;
	int cur = b+1;
	for(int i = p-1; i >= 0; i--){
		s1[i] = t[cur++];
	}
	int k = 0;
	while(cur < a){
		s2[k++] = t[cur++];
	}
	cur = a+1;
	while(k < 13){
		s2[k++] = t[cur % 27];
		cur++;
	}
	for(int k = 12; k > p; k--){
		s1[k] = t[cur % 27];
		cur++;
	}
	for(int i = 0; i < 13; i++) cout << s1[i];
	cout << endl;
	for(int i = 0; i < 13; i++) cout << s2[i];
	cout << endl;
}