#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int nn,n;
int xx[100005],x[100005];
int nx[100005],pv[100005];
int a,b;

int main(){
	scanf("%d",&nn);
	fore(i,0,nn)scanf("%d",xx+i);
	scanf("%d%d",&a,&b);
	sort(xx,xx+nn);
	fore(i,0,nn){
		if(i&&xx[i]==xx[i-1])continue;
		x[n++]=xx[i];
	}
	fore(i,0,n)nx[i]=i+1;
	fore(i,0,n)pv[i]=max(i-1,0);
	int r=0;
	while(a>b){
		int na=a-1;
		for(int i=0;i<n;i=nx[i]){
			int k=a-a%x[i];
			if(k>=b)na=min(na,k);
			else {
				nx[pv[i]]=nx[i];
				pv[nx[i]]=pv[i];
			}
		}
		a=na;
		r++;
	}
	printf("%d\n",r);
	return 0;
}