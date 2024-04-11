#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n;
int x[128];
int q[128];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	sort(x,x+n);
	int r=0;
	fore(i,0,n){
		while(x[i]>0&&!q[x[i]])x[i]--;
		if(!x[i])r++;
		q[x[i]]--;
		q[x[i]+1]++;
	}
	printf("%d\n",r);
	return 0;
}