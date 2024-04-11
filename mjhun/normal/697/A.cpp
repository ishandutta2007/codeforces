#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int main(){
	int t,s,x;
	scanf("%d%d%d",&t,&s,&x);
	printf("%s\n",x<t||x==t+1||(x-t)%s>1?"NO":"YES");
	return 0;
}