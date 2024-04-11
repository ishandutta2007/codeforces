#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
ll mod=1e9+7;

int a[202020];
int u[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll v=1;
	int fe=n;
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			int x=i;
			while (u[x]==0){
				u[x]=i;
				x=a[x];
			}
			if (u[x]==i){
				int cs=0;
				ll lol=1;
				while (u[x]==i){
					u[x]=n+1;
					x=a[x];
					cs++;
					lol*=2;
					lol%=mod;
				}
				fe-=cs;
				lol+=mod-2;
				lol%=mod;
				v*=lol;
				v%=mod;
			}
		}
	}
	for (int i=0;i<fe;i++){
		v*=2;
		v%=mod;
	}
	cout<<v<<endl;
}