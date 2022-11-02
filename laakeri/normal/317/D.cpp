#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[101010];
int c[100];

const int M=1e8;
char nb[M+10];
unordered_map<int, char> nbb;

int getnim(int b){
	if (b==0) return 0;
	if (b==(1<<29)-1) return 12;
	if (b<M){
		if (nb[b]) return nb[b]-1;
	}
	else{
		if (nbb.count(b)) return nbb[b];
	}
	set<int> nbs;
	for (int i=0;(1<<i)<=b;i++){
		if ((1<<i)&b){
			int u=b;
			int t=i+1;
			for (int k=1;(1ll<<(ll)(k*t-1))<=(ll)b;k++){
				u&=~(1<<(k*t-1));
			}
			nbs.insert(getnim(u));
		}
	}
	for (int j=0;;j++){
		if (nbs.count(j)==0){
			if (b<M) nb[b]=j+1;
			else nbb[b]=j;
			return j;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	c[1]=n;
	for (ll i=2;i*i<=n;i++){
		if (p[i]==0){
			p[i]=1;
			int t=1;
			for (ll x=i*i;x<=n;x=x*i){
				if (x*x<=n) p[x]=t+1;
				t++;
			}
			c[t]++;
			c[1]-=t;
		}
	}
	int x=0;
	for (int i=1;i<30;i++){
		if (c[i]%2==1){
			x^=getnim((1<<i)-1);
			//cout<<i<<" "<<getnim((1<<i)-1)<<" "<<((1<<i)-1)<<endl;
		}
	}
	if (x==0) cout<<"Petya"<<endl;
	else cout<<"Vasya"<<endl;
}