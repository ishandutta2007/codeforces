#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int n;
int a[100005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	puts("YES");
	int g=0;
	fore(i,0,n)g=gcd(g,a[i]);
	if(g>1){puts("0");return 0;}
	int r=0,i=0;
	while(i<n){
		if(a[i]%2==0){i++;continue;}
		int j=i;
		while(j<n&&a[j]%2)j++;
		r+=(j-i)/2;
		if((j-i)%2)r+=2;
		i=j;
	}
	printf("%d\n",r);
	return 0;
}