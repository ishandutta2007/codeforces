#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int g=__gcd(a,b),r=0;
	a/=g;b/=g;
	while(a%2==0){a/=2;r++;}
	while(a%3==0){a/=3;r++;}
	while(a%5==0){a/=5;r++;}
	if(a>1){puts("-1");return 0;}
	while(b%2==0){b/=2;r++;}
	while(b%3==0){b/=3;r++;}
	while(b%5==0){b/=5;r++;}
	if(b>1){puts("-1");return 0;}
	printf("%d\n",r);
	return 0;
}