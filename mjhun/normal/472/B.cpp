#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,k;
int x[2048];

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%d",x+i);
	sort(x,x+n);
	int r=0;
	for(int i=n-1;i>=0;i-=k)r+=x[i]-1;
	printf("%d\n",2*r);
	return 0;
}