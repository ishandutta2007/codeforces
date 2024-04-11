#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#define MP make_pair

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int,int> VII;
const LD Eps = 1e-8;


char what[27] =
//"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"A??????HI???M?O????TUVWXY?";

char str[100005];

void input(){
	scanf("%s", str);
}

bool good(){
	int N = strlen(str);
	for(int i = 0; i < N; i++){
		if(str[i] != what[str[N-i-1]-'A'])
			return false;
	}
	return true;
}

int main(){
	input();
	printf(good() ? "YES\n" : "NO\n");
}