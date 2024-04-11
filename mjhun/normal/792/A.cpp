#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,x[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	sort(x,x+n);
	int mn=(1<<31)-1,q=0;
	fore(i,0,n-1)mn=min(mn,x[i+1]-x[i]);
	fore(i,0,n-1)if(x[i+1]-x[i]==mn)q++;
	printf("%d %d\n",mn,q);
	return 0;
}