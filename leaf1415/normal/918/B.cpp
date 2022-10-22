#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;
map<string, string> mp;

int main(void)
{
	cin >> n >> m;
	string name, ip;
	for(int i = 0; i < n; i++){
		cin >> name >> ip;
		mp[ip] = name;
	}
	
	for(int i = 0; i < m;i++){
		cin >> name >> ip;
		cout << name << " " << ip << " #";
		ip.erase(ip.end()-1);
		cout << mp[ip] << endl;
	}
	return 0;
}