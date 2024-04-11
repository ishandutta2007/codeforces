#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

pair<ll,ll> t[300005];
int n;
priority_queue<ll> q;

bool can(int p){
	while(!q.empty())q.pop();
	int l;
	for(l=1;l<n&&-t[l].fst>-t[0].fst;l++);
	if(l-1<=p)return true;
	int c=l-1;
	fore(i,1,l)q.push(-(t[i].snd-(-t[i].fst)));
	ll w=-t[0].fst;
	while(c>p){
		if(q.empty())return false;
		ll z=-q.top();q.pop();
		if(z>=w)return false;
		w-=z+1;c--;
		while(l<n&&-t[l].fst>w){
			c++;
			q.push(-(t[l].snd-(-t[l].fst)));
			l++;
		}
	}
	return true;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		ll a,b;
		scanf("%I64d%I64d",&a,&b);
		t[i]=mp(-a,b);
	}
	sort(t+1,t+n);
	int s=0,e=n;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	printf("%d\n",s+1);
	return 0;
}