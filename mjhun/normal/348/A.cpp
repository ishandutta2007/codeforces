#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int a[100005];
int n;

bool can(int q){
	int w=q;
	fore(i,0,n){
		if(a[i]>q)return false;
		w-=min(w,q-a[i]);
	}
	return !w;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	int s=1,e=1500000007;
	while(e-s>1){
		int m=s+(e-s)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	printf("%d\n",s);
	return 0;
}