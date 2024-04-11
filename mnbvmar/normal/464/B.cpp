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
const LD Eps = 1e-8;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


int xx[8], yy[8], zz[8];

void input(){
	REP(i, 8)
		scanf("%d%d%d", &xx[i], &yy[i], &zz[i]);
}

int tab[3][3];
LL vec[3];

void cross(int p, int q){
	vec[0] = (LL)tab[1][p]*tab[2][q] - (LL)tab[1][q]*tab[2][p];
	vec[1] = (LL)tab[0][q]*tab[2][p] - (LL)tab[0][p]*tab[2][q];
	vec[2] = (LL)tab[0][p]*tab[1][q] - (LL)tab[0][q]*tab[1][p];
}

LL get_dist(int v){
	LL u = 0;
	int x = xx[v]-xx[0], y = yy[v]-yy[0], z = zz[v]-zz[0];
	/*u += (LL)tab[v][0]*tab[v][0];
	u += (LL)tab[v][1]*tab[v][1];
	u += (LL)tab[v][2]*tab[v][2];*/
	return (LL)x*x + (LL)y*y + (LL)z*z;
}




LL dot(int u, int v){
	return (LL)tab[u][0]*tab[v][0] + (LL)tab[u][1]*tab[v][1] + (LL)tab[u][2]*tab[v][2];
}


bool mkchk(int u, int v, int w){
	cross(u, v);
	if(vec[0] == 0 && vec[1] == 0 && vec[2] == 0) return false;
	//printf("C\n");
	if(tab[w][0]*vec[1] != tab[w][1]*vec[0]) return false;
	if(tab[w][0]*vec[2] != tab[w][2]*vec[0]) return false;
	
	return dot(u, v) == 0;
}

bool used[8];

bool good(int a, int b, int c){	
	//printf("%d %d\n", zz[a], zz[0]);
	tab[0][0] = xx[a]-xx[0];
	tab[0][1] = yy[a]-yy[0];
	tab[0][2] = zz[a]-zz[0];
	tab[1][0] = xx[b]-xx[0];
	tab[1][1] = yy[b]-yy[0];
	tab[1][2] = zz[b]-zz[0];
	tab[2][0] = xx[c]-xx[0];
	tab[2][1] = yy[c]-yy[0];
	tab[2][2] = zz[c]-zz[0];
	
	/*REP(i,3){
		REP(j,3) printf("%d\t", tab[i][j]);
		printf("\n");
	}*/
	
	LL distA = get_dist(a), distB = get_dist(b), distC = get_dist(c);
	//printf("A %lld %lld %lld\n", distA, distB, distC);
	if(distA != distB || distB != distC) return false;
	//printf("B\n");
	
	/*if(!mkchk(0,1,2)) return false;
	if(!mkchk(0,1,2)) return false;
	if(!mkchk(0,1,2)) return false;*/
	/*if(vec[0] == 0 && vec[1] == 0 && vec[2] == 0) return false;
	//printf("C\n");
	if(tab[2][0]*vec[1] != tab[2][1]*vec[0]) return false;
	if(tab[2][0]*vec[2] != tab[2][2]*vec[0]) return false;*/
	
	//printf("K\n");
	
	fill(used, used+8, false);
	
	fill(used, used+8, false);
	REP(u,2){
		REP(v,2){
			REP(w,2){
				int x,y,z;
				x = xx[0] + u*tab[0][0] + v*tab[1][0] + w*tab[2][0];
				y = yy[0] + u*tab[0][1] + v*tab[1][1] + w*tab[2][1];
				z = zz[0] + u*tab[0][2] + v*tab[1][2] + w*tab[2][2];
				
				bool ok = false;
				//printf("Y\n");
				REP(i, 8){
					if(x == xx[i] && y == yy[i] && z == zz[i]){
						if(used[i]) return false;
						used[i]=true;
						
						int sum = u+v+w;
						//printf("%d %d %lld %lld\n", i, sum, get_dist(i), distA);
						if(get_dist(i) != sum*distA)
							return false;
						ok = true;
					}
				}
				if(!ok) return false;
			}
		}
	}
	
	return true;
}

void check(){
	FORI(a, 1, 7){
		FORI(b, a+1, 7){
			FORI(c, b+1, 7){
				if(good(a,b,c)){
					printf("YES\n");
					REP(i, 8){
						printf("%d %d %d\n", xx[i], yy[i], zz[i]);
					}
					exit(0);
				}
			}
		}
	}
}


void brute(int i){
	if(i == 8){ check(); return; }
	
	brute(i+1);
	swap(yy[i],zz[i]);
	brute(i+1);
	swap(zz[i],xx[i]);
	brute(i+1);
	swap(zz[i],yy[i]);
	brute(i+1);
	swap(zz[i],xx[i]);
	brute(i+1);
	swap(zz[i],yy[i]);
	brute(i+1);
	swap(zz[i],xx[i]);
}

int data[8][3] = {
{0,0,0},
{0,0,0},
{0,0,0},
{0,0,0},
{1,1,1},
{1,1,1},
{1,1,1},
{1,1,1}
};


int main(){
	/*REP(i,8){
		xx[i] = data[i][0];
		yy[i] = data[i][1];
		zz[i] = data[i][2];
	}
	return good(1,2,3)==false;*/
	
	input();
	
	brute(1);
	printf("NO\n");
}