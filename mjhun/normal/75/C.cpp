#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	while(b){
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}

map<int,int> p;
vector<int> d;
int a,b,n;
int w;

void gen(const map<int,int>::iterator& it){
	if(it==p.end())d.push_back(w);
	else {
		map<int,int>::iterator it2=it;
		++it2;
		int w2=w;
		gen(it2);
		for(int i=0;i<it->second;++i){
			w2*=it->first;
			w=w2;
			gen(it2);
		}
	}
}

int main(){
	scanf("%d%d%d",&a,&b,&n);
	a=gcd(a,b);
	for(int k=2;k*k<=a;++k){
		while(a%k==0){
			a/=k;
			p[k]++;
		}
	}
	if(a>1)p[a]+=1;
	w=1;
	gen(p.begin());
	sort(d.begin(),d.end());
	while(n--){
		int l,h;
		scanf("%d%d",&l,&h);
		vector<int>::iterator it=upper_bound(d.begin(),d.end(),h);
		--it;
		int r=*it;
		if(r>=l)printf("%d\n",r);
		else puts("-1");
	}
	return 0;
}