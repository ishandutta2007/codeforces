#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int d[101010];
int a[101010];

int p[101010];
int u[101010];

int n,m;

int can(int x){
	for (int i=1;i<=n;i++) u[i]=0;
	for (int i=1;i<=m;i++){
		p[i]=x+1;
	}
	for (int i=x;i>=1;i--){
		if (d[i]>0&&p[d[i]]==x+1){
			u[i]=1;
			p[d[i]]=i;
		}
	}
	vector<pair<int, int> > s;
	for (int i=1;i<=m;i++){
		if (p[i]==x+1) return 0;
		else s.push_back({p[i], a[i]});
	}
	sort(s.begin(), s.end());
	int i2=0;
	for (int i=1;i<=x;i++){
		if (u[i]) continue;
		if (s[i2].F<=i) return 0;
		s[i2].S--;
		if (s[i2].S==0){
			i2++;
			if (i2==(int)s.size()) return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>d[i];
	}
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	int mi=0;
	int ma=n;
	int v=-1;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		if (can(mid)){
			v=mid;
			ma=mid-1;
		}
		else{
			mi=mid+1;
		}
	}
	cout<<v<<endl;
}