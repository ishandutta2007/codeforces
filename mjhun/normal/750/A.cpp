#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int r=0,w=240-k;
	while(w>=0){
		r++;
		w-=5*r;
	}
	printf("%d\n",min(r-1,n));
	return 0;
}