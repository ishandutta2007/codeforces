#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
const int N=100100;
int n;
int t[N];
struct BIT{
	int a[N];
	void add(int x){
		for(;x<N;x+=x&-x){
			a[x]++;
		}
	}
	void sub(int x){
		for(;x<N;x+=x&-x){
			a[x]--;
		}
	}
	int sum(int x){
		int aa=0;
		for(;x;x-=x&-x){
			aa+=a[x];
		}
		return aa;
	}
	int f(){
		int l=0,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(sum(mid)==0){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		return l;
	}
}gr;
priority_queue<pair<int,int> > q1;
priority_queue<int> qwq;
int qt;
priority_queue<pair<int,int> > q2;
priority_queue<pair<int,int> > q3;
int p;
int ans[N];
void ww(int t){
	while(!qwq.empty()){
		int cc=gr.f();
		if(cc>=-qwq.top()){
			int c=-qwq.top();
			// <<c<<" in"<<" @"<<t<<endl;
			qwq.pop();
			int ft=max(qt,t)+p;
			qt=ft;
			gr.add(c);
			cc=max(cc,c-1);
			q2.push(make_pair(-ft,-c));
		}
		else{
			break;
		}
	};
}
signed main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		q1.push(make_pair(-t[i],-i));
	}
	while(!q1.empty()||!q2.empty()){
		if(q1.empty()||(!q2.empty()&&q1.top().first<q2.top().first)){
			//q2
			auto tp=q2.top();
			q2.pop();
			int tt=-tp.first;
			int ti=-tp.second;
			// <<ti<<" done"<<" @"<<tt<<endl;
			ans[ti]=tt;
			gr.sub(ti);
			ww(tt);
		}
		else{
			//q1
			auto tp=q1.top();
			q1.pop();
			int tt=-tp.first;
			int ti=-tp.second;
			qwq.push(-ti);
			ww(tt);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}