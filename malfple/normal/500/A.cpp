#include <iostream>
#include <cstdio>

#include <cstring>
#include <string>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<int,double> pif;
typedef pair<double,double> pff;

#define OO (int)1e9
#define INF (ll)1e17

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
#define exl(i,l,r) ((i) > (l) && (i) < (r))
#define inl(i,l,r) ((i) >= (l) && (i) <= (r))

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

#define mp make_pair
#define pb push_back

#define ff first
#define ss second

int n,t;
int arr[30005];

int main(){
	scanf("%d %d",&n,&t);
	rep(i,1,n-1)scanf("%d",&arr[i]);
	int now=1;
	while(now<t){
		now+=arr[now];
	}
	if(now==t)printf("YES\n");
	else printf("NO\n");
	return 0;
}