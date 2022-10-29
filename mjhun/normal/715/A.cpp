#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int main(){
	int n;
	scanf("%d",&n);
	puts("2");
	fore(i,2,n+1)printf("%lld\n",1LL*i*(i+1)*(i+1)-i+1);
	return 0;
}