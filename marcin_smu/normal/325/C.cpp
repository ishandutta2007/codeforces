#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
//#define makel(A) scanf("%lld",&A)
//#define pll(A) printf("%lld ",A)
#define MAX 100001
#define INF 314000000
int m,n,odl[MAX];
int st[MAX],dia[MAX],pot[MAX];
int odl2[MAX],dia2[MAX],pot2[MAX],pocz[MAX];
vector<int> gdzie[MAX],d[MAX];
priority_queue<PI > kol;
queue<int > kol2;
bool cz[MAX];
void add(int kt){
	if(odl[st[kt]] == -1 || odl[st[kt]] > dia[kt]){
		odl[st[kt]] = dia[kt];
		kol.push(MP(-dia[kt],st[kt]));
	}
}
void add2(int kt){
	if(odl2[st[kt]] < dia2[kt])
		odl2[st[kt]] = dia2[kt];
	pocz[st[kt]]--;
	if(pocz[st[kt]]==0)
		kol2.push(st[kt]);
	
}
main(){
	make(m);
	make(n);
	R(i,n){
		odl[i] = -1;
		odl2[i] = -1;
	}
	R(i,m){
		make(st[i]);
		st[i]--;
		pocz[st[i]] ++;
		int pom;make(pom);
		while(pom--){
			int pom2;
			make(pom2);
			pom2--;
			if(pom2==-2){
				dia[i]++;
				dia2[i]++;
			}else{
				pot[i]++;
				pot2[i]++;
				gdzie[pom2].PB(i);
				d[st[i]].PB(pom2);
			}
		}
		if(pot[i]==0)add(i);
	}
	
	while(kol.empty()==0){
		PI ak = kol.top();kol.pop();
		int nr = ak.SE;
		if(-ak.FI != odl[nr])continue;
		R(i,gdzie[nr].size()){
			int pom = gdzie[nr][i];
			pot[ pom ]--;
			dia[pom] += odl[nr];
			if(dia[pom] > INF) dia[pom] = INF;
			if(pot[pom ] == 0)
				add(pom);
		}
	}
	R(i,n){
		if(odl[i] == -1){
			R(j,gdzie[i].size()){
				int pom = gdzie[i][j];
				if(cz[pom] == 0){
					cz[pom]=1;
					pot2[pom]=-1;
					pocz[st[pom]]--;
				}
			}
		}
	}
	R(i,m){
		if(pot2[i] == 0)add2(i);
	}
	while(kol2.empty()==0){
		int nr = kol2.front();kol2.pop();
		R(i,gdzie[nr].size()){
			int pom = gdzie[nr][i];
			pot2[ pom ]--;
			dia2[pom] += odl2[nr];
			if(dia2[pom] > INF) dia2[pom] = INF;
			if(pot2[pom] == 0)
				add2(pom);
		}
	}
	R(i,n){
		if(odl[i]==-1){
			printf("-1 -1\n");
		}else{
			printf("%d ",odl[i]);
			if(pocz[i] == 0)
				printf("%d\n",odl2[i]);
			else
				printf("-2\n");
		}
	}
}