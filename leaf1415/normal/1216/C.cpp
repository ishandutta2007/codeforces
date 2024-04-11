#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint sx[3], sy[3], tx[3], ty[3];

bool contain(llint x, llint y, llint id)
{
	return (x >= sx[id] && x <= tx[id] && y >= sy[id] && y <= ty[id]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 0; i < 3; i++){
		cin >> sx[i] >> sy[i] >> tx[i] >> ty[i];
	}
	
	bool flag = false;
	if(!contain(sx[0], sy[0], 1) && !contain(sx[0], sy[0], 2)) flag = true;
	if(!contain(sx[0], ty[0], 1) && !contain(sx[0], ty[0], 2)) flag = true;
	if(!contain(tx[0], sy[0], 1) && !contain(tx[0], sy[0], 2)) flag = true;
	if(!contain(tx[0], ty[0], 1) && !contain(tx[0], ty[0], 2)) flag = true;
	if(flag){
		cout << "YES" << endl;
		return 0;
	}
	
	for(int i = 1; i <= 2; i++){
		if(contain(sx[0], sy[0], i) && contain(tx[0], sy[0], i) 
		&& contain(tx[0], ty[0], i) && contain(sx[0], ty[0], i)){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	if(contain(sx[0], sy[0], 1) && contain(sx[0], ty[0], 1)){
		if(tx[1] >= sx[2]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	if(contain(sx[0], sy[0], 2) && contain(sx[0], ty[0], 2)){
		if(tx[2] >= sx[1]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	if(contain(sx[0], sy[0], 1) && contain(tx[0], sy[0], 1)){
		if(ty[1] >= sy[2]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	if(contain(sx[0], sy[0], 2) && contain(tx[0], sy[0], 2)){
		if(ty[2] >= sy[1]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	return 0;
}