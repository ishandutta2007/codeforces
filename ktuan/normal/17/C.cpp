#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

const int MOD=51123987;

int n,mm;
char s[155];
int F[155][55][55], G[155][55][55], tmp[155][55][55];

int next[155][3];

int main() {
	scanf("%d",&n);
	gets(s);gets(s);
	Rep(i,n)s[i]-='a';
	Rep(i,3)next[n][i]=-1;
	Ford(i,n-1,0){
		Rep(j,3)next[i][j]=next[i+1][j];
		next[i][s[i]]=i;	
	}
	//Rep(i,n){Rep(j,3)cout<<next[i][j]<<" ";cout<<endl;}
	mm=n/3+10;
	if(mm>=55)mm=55;
	F[0][0][0]=1;
	Rep(i,n){
		memset(G,0,sizeof(G));
		Rep(j,n)Rep(sa,mm)Rep(sb,mm)if(F[j][sa][sb]>0){
			int tmp=F[j][sa][sb];
			if(next[j][0]!=-1){
				int z=next[j][0];
				G[z][sa+1][sb]+=tmp;
				if(G[z][sa+1][sb]>=MOD) G[z][sa+1][sb]-=MOD;
			}
			if(next[j][1]!=-1){
				int z=next[j][1];
				G[z][sa][sb+1]+=tmp;
				if(G[z][sa][sb+1]>=MOD) G[z][sa][sb+1]-=MOD;
			}
			if(next[j][2]!=-1){
				int z=next[j][2];
				G[z][sa][sb]+=tmp;
				if(G[z][sa][sb]>=MOD) G[z][sa][sb]-=MOD;
			}
		}	
		memmove(F,G,sizeof(G));
	}
	long long total=0;
	Rep(j,n)Rep(sa,mm)Rep(sb,mm){
		int sc=n-sa-sb;
		if(abs(sa-sb)<=1&&abs(sb-sc)<=1&&abs(sc-sa)<=1){
			//cout<<j<<" "<<sa<<" "<<sb<<" "<<sc<<endl;
			total=(total+F[j][sa][sb])%MOD;
		}	
	}
	cout<<total<<endl;
	return 0;	
}