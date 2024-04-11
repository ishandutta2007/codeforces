#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m,k;
int x[1024];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,m)x[i]=1<<20;
	fore(i,0,n){
		int a,b;
		scanf("%d%d",&a,&b);a--;
		x[a]=min(x[a],b);
	}
	int r=0;
	fore(i,0,m)r+=x[i];
	printf("%d\n",min(r,k));
	return 0;
}