#include<bits/stdc++.h>
using namespace std;
int const N=2333333;
int n,m,q,cur,cnt[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m,cur=n;m--;){
		int x,y;cin>>x>>y;
		if(x>y)swap(x,y);
		cur-=!cnt[x]++;
	}
	for(cin>>q;q--;){
		int op,x,y;
		cin>>op;
		if(op>2)cout<<cur<<"\n";
		else{
			cin>>x>>y;
			if(x>y)swap(x,y);
			if(op>1)cur+=!--cnt[x];
			else cur-=!cnt[x]++;
		}
	}
}