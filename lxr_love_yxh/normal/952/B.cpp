#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ull, ull> pull;
typedef vector <pii> vii;
typedef vector <pll> vll;
typedef vector <pull> vull;
const int mod = 1e9 + 7;
const int maxn = 1e3 + 3;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int n;
char c[1000];
string normal[5] = {"great", "don't think so", "dou't touch me", "not bad", "cool"};
string grumpy[6] = {"no way", "don't even", "are you serious", "go die in a hole", "worse", "terrible"};

int main(){
	fflush(stdout);
	for(int i = 0; i < 10; i++){
		printf("%d\n", i);
		fflush(stdout);
		memset(c, 0, sizeof(c));
		gets(c);
		string s = c;
		if(s == "no") continue;
		for(int j = 0; j < 5; j++){
			if(normal[j] == s){
				puts("normal");
				return 0;
			}
		}
		for(int j = 0; j < 6; j++){
			if(grumpy[j] == s){
				puts("grumpy");
				return 0;
			}
		}
	}
    return 0;
}