#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint T;
llint n;
string s;
llint a[200005];

void calc(string &s)
{
	int id = 1;
	for(int i = (int)s.size()-1; i >= 0; i--){
		if(s[i] == '>'){
			a[i+2] = id++;
		}
		else{
			llint l = -1;
			for(int j = i; j >= 0; j--){
				if(s[j] == '>'){
					l = j;
					break;
				}
			}
			for(int j = l; j <= i; j++) a[j+2] = id++;
			i = l;
		}
	}
	if(s[0] == '>') a[1] = id;
}

void calc2(string &s)
{
	int id = (llint)s.size() + 1;
	for(int i = (int)s.size()-1; i >= 0; i--){
		if(s[i] == '<'){
			a[i+2] = id--;
		}
		else{
			llint l = -1;
			for(int j = i; j >= 0; j--){
				if(s[j] == '<'){
					l = j;
					break;
				}
			}
			for(int j = l; j <= i; j++) a[j+2] = id--;
			i = l;
		}
	}
	if(s[0] == '<') a[1] = id;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n >> s;
		
		calc(s);
		for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
		calc2(s);
		for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	}
	
	return 0;
}