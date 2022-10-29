#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int main(){
	int s=0;
	fore(i,0,5){
		int c;
		scanf("%d",&c);
		s+=c;
	}
	if(!s||(s%5))puts("-1");
	else printf("%d\n",s/5);
	return 0;
}