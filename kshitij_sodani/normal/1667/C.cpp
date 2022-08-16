#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	/*pair<int,int> mi={1e9,1e9};
	for(int i=1;i<=n;i++){
		mi=min(mi,{max(n-(i/2),i-1),i});
	}
	cout<<mi.a<<" "<<mi.b<<endl;
	return 0;*/
	if(n==1){
		cout<<1<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	if(n%3==0){
		cout<<((n*2)/3)<<endl;
		int x=n/3;
		pair<int,int> cur={x,1};
		for(int i=1;i<=x;i++){
			cout<<cur.a<<" "<<cur.b<<endl;
			cur.a-=1;
			cur.b+=1;
		}
		cout<<(2*x+1)<<" "<<(2*x+1)<<endl;
		cur={3*x,2*x+2};
		for(int i=1;i<x;i++){
			cout<<cur.a<<" "<<cur.b<<endl;
			cur.a-=1;
			cur.b+=1;
		}
	}
	else if(n%3==1){
		cout<<((n*2)/3)+1<<endl;
		int x=n/3;
		pair<int,int> cur={x,1};
		for(int i=1;i<=x;i++){
			cout<<cur.a<<" "<<cur.b<<endl;
			cur.a-=1;
			cur.b+=1;
		}
		cout<<(2*x+1)<<" "<<(2*x+1)<<endl;
		cur={3*x,2*x+2};
		for(int i=1;i<x;i++){
			cout<<cur.a<<" "<<cur.b<<endl;
			cur.a-=1;
			cur.b+=1;
		}
		cout<<(3*x+1)<<" "<<(3*x+1)<<endl;
	}
	else{
		cout<<((n*2)/3)<<endl;
		int x=n/3;
		x+=1;

		pair<int,int> cur={x,1};
		for(int i=1;i<=x;i++){
			cout<<cur.a<<" "<<cur.b<<endl;
			cur.a-=1;
			cur.b+=1;
		}
		cur={3*x-1,2*x+1};
		for(int i=1;i<x;i++){
			cout<<cur.a<<" "<<cur.b<<endl;
			cur.a-=1;
			cur.b+=1;
		}
	}








	return 0;
}