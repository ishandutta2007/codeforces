#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define fst first
#define snd second
#define mp make_pair
#define fore(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define mset(x,t) memset(x,t,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
typedef long long ll;

int n;
int a[128];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n-1)if(a[i]+a[i+1]==5){puts("Infinite");return 0;}
	puts("Finite");
	int r=0;
	fore(i,0,n-1)r+=1+max(a[i],a[i+1]);
	fore(i,0,n-2)if(a[i]==3&&a[i+1]==1&&a[i+2]==2)r--;
	printf("%d\n",r);
	return 0;
}
///