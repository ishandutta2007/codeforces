#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int n;
char s[200005];
int p[200005];

int main(){
	scanf("%d%s",&n,s);
	for(int i=0;i<n;++i)scanf("%d",p+i);
	int r=-1;
	for(int i=0;i<n-1;++i){
		if(s[i]=='R'&&s[i+1]=='L'){
			if(r<0)r=(p[i+1]-p[i])/2;
			else r=min(r,(p[i+1]-p[i])/2);
		}
	}
	printf("%d\n",r);
	return 0;
}