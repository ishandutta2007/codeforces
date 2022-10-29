#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
char s[200005];

int main(){
	scanf("%d%s",&n,s+1);
	int r=0;
	for(int i=1;s[i]=='<';i++)r++;
	for(int i=n;s[i]=='>';i--)r++;
	printf("%d\n",r);
	return 0;
}