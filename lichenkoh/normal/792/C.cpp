#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=1e5+4;
char a[mn];
pair<int,pair<int,pair<int,int> > > f[mn][3][2];
char res[mn];
int main() 
{
	scanf("%s\n",a);
	int n=strlen(a);
	for (int x=0;x<=n;x++)
		for (int m=0;m<3;m++)
			for (int z=0;z<2;z++) f[x][m][z].fst=-INF;
	f[0][0][1]=MP(0,MP(-1,MP(-1,-1)));
	for (int x=0;x<n;x++) {
		int d=a[x]-'0';
		for (int use=0;use<2;use++) {
			for (int m=0;m<3;m++) {
				int newm=(m+d*use)%3;
				for (int z=0;z<2;z++) {
					int val=f[x][m][z].fst;
					if (val<=-INF) continue;
					int newz=z;
					if (z==0) newz=0;
					else {
						if (d==0&&use) continue; // Cannot use 0
						if (use&&d!=0) newz=0;
					}
					//if (use==0) printf("x:%d m:%d z:%d val:%d\n",x,m,z,val);
					chkmax(f[x+1][newm][newz], MP(val+use, MP(use,MP(m,z))));
				}
			}
		}
	}
	/*for (int x=0;x<=n;x++)
		for (int m=0;m<3;m++)
			for (int z=0;z<2;z++) {
				int val=f[x][m][z].fst;
				if (val<=-INF) continue;
				printf("x:%d m:%d z:%d val:%d\n",x,m,z,val);
			}*/
	int idx=0;
	pll p=MP(0,0);
	int len=f[n][p.fst][p.snd].fst;
	if (len<=0) {
		for (int x=0;x<n;x++) {
			if (a[x]=='0') {
				printf("0\n"); return 0;
			}
		}
		printf("-1\n"); return 0;
	}
	res[len]='\0';
	for (int x=n;x>=1;x--) {
		auto got=f[x][p.fst][p.snd];
		int use=got.snd.fst;
		if (use) res[--len]=a[x-1];
		p=got.snd.snd;
	}
	printf("%s\n",res);
}