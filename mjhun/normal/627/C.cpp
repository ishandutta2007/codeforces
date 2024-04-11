#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int d,k,n;
pair<int,int> w[200005];
int p[200005];
stack<int> s;

int main(){
	scanf("%d%d%d",&d,&k,&n);
	for(int i=0;i<n;++i){
		int x,c;
		scanf("%d%d",&x,&c);
		w[i]=mp(x,c);
	}
	sort(w,w+n);
	w[n]=mp(d,-1);
	s.push(n);
	for(int i=n-1;i>=0;--i){
		while(w[s.top()].snd>=w[i].snd)s.pop();
		p[i]=s.top();
		s.push(i);
	}
	int t=k-w[0].fst,i=0;
	ll r=0;
	for(int i=0;t>=0&&i<n;++i){
		if(w[p[i]].fst-w[i].fst>t){
			int q=min(w[p[i]].fst-w[i].fst,k)-t;
			r+=1LL*q*w[i].snd;
			t+=q;
		}
		t-=w[i+1].fst-w[i].fst;	
	}
	cout<<(t<0?-1:r)<<endl;
	return 0;
}