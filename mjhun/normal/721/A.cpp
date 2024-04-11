#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

char s[128];
int n;
vector<int> r;

int main(){
	scanf("%d%s",&n,s);
	int b=0;
	fore(i,0,n){
		if(s[i]=='W'){
			if(b>0){
				r.pb(b);
				b=0;
			}
		}
		else b++;
	}
	if(b>0)r.pb(b);
	printf("%d\n",(int)r.size());
	if(r.size()){printf("%d",r[0]);
	fore(i,1,r.size())printf(" %d",r[i]);puts("");
	}
	return 0;
}