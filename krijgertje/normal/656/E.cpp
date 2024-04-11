#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

const int MAXN=10;

int n;
int d[MAXN][MAXN];

int read(int x,int y) { return y<n?scanf("%d",&d[x][y]),read(x,y+1):x+1<n?read(x+1,0):1; }
int floyd(int i,int j,int k) { return j<n?d[i][j]=min(d[i][j],d[i][k]+d[k][j]),floyd(i,j+1,k):i+1<n?floyd(i+1,0,k):k+1<n?floyd(0,0,k+1):1; }
int mx(int x,int y) { return y<n?max(d[x][y],mx(x,y+1)):x+1<n?mx(x+1,0):0; }

void run() {
	scanf("%d",&n);
	read(0,0);
	floyd(0,0,0);
	printf("%d\n",mx(0,0));
}

int main() {
	run();
	return 0;
}