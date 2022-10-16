#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
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

const int MaxN = 100005,
          MaxBuckets = 2000;


int LastAns = 0;

int Left[MaxBuckets], Right[MaxBuckets];
vector<int> buckets[MaxBuckets];
unordered_map<int,int> numEqual[MaxBuckets];
int N, Q;
int SqrtN, NumBucks;


int add_bucket(int val, int buck, int pos = -1){
	//printf("[%d]\n", val);
	if(pos == -1){
		buckets[buck].push_back(val);
		//pos = buckets[buck].size();
	} else {
		buckets[buck].insert(buckets[buck].begin()+pos, val);
	}
	numEqual[buck][val] += 1;
	
	return buckets[buck].size();
}

int del_bucket(int pos, int buck){
	int val = buckets[buck][pos];
	buckets[buck].erase(buckets[buck].begin()+pos);
	numEqual[buck][val] -= 1;
	
	return val;
}



int recompValues[MaxN];

void recompute(){
	int ptr = 0;
	REP(b, NumBucks){
		for(int val: buckets[b]){
			recompValues[ptr++] = val;
		}
		numEqual[b].clear();
		
		Left[b] = b*SqrtN;
		Right[b] = min((b+1)*SqrtN-1, N-1);
		
		buckets[b].clear();
		buckets[b].reserve(2*SqrtN);
	}
	
	int indBuck = 0;
	REP(i, N){
		if(add_bucket(recompValues[i], indBuck) == SqrtN){
			indBuck++;
		}
	}
}



void input(){
	scanf("%d", &N);
	SqrtN = min((int)(round(sqrt(N)*2)),N);
	fprintf(stderr, "%d\n", SqrtN);
	
	NumBucks = (N+SqrtN-1)/SqrtN;
	int indBuck=0, ptrBuck = 0;
	
	
	REP(i,N){
		int data;
		scanf("%d", &data);
		if(add_bucket(data, indBuck) == SqrtN)
			indBuck++;
	}
	
	REP(b,NumBucks){
		Left[b] = b*SqrtN;
		Right[b] = min((b+1)*SqrtN-1, N-1);
	}
	
	scanf("%d", &Q);
}

void read_data(int& type, int& L, int& R, int& K){
	scanf("%d", &type);
	if(type == 1)
		scanf("%d%d", &L, &R);
	else
		scanf("%d%d%d", &L, &R, &K);
	
	L--; R--;
	
	L = (L+LastAns)%N;
	R = (R+LastAns)%N;
	K = (K+LastAns-1)%N + 1;
	if(L > R) swap(L, R);
}


inline void translate(int pos, int& buck, int& posBuck){
	REP(b, NumBucks){
		if(Left[b] <= pos && Right[b] >= pos){
			buck = b;
			posBuck = pos-Left[b];
		}
	}
}

void modify_ranges(int startBuck, int diff){
	//printf("mod(%d,%d)\n", startBuck, diff);
	Right[startBuck] += diff;
	FORI(b, startBuck+1, NumBucks-1){
		Left[b] += diff;
		Right[b] += diff;
	}
}

inline int count_whole_bucket(int buck, int K){
	unordered_map<int,int>::iterator it;
	it = numEqual[buck].find(K);
	if(it != numEqual[buck].end())
		return it->second;
	else
		return 0;
}
int count_part_bucket(int buck, int lpos, int rpos, int K){
	int res = 0;
	FORI(i, lpos, rpos){
		if(buckets[buck][i] == K)
			res++;
	}
	return res;
}
inline int count_left_bucket(int buck, int lpos, int K){
	return count_part_bucket(buck, lpos, buckets[buck].size()-1, K);
}
inline int count_right_bucket(int buck, int rpos, int K){
	return count_part_bucket(buck, 0, rpos, K);
}



void debug(){
	/*REP(b, NumBucks){
		printf("%d: (%d,%d)  [", b, Left[b], Right[b]);
		for(int v: buckets[b])
			printf("%d,", v);
		printf("], ");
		for(auto P: numEqual[b])
			printf("%d=>%d, ", P.first, P.second);
		printf("\n");
	}
	printf("\n");*/
}



void output(int val){
	printf("%d\n", val);
	LastAns = val;
}


int main(){
	input();
	//printf("%d %d\n", SqrtN, NumBucks);
	
	debug();
	
	REP(query, Q){
		int tp, L, R, K, lbuck, lpos, rbuck, rpos;
		read_data(tp, L, R, K);
		translate(L, lbuck, lpos);
		translate(R, rbuck, rpos);
		//printf("L=%d(%d,%d) R=%d(%d,%d)\n", L,lbuck,lpos, R,rbuck,rpos);
		
		if(tp == 1){
			int val = del_bucket(rpos, rbuck);
			add_bucket(val, lbuck, lpos);
			
			modify_ranges(rbuck, -1);
			modify_ranges(lbuck, 1);
		} else {
			//printf("K=%d\n", K);
			if(lbuck == rbuck){
				output(count_part_bucket(lbuck, lpos, rpos, K));
			} else {
				int result = 0;
				result += count_left_bucket(lbuck, lpos, K);
				result += count_right_bucket(rbuck, rpos, K);
				FORI(b, lbuck+1, rbuck-1){
					result += count_whole_bucket(b, K);
				}
				output(result);
			}
		}
	
		
		if(query % SqrtN == (SqrtN-1)){
			//printf("!!!\n");
			recompute();
		}
		
		debug();
	}
	
	
	return 0;
}