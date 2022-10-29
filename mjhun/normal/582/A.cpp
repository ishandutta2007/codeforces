#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int n;
multiset<int> q;
vector<int> sol;

void add(int k){
	for(int i=0;i<sol.size();++i){
		q.erase(q.find(gcd(k,sol[i])));
		q.erase(q.find(gcd(k,sol[i])));
	}
	q.erase(q.find(k));
	sol.push_back(k);
}

int main(){
	scanf("%d",&n);
	int m=n*n,k;
	while(m--){
		scanf("%d",&k);
		q.insert(k);
	}
	for(int i=0;i<n;++i){
		multiset<int>::iterator it=q.end();
		--it;
		add(*it);
	}
	printf("%d",sol[0]);
	for(int i=1;i<n;++i)printf(" %d",sol[i]);
	puts("");
	return 0;
}