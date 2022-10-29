#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
#define N 100005
using namespace std;

typedef long long ll;

ll l[N][2];
ll r[N][2];
int x[N];
int n;

int main(){
	scanf("%d",&n);n--;
	for(int i=0;i<n;++i){
		scanf("%d",x+i);
	}
	for(int i=n-1;i>=0;--i){
		r[i][1]=(x[i]==1)?0:r[i+1][1]+x[i]&(~1);
		if(x[i]%2)r[i][0]=max(r[i][1],x[i]+r[i+1][0]);
		else r[i][0]=max(r[i][1],x[i]-1+r[i+1][0]);
	}
	for(int i=1;i<=n;++i){
		l[i][1]=(x[i-1]==1)?0:l[i-1][1]+x[i-1]&(~1);
		if(x[i-1]%2)l[i][0]=max(l[i][1],x[i-1]+l[i-1][0]);
		else l[i][0]=max(l[i][1],x[i-1]-1+l[i-1][0]);
	}
	ll q=0;
	for(int i=0;i<=n;++i){
		q=max(q,r[i][0]+l[i][0]);
	}
	cout<<q<<endl;
	return 0;
}