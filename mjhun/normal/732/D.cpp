#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m;
int d[100005];
int a[100005];
bool w[100005];

bool can(int k){
	memset(w,false,sizeof(w));
	ll t=0;
	for(int i=k-1;i>=0;--i){
		if(d[i]>=0&&!w[d[i]]){
			t+=a[d[i]];
			w[d[i]]=true;
		}
		else if(t)t--;
	}
	if(t)return false;
	fore(i,0,m)if(!w[i])return false;
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		scanf("%d",d+i);d[i]--;
	}
	fore(i,0,m)scanf("%d",a+i);
	int s=1,e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	if(!can(s))puts("-1");
	else printf("%d\n",s);
	return 0;
}