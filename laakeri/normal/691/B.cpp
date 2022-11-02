#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

map<char, char> sc;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sc['A']='A';
	sc['b']='d';
	sc['d']='b';
	sc['H']='H';
	sc['I']='I';
	sc['M']='M';
	sc['O']='O';
	sc['o']='o';
	sc['p']='q';
	sc['q']='p';
	sc['T']='T';
	sc['U']='U';
	sc['V']='V';
	sc['v']='v';
	sc['W']='W';
	sc['w']='w';
	sc['X']='X';
	sc['x']='x';
	sc['Y']='Y';
	string s;
	cin>>s;
	for (int i=0;i<(int)s.size();i++){
		if (s[i]!=sc[s[(int)s.size()-i-1]]){
			cout<<"NIE"<<endl;
			return 0;
		}
	}
	cout<<"TAK"<<endl;
}