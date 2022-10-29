#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,w;
int a[200005];

int main(){
	scanf("%d%d",&n,&w);
	fore(i,0,2*n)scanf("%d",a+i);
	sort(a,a+2*n);
	int r=min(3LL*n*min(2*a[0],a[n]),2LL*w);
	printf("%d",r/2);
	if(r%2)printf(".5");
	puts("");
	return 0;
}//