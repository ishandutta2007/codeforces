#include <string>
#include <iostream>
using namespace std;

string str[3][100005];
int n, p[100005];

int main(){
	int i, lastChoice;
	cin >> n;
	for(i = 1; i <= n; ++ i){
		cin >> str[1][i] >> str[2][i];
		if(str[1][i] > str[2][i]) swap(str[1][i], str[2][i]);
	}
	for(i = 1; i <= n; ++ i) cin >> p[i];
	lastChoice = 1;
	for(i = 2; i <= n; ++ i)
		if(str[1][p[i]] > str[lastChoice][p[i - 1]])
			lastChoice = 1;
		else if(str[2][p[i]] > str[lastChoice][p[i - 1]])
			lastChoice = 2;
		else{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}