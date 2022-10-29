#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;
map<int,int> c;
int a[200005],b[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n)scanf("%d",b+i);
	pair<pair<int,int>,int> r=mp(mp(-1,-1),-1);
	fore(i,0,n)r=max(r,mp(mp(c[a[i]],c[b[i]]),i));
	printf("%d\n",r.snd+1);
	return 0;
}