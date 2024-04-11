#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex> 

#pragma warning(disable:4996) 

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define pb push_back 
#define mp make_pair 
#define x first 
#define y second 
#define all(v) (v).begin(),(v).end() 

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-4;
const double PI=3.1415926535897932384626433832795;

void solve(){
	pair<int,int> a[3];
	For(i,3) scanf("%d%d",&a[i].x,&a[i].y);
	if(a[0].x==a[1].x&&a[1].x==a[2].x||a[0].y==a[1].y&&a[1].y==a[2].y){
		printf("1");
		return;
	}
	int s=0;
	For(i,3){
		For(j,i){
			if(a[i].x==a[j].x){
				if(!((a[3-i-j].y<a[i].y)^(a[3-i-j].y<a[j].y))){
					printf("2");
					return;
				}
			}
			if(a[i].y==a[j].y){
				if(!((a[3-i-j].x<a[i].x)^(a[3-i-j].x<a[j].x))){
					printf("2");
					return;
				}
			}
		}
	}
	For(i,3){
		For(j,i){
			if(a[i].x==a[j].x) s++;
			if(a[i].y==a[j].y) s++;
		}
	}
	if(s>=2){
		printf("2");
		return;
	}
	printf("3");
}

int main(){
#pragma comment(linker,"/STACK:268435456") 
#ifdef _DEBUG 
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	solve();
	return 0;
}