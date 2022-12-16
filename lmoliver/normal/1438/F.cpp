#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

int query(int u,int v,int w){
	printf("? %d %d %d\n",u,v,w);
	fflush(stdout);
	return read();
}

int n;
int ran(){
	return rand()%(n-1)+1;
}

void answer(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}

int main(){
	int h=read();
	n=1<<h;

	map<int,int> cnt;
	D(i,400){
		int a,b,c;
		do{
			a=ran();
			b=ran();
			c=ran();
		}while(a==b||b==c||c==a);
		cnt[query(a,b,c)]++;
	}
	priority_queue<pair<int,int> > q;
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++){
		q.push(make_pair(it->second,it->first));
	}

	if(h==3){
		int a[3];
		D(i,3){
			a[i]=q.top().second;
			q.pop();
		}
		answer(query(a[0],a[1],a[2]));
		abort();
	}
	else{
		int a[2];
		D(i,2){
			a[i]=q.top().second;
			q.pop();
		}
		F(i,1,n-1){
			if(i!=a[0]&&i!=a[1]&&query(a[0],a[1],i)==i){
				answer(i);
			}
		}
		abort();
	}
	return 0;
}