#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

bool u[1024];
int n;

int main(){
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		u[x]=true;
	}
	bool r=false;
	fore(i,1,1001){
		r=r||u[i]&&u[i-1]&&u[i+1];
	}
	puts(r?"YES":"NO");
	return 0;
}