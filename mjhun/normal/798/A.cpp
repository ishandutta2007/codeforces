#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

char s[32];int n;
int r;

int main(){
	scanf("%s",s);n=strlen(s);
	fore(i,0,n/2){
		r+=s[i]!=s[n-1-i];
	}
	if(r>1)puts("NO");
	else if(r==0&&n%2==0)puts("NO");
	else puts("YES");
	return 0;
}