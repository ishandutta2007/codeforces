#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n;
char s[100005];

int main(){
	scanf("%d%s",&n,s);
	int a=0,d=0;
	fore(i,0,n){
		if(s[i]=='A')a++;
		else d++;
	}
	if(a>d)puts("Anton");
	else if(d>a) puts("Danik");
	else puts("Friendship");
	return 0;
}