#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

void in(vector<int>& x){
	int k;
	scanf("%d",&k);
	while(k--){
		int a;
		scanf("%d",&a);
		x.pb(a);
	}
}

vector<int> w[100005];

int m;

int nv[8005][2];
int f[8005][2];

void go(int i, int k){
	if(f[i][k]==0){
		for(int x:w[k^1]){
			int j=(((i-x)%m)+m)%m;
			if(f[j][k^1]<0){
				f[j][k^1]=1;
				go(j,k^1);
			}
		}
	}
	else {
		for(int x:w[k^1]){
			int j=(((i-x)%m)+m)%m;
			if(f[j][k^1]<0){
				nv[j][k^1]--;
				if(nv[j][k^1]==0){
					f[j][k^1]=0;
					go(j,k^1);
				}
			}
		}
	}
}

int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&m);
	in(w[0]);in(w[1]);
//	fore(i,1,m){
//		fore(k,0,2){
//			for(int j:w[k]){
//				g[2*i+k].pb(2*((i+j)%m)+(k^1));
//			}
//		}
//	}
	memset(f,-1,sizeof(f));
	fore(k,0,2)fore(i,0,m)nv[i][k]=w[k].size();
	f[0][0]=f[0][1]=0;
	go(0,0);
	go(0,1);
	fore(k,0,2){
		fore(i,1,m){
			if(i>1)putchar(' ');
			if(f[i][k]==-1)printf("Loop");
			else if(f[i][k]==1)printf("Win");
			else printf("Lose");
		}
		puts("");
	}
	return 0;
}