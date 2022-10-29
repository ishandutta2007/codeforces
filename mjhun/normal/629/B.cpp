#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int x[512],y[512];
int n;


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		char t[2];
		int a,b;
		scanf("%s %d %d",t,&a,&b);
		for(int i=a;i<=b;++i){
			if(t[0]=='M')x[i]++;
			else y[i]++;
		}
	}
	int r=0;
	for(int i=1;i<=366;++i){
		r=max(r,min(x[i],y[i])*2);
	}
	printf("%d\n",r);
	return 0;
}