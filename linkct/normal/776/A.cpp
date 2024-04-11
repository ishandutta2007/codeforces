#include <iostream>
#include <map>
#include <string>
using namespace std;

int n; map <string, int> ss;

void print(){
	for(map <string, int> :: iterator it = ss.begin(); it != ss.end(); ++ it)
		for(int i = 1; i <= it -> second; ++ i)
			cout << it -> first << ' ';
	cout << endl;
}
int main(){
	string s;
	cin >> s; ++ ss[s];
	cin >> s; ++ ss[s];
	print(); cin >> n;
	while(n --){
		cin >> s; -- ss[s]; if(!ss[s]) ss.erase(s);
		cin >> s; ++ ss[s];
		print();
	} return 0;
}