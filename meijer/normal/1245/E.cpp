#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MOD=1e9+7, N=10, M=100;

int h[N][N], up[M];
double mem[M];

int main() {
    RE(j,N) RE(i,N) cin>>h[i][j];
    RE(i,N) RE(j,N) {
    	int k, l;
    	if(j % 2) {
    		// right
    		k = j*N + N - i - 1;
    	} else {
    		// left
    		k = j*N + i;
    	}
    	if((j-h[i][j]) % 2) {
    		// right
    		l = (j-h[i][j])*N + N - i - 1;
    	} else {
    		// left
    		l = (j-h[i][j])*N + i;
    	}
    	up[k] = l;
    }
    mem[0] = 0.0;
    REP(i,1,6) {
    	mem[i] = 1.0;
    	REP(j,1,i+1) {
    		mem[i] += (1.0/6.0)*min(mem[i-j], mem[up[i-j]]);
    	}
    	mem[i] *= 6.0/double(i);
    }
    REP(i,6,M) {
    	mem[i] = 1.0;
    	REP(j,1,7) {
    		mem[i] += (1.0/6.0)*min(mem[i-j], mem[up[i-j]]);
    	}
    }
    printf("%.10f\n", mem[M-1]);
}