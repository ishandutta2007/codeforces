#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

bitset<2048> w[2048];
bitset<2048> a[2048];
int x[500005];
int y[500005];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		scanf("%d%d",x+i,y+i);x[i]--;y[i]--;
		w[x[i]][y[i]]=1;
	}
	fore(i,0,n)a[i][i]=1;
	fore(i,0,n){
		if(!w[i][i]){
			fore(j,i+1,n){
				if(w[j][i]){
					swap(w[i],w[j]);
					swap(a[i],a[j]);
					break;
				}
			}
		}
		assert(w[i][i]);
		fore(j,0,n)if(j!=i&&w[j][i])w[j]^=w[i],a[j]^=a[i];
	}
	fore(i,0,m){
		puts(a[y[i]][x[i]]?"NO":"YES");
	}
	return 0;
}