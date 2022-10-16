#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL X;

void input(){
	cin >> N >> X;
}

string result;

const string addends[10] = {
	"", "",   // 0, 1
	"2",
	"3",
	"322",
	"5",
	"53",
	"7",
	"7222",
	"7332"
};

int main(){
	input();
	
	while(X > 0){
		result += addends[X % 10];
		X /= 10;
	}

	sort(result.begin(), result.end(), greater<char>());

	cout << result << endl;
}