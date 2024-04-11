#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(int i = a, qwer = n;i<qwer;i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 100500;

int n,m;
char r[128];

void perdi(){puts("No");exit(0);}

string f[128];
bool t[128];
int w[128];

int main() {
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		char s[128];
		scanf("%s",s);
		f[i]=string(s);
	}
	fore(i,0,m)scanf("%d",w+i),w[i]--,t[w[i]]=true;
	int kk=f[w[0]].size();
	fore(i,0,m)if(f[w[i]].size()!=kk)perdi();
	fore(j,0,kk)r[j]=f[w[0]][j];
	fore(i,1,m){
		fore(j,0,kk){
			if(f[w[i]][j]!=r[j])r[j]='?';
		}
	}
	bool can=true;
	fore(i,0,n){
		if(f[i].size()!=kk)continue;
		if(t[i])continue;
		bool m=true;
		fore(j,0,kk){
			m=m&&(r[j]=='?'||r[j]==f[i][j]);
		}
		if(m)can=false;
	}
	if(!can)perdi();
	printf("Yes\n%s\n",r);
	return 0;
}