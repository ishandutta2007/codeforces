#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int a[15];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'L'){
			for(int j = 0; j < 10; j++){
				if(a[j] == 0){
					a[j] = 1;
					break;
				}
			}
		}
		else if(s[i] == 'R'){
			for(int j = 9; j >= 0; j--){
				if(a[j] == 0){
					a[j] = 1;
					break;
				}
			}
		}
		else{
			a[s[i]-'0'] = 0;
		}
	}
	for(int i = 0; i < 10; i++) cout << a[i];
	cout << endl;
	
	return 0;
}