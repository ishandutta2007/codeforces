#include<bits/stdc++.h>
using namespace std;
int n;
pair<pair<long long,long long>,long long> t[2000000];
long long s[2000000];
deque<int> d;
int next_to_front() {
	int p=d.front();
	d.pop_front();
	int q=d.front();
	d.push_front(p);
	return q;
}
int next_to_back() {
	int p=d.back();
	d.pop_back();
	int q=d.back();
	d.push_back(p);
	return q;
}
double cut(int i,int j) {
	double k1,n1,k2,n2,x1,y1;
	k1=-t[i].first.first;
	n1=s[i];
	k2=-t[j].first.first;
	n2=s[j];
	x1=(n1-n2)/(k2-k1);
	return x1;
}
bool orient(int i,int j,int k) {
	return cut(j,i)>cut(k,i);
}
int main()
{
	scanf("%d",&n);
	long long x,y,a;
	for(int i=0;i<n;i++) {
		scanf("%lld %lld %lld",&x,&y,&a);
		t[i]=make_pair(make_pair(x,y),a);
	}
	sort(t,t+n);
	s[0]=t[0].first.first*t[0].first.second-t[0].second;
	long long r=s[0];
	d.push_back(0);
	for(int i=1;i<n;i++) {
		s[i]=t[i].first.first*t[i].first.second-t[i].second;
		while(d.size()>1 && s[next_to_front()]-t[next_to_front()].first.first*t[i].first.second>=s[d.front()]-t[d.front()].first.first*t[i].first.second) d.pop_front(); 
		s[i]=s[i]+max(0LL,s[d.front()]-t[d.front()].first.first*t[i].first.second);
		while(d.size()>1 && orient(next_to_back(),i,d.back())) d.pop_back();
		d.push_back(i);
		r=max(r,s[i]);
	}
	printf("%lld",r);
	return 0;
}