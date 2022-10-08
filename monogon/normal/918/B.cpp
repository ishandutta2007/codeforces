#include <iostream>
#include <map>

using namespace std;

int n, m;
string name, ip;
map<string, string> serverMap;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> name >> ip;
		serverMap[ip] = name;
	}
	for(int i = 0; i < m; i++) {
		cin >> name >> ip;
		cout << name << " " << ip << " #" << serverMap[ip.substr(0, ip.length() - 1)] << endl;
	}
}