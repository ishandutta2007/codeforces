#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int main(){
	int k,r;
	scanf("%d%d",&k,&r);
	int s=1;
	while((k*s)%10!=r&&(k*s)%10!=0)s++;
	printf("%d\n",s);
	return 0;
}