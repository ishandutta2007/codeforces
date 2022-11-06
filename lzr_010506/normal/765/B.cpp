#include <bits/stdc++.h>
using namespace std;
string ch;
int main() 
{
	cin >> ch;
	char ss = 'a';
	for(int i = 0; i < ch.size(); i ++)
	{
		if(ch[i] < ss) continue;
		if(ch[i] > ss) {cout << "NO"; return 0;}
		if(ch[i] == ss) ss ++;
	}
	cout << "YES";
}