#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int k;
vector<pair<int,int> > e;
int n;
bool u[128];

int main(){
	scanf("%d",&k);
	if(k%2==0){puts("NO");return 0;}
	puts("YES");
	if(k==1){puts("2 1\n1 2");return 0;}
	int t=k/2;
	fore(i,0,k+1){
		fore(j,i+1,k+1){
			if(t&&!u[i]&&!u[j]){
				e.pb(mp(0,i+1));
				e.pb(mp(0,j+1));
				t--;
				u[i]=u[j]=true;
			}
			else {
				e.pb(mp(i+1,j+1));
			}
		}
	}
	printf("%d %d\n",2*(k+2),2*e.size()+1);
	printf("1 %d\n",k+3);
	fore(i,0,e.size()){
		int x=e[i].fst,y=e[i].snd;
		printf("%d %d\n",x+1,y+1);
		printf("%d %d\n",x+k+3,y+k+3);
	}
	return 0;
}