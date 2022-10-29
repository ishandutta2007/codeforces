#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n,g;
bool w[1<<20];
int m[16],r[16];

int main(){
	g=16*9*5*7*11*13;
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",m+i);
	fore(i,0,n)scanf("%d",r+i);
	fore(i,0,n)for(int j=r[i];j<g;j+=m[i])w[j]=true;
	int s=0;
	fore(i,0,g)s+=w[i];
	printf("%lf\n",1.*s/g);
	return 0;
}