#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define ll long long int
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const ll LONGINF=4e18;
const double eps=1e-9;

template<typename T>void swap(T *x1,T *x2){
    T t;
    t=*x1;
    *x1=*x2;
    *x2=t;
}



void solve(int n){
	int m,k,i,j,a,b;
	vector<int> one;
	vector<vector<int>> t;
	scanf("%d%d",&m,&k);
	one.resize(m+2,0);
	t.resize(n+2,one);
	For(i,k){
		scanf("%d%d",&a,&b);
		t[a][b]=1;
		if(t[a+1][b]+t[a][b-1]+t[a+1][b-1]==3){
			printf("%d",i+1);
			return;
		}
		if(t[a-1][b]+t[a][b+1]+t[a-1][b+1]==3){
			printf("%d",i+1);
			return;
		}
		if(t[a-1][b]+t[a][b-1]+t[a-1][b-1]==3){
			printf("%d",i+1);
			return;
		}
		if(t[a+1][b]+t[a][b+1]+t[a+1][b+1]==3){
			printf("%d",i+1);
			return;
		}
	}
	printf("0");






#ifndef ONLINE_JUDGE
    printf("\n\nTime in ms: %.0lf",(double)clock() / CLOCKS_PER_SEC * 1000);
#endif
}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    char c[100100];
    string s;
	scanf("%d",&n);
	solve(n);
    /*printf("2000 1999 1\n");
    For(n,1999){
        printf("%d %d 1000000000000000\n",n+1,n+2);
    }*/
    return 0;
}