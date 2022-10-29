#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
	while(b){
		ll c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int f[128];
bool vis[128];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",f+i),f[i]--;
	ll r=1;
	fore(i,0,n){
		if(!vis[i]){
			int j,l=0;
			for(j=i;!vis[j];j=f[j])vis[j]=true,l++;
			if(j!=i){
				cout<<"-1\n";
				return 0;
			}
			if(l%2==0)l/=2;
			r=(r*l)/gcd(r,l);
		}
	}
	cout<<r<<endl;
	return 0;
}