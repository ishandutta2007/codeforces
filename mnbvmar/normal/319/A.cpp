#include <bits/stdc++.h>
#define MP make_pair
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define ALL(container) (container).begin(), (container).end()
#define FORI(i,from,to) for(int i = (from); i <= (to); i++)
#define FORD(i,from,to) for(int i = (from); i >= (to); i--)
#define REP(i,num) for(int i = 0; i < (num); i++)

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
const double Eps = 1e-7;
inline bool is_zero(double x){ return (x >= -Eps) && (x <= Eps); }



char str[105];
int N;

void input(){
	scanf("%s", str);
	N = strlen(str);
}


const int Mod = 1000000007;

int main(){
	input();
	int result = 0;

	for(int i = 0; i < N; i++){
		if(str[i] == '1'){
			int mul = 1;
			for(int j = 0; j < i; j++) mul = (mul*2) % Mod;
			for(int j = i+1; j < N; j++) mul = ((long long)mul * 4) % Mod;

			result = (result+mul)% Mod;
		}
	}
	printf("%d\n", result);
}