#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <functional>
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

const int MaxN = 100005;

/**/
const int MaxSiz = 32768,
          Base = 16384;
          
int P[MaxSiz], Q[MaxSiz];

void padd(int *P, int pos, int val){
	pos += Base;
	while(pos){
		P[pos] += val;
		pos /= 2;
	}
}

void add_num(int num){
	padd(P, num, num);
	padd(Q, num, 1);
}
void del_num(int num){
	padd(P, num, -num);
	padd(Q, num, -1);
}


LL krecur(int k, int v=1){
	if(v >= Base){
		//printf("v=%d\n", v);
		return k*(v-Base);
	}
	
	int lft = v*2;
	if(Q[lft] >= k){
		return krecur(k, lft);
	} else {
		return krecur(k-Q[lft], lft+1) + P[lft];
	}
}

int get_k_min(int k){
	//printf("[%d]%d %d\n", k, Q[1], Q[2]);
	int v= krecur(k);
	//printf("{{%d}}\n", v);
	return v;
}


/**/


const int MaxCand = 100005;

int N;
int a[MaxN], b[MaxN];
vector<int> votes[MaxCand], nums[MaxCand];
vector<int> decr;
int maxOpp = 0;

void input(){
	scanf("%d", &N);
	REP(i,N){
		scanf("%d%d", &a[i], &b[i]);
		votes[a[i]].push_back(b[i]);
		if(a[i])
			add_num(b[i]);
	}
	REP(i, MaxCand){
		sort(votes[i].begin(), votes[i].end(), greater<int>());
		if(!i) continue;
		
		if(votes[i].size() > 0)
			nums[votes[i].size()].push_back(i);
		
		maxOpp = max(maxOpp, (int)votes[i].size());
	}
}



int main(){
	input();
	
	int actualNum = votes[0].size();
	if(actualNum > maxOpp){
		printf("0\n");
		return 0;
	}
	
	int res = 1010101010;
	
	int leftToTake = N-actualNum;
	int incr = 0;
	FORD(i, N, max(actualNum,1)){
		for(int c: nums[i]){
			decr.push_back(c);
		}
		for(int d: decr){			
			int val = *votes[d].rbegin();
			//printf("%d %d\n", d, val);
			votes[d].pop_back();
			incr += val;
			leftToTake--;
			del_num(val);
		}
		
		if(leftToTake < 0) break;
		
		res = min(res, (int)get_k_min(leftToTake)+incr);
		leftToTake--;
	}
	
	printf("%d\n", res);
	
	return 0;
}