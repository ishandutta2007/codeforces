#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,k,x;
int g;
ll a[200005];
priority_queue<pair<ll,int> > q;

int main(){
	scanf("%d%d%d",&n,&k,&x);
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		a[i]=t;
		q.push(mp(-abs(a[i]),i));
		if(a[i]<0)g++;
	}
	while(k--){
		int i=q.top().snd;q.pop();
		if(g%2){
			if(a[i]<0)a[i]-=x;
			else a[i]+=x;
		}
		else {
			if(a[i]<0){
				a[i]+=x;
				if(a[i]>=0)g--;
			}
			else {
				a[i]-=x;
				if(a[i]<0)g++;
			}
		}
		q.push(mp(-abs(a[i]),i));
	}
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%I64d",a[i]);
	}
	puts("");
	return 0;
}