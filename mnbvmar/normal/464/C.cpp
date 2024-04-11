#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <set>
#include <map>
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
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
const LD Eps = 1e-8;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


const int Mod = 1000000007;

string str;
int Q;
int val[10], powten[10];
vector<string> zm;

void input(){
	cin >> str;
	//scanf("%s", str);
	//scanf("%d", &Q);
	cin >> Q;
	zm.resize(Q);
	REP(i,Q){
		cin >> zm[i];
	}
}


int cnt[10];

int main(){
	ios_base::sync_with_stdio(0);
	
	input();
	REP(i,10){ val[i] = i; powten[i] = 10; }
	
	FORD(i, Q-1, 0){
		int from = (zm[i][0]-'0');
		int nval=0;
		int ncoef=1;
		
		for(int j = 3; j < zm[i].size(); j++){
			int c = zm[i][j] - '0';
			ncoef = ((LL)ncoef * powten[c]) % Mod;
			nval = ((LL)nval * powten[c] + val[c]) % Mod;
		}
		powten[from] = ncoef;
		val[from] = nval;
		
	}
	
	int totRes = 0;
	REP(i, str.size()){
		int c = str[i]-'0';
		totRes = ((LL)totRes * powten[c] + val[c]) % Mod;
	}
	
	cout << totRes << endl;
	
}