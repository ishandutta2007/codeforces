#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string pulld = "s10utsusdteds";
string pullr = "s10ltslsrters";
string pulll = "s10rtsrsltels";
string pull_all;
void make_pull_all(){
	for(int i = 0; i < 36; i++){
		pull_all += pulld;
		pull_all += "ls";
	}
	for(int i = 0; i < 36; i++){
		pull_all += "r";
	}
}

int main(){
	make_pull_all();
	string ans;
	ans += "d" + pull_all;
	ans += "d" + pull_all;
	ans += "uu" + pull_all;
	ans += "d";
	ans += "l0r";
	for(int i = 0; i < 32; i++){
		ans += "1010utdtlt";
		ans += "r" + pullr + "l";
		ans += "1100utdtlt";
		ans += "l" + pulll + "l" + pulll + "rr";
		ans += "l";
	}
	ans += "rr";
	cout << ans << endl;
}