#include <stdio.h>
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
const LD Eps = 1e-7;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


const int Undefined = -1,
          VertexInside = 1,
          VertexOutside = 2;
          
class TwoSAT {
	vector< vector<int> > adjGraph;
	vector< vector<int> > contractGraph;
	vector<int> numComp, index, lowVert, complement;
	vector<char> setValue, visited;
	stack<int> S;
	int N;
	int tm, compon;
	
	
	void dfs_comp(int v){
		index[v] = lowVert[v] = tm++;
		visited[v] = VertexInside;
		S.push(v);
		
		for(int i = 0; i < adjGraph[v].size(); i++){
			int s = adjGraph[v][i];
			
			if(index[s] == Undefined){
				dfs_comp(s);
				lowVert[v] = min(lowVert[v], lowVert[s]);
			} else if(visited[s] == VertexInside){
				lowVert[v] = min(lowVert[v], index[s]);
			}
		}
		
		
		if(lowVert[v] == index[v]){
			int comp = compon++, w;
			do {
				w = S.top(); S.pop();
				numComp[w] = comp;
				visited[w] = VertexOutside;
			} while(w != v);
		}
	}
	
	void get_components(){
		tm = compon = 0;
		while(!S.empty()) S.pop();
		
		for(int v = 0; v < 2*N; v++)
			if(!visited[v])
				dfs_comp(v);
	}
	
	void get_contracted_graph(){
		for(int v = 0; v < 2*N; v++){
			int numV = numComp[v];
			for(int i = 0; i < adjGraph[v].size(); i++){
				int numS = numComp[adjGraph[v][i]];
				contractGraph[numV].push_back(numS);
			}
			
			complement[numV] = numComp[v^1];
		}
	}
	
	void set_contracted_values(){		
		for(int i = compon-1; i >= 0; i--){
			if(setValue[i] == Undefined){
				setValue[i] = 0;
				setValue[complement[i]] = 1;
			}
		}
	}
	
	
public:
	TwoSAT() {}
	TwoSAT(int _N){
		N = _N;
		adjGraph.resize(2*N);
		numComp = complement = vector<int>(2*N);
		visited = vector<char>(2*N, 0);
		index = lowVert = vector<int>(2*N, Undefined);
		setValue = vector<char>(2*N, Undefined);
	}
	
	
	void addTrans(int p1, bool pos1, int p2, bool pos2){
		//printf("%d[%d]->%d[%d]\n", p1,pos1?1:0,p2,pos2?1:0);
		p1 = (p1*2) + (pos1 ? 0 : 1);
		p2 = (p2*2) + (pos2 ? 0 : 1);
		adjGraph[p1].push_back(p2);
	}
	
	void addClause(int p1, bool pos1, int p2, bool pos2){
		addTrans(p1, !pos1, p2, pos2);
		addTrans(p1, pos1, p2, !pos2);
	}
	
	
	bool solveSAT(){
		get_components();
		for(int i = 0; i < 2*N; i += 2)
			if(numComp[i] == numComp[i+1])
				return false;
		
		contractGraph.clear();
		contractGraph.resize(compon);
		
		get_contracted_graph();
		set_contracted_values();
		
		return true;
	}
	
	bool getState(int p){
		return (setValue[numComp[p*2]] == 1);
	}
};

TwoSAT TS;




const int MaxN = 100005;

int N, A, B;
map<int,int> p;
int data[MaxN];

void input(){
	scanf("%d%d%d", &N, &A, &B);
	REP(i, N){
		int val;
		scanf("%d", &val);
		data[i] = val;
		p[val] = i;
		//p.insert(PII(val, i));
	}
}

int main(){
	input();
	TS = TwoSAT(2*N);
	
	REP(i, N){
		//int num = data[i];
		int anum = A-data[i];
		if(p.count(anum)){
			int j = p.find(anum)->second;
			//printf("(%d)\n", j);
			TS.addTrans(i, true, j, true);
			TS.addTrans(j, false, i, false);
		} else {
			TS.addTrans(i, true, i, false);
		}
		
		int bnum = B-data[i];
		if(p.count(bnum)){
			int j = p.find(bnum)->second;
			//printf("(%d)\n", j);
			TS.addTrans(i, false, j, false);
			TS.addTrans(j, true, i, true);
		} else {
			TS.addTrans(i, false, i, true);
		}
	}
	if(!TS.solveSAT()){
		printf("NO\n");
	} else {
		printf("YES\n");
		REP(i, N){
			printf("%d ", TS.getState(i) ? 0 : 1);
		}
		printf("\n");
	}
}