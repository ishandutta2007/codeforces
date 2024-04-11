#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int main(){
	int n;
	scanf("%d",&n);
	if(n%2)printf("%d %d\n",9,n-9);
	else printf("%d %d\n",4,n-4);
	return 0;
}