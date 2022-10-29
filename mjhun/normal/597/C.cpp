#include <bits/stdc++.h>
#define MN (1<<17)
using namespace std;

typedef long long ll;

ll f[MN];
ll t[MN];
int s[MN];
int n,k;

void upd(int p, ll v){
	if(!p)t[p]+=v;
	else while(p<MN){
		t[p]+=v;
		p+=p&(-p);
	}
}

ll qu(int w){
	ll r=0;
	while(w>0){
		r+=t[w];
		w&=w-1;
	}
	w=MN-1;
	while(w>0){
		r-=t[w];
		w&=w-1;
	}
	return -r;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%d",s+i);s[i]--;
	}
	for(int i=0;i<n;++i)f[i]=1;
	while(k--){
		memset(t,0,sizeof(t));
		for(int i=n-1;i>=0;--i){
			upd(s[i],f[i]);
			f[i]=qu(s[i]);
		}
	}
	ll r=0;
	for(int i=0;i<n;++i)r+=f[i];
	cout<<r<<endl;
	return 0;
}