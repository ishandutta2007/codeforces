//// YOLOOOOOOO!!!!!

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <unordered_set>
#define MP make_pair
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define PB push_back
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


int x[100005], y[100005], n, m;
vector<int> P[100005];
vector<int> OSq, LSq;

unordered_set<LL> HS;

LL repr_PII(PII P){
	return (LL)P.first*1000000 + P.second;
}

void input(){
	scanf("%d", &n);
	REP(i,n){
		scanf("%d", &x[i]);
		scanf("%d", &y[i]);
		m = max(m, x[i]);
		
		P[x[i]].PB(y[i]);
		HS.insert(repr_PII({x[i],y[i]}));
	}
	REP(i,m+1){
		sort(ALL(P[i]));
	}
}


int main(){
	input();
	
	LL num = 0;
	
	int sq = (int)round(sqrt(n));
	
	// > sq
	REP(i,m+1){
		if(P[i].size() > sq)
			OSq.PB(i);
		else if(P[i].size())
			LSq.PB(i);
	}
	
	
	/*for(auto X: HS){
		printf("%lld\n", X);
	}*/
	
	for(int x: LSq){
		for(int i = 0; i < P[x].size(); i++){
			for(int j = i+1; j < P[x].size(); j++){
				int y1 = P[x][i], y2 = P[x][j];
				int d = y2-y1;
				//printf("%d %d %d %d\n", x, i, j, d);
				
				//printf("(%d,%d) %lld\n", x+d,y1, repr_PII({x+d,y1}));
				//printf("(%d,%d) %lld\n", x+d,y2, repr_PII({x+d,y2}));
				
				if(HS.find(repr_PII({x+d,y1})) != HS.end() &&
				   HS.find(repr_PII({x+d,y2})) != HS.end()){
					/*if(P[x+d].size() > sq){
						num++;
					}*/
					num++;
				}
				
				if(HS.find(repr_PII({x-d,y1})) != HS.end() &&
				   HS.find(repr_PII({x-d,y2})) != HS.end()){
					if(P[x-d].size() > sq)
						num++;
					///num++;
				}
			}
		}
	}
	
	for(int x1: OSq){
		P[x1].PB(10000000);
		for(int x2: OSq){
			if(x2 >= x1) continue;
			
			//printf("%d %d\n", x1, x2);
			
			int ptr1 = 0, ptr2 = 0, eq = 0;
			while(P[x1][ptr1] != 10000000 ||
			      P[x2][ptr2] != 10000000){
				
				int p1 = P[x1][ptr1], p2 = P[x2][ptr2];
				if(p1 == p2){
					if(HS.find(repr_PII({x1,p1+x1-x2})) != HS.end() &&
					   HS.find(repr_PII({x2,p1+x1-x2})) != HS.end()){
						num++;
					}
				} if(p1 > p2)
					ptr2++;
				else
					ptr1++;
			}
			
			//num += ((LL)eq * (eq+1))/2;
		}
	}
	
	
	printf("%I64d\n", num);
	return 0;
}