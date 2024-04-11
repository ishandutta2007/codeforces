#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1)puts("1");
	else if(m-1>=n-m)printf("%d\n",m-1);
	else printf("%d\n",m+1);
	return 0;
}