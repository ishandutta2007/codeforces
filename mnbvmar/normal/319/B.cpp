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


const int MaxN = 100005;


int N;
int tab[MaxN];
set<int> S, toRemove, alive;
int numKills[MaxN];
int where[MaxN];


void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &tab[i]);
		where[tab[i]] = i;
	}
}


int main(){
	input();
	//fu_init(N);

	int result = 0;
	
	for(int i = 1; i <= N; i++){
		S.insert(i);
		alive.insert(i-1);
	}

	while(!S.empty()){
		for(auto it = S.rbegin(); it != S.rend(); it++){
			auto who = alive.upper_bound(where[*it]);
			if(who == alive.end() || tab[*who] > *it)
				toRemove.insert(*it);
			else {
				//printf("%d kills %d\n", *it, tab[*who]);
				numKills[*it]++;
				toRemove.insert(tab[*who]);
				alive.erase(*who);
			}
		}

		for(int x: toRemove){
			S.erase(x);
		}
		toRemove.clear();
	}

	for(int i = 0; i <= N; i++)
		result = max(result, numKills[i]);
	printf("%d\n", result);
}