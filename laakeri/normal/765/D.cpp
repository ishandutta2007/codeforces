#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int f[101010];
int g[101010];
int h[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>f[i];
	}
	int c=0;
	for (int i=1;i<=n;i++){
		if (f[i]==i){
			c++;
			g[i]=c;
			h[c]=i;
		}
	}
	for (int i=1;i<=n;i++){
		if (f[i]!=i){
			if (g[f[i]]==0){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (f[i]!=i){
			g[i]=g[f[i]];
		}
	}
	cout<<c<<'\n';
	for (int i=1;i<=n;i++){
		cout<<g[i]<<" ";
	}
	cout<<'\n';
	for (int i=1;i<=c;i++){
		cout<<h[i]<<" ";
	}
	cout<<'\n';
}