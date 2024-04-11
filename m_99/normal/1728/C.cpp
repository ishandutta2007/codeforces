#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

int get(int n){
	int cur = 1;
	rep(i,100){
		if(n < cur){
			return i;
		}
		cur*=10;
	}
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		multiset<int> a,b;
		rep(i,n){
			int x;
			scanf("%d",&x);
			a.insert(x);
		}
		rep(i,n){
			int x;
			scanf("%d",&x);
			b.insert(x);
		}
		int ans = 0;
		while(a.size()>0){
			auto ia = a.end();
			ia--;
			auto ib = b.end();
			ib--;
			if((*ia)==(*ib)){
				a.erase(ia);
				b.erase(ib);
				continue;
			}
			if((*ia)>(*ib)){
				int x = get(*ia);
				a.erase(ia);
				a.insert(x);
				ans++;
			}
			else{
				int x = get(*ib);
				b.erase(ib);
				b.insert(x);
				ans++;
			}
		}
		cout<<ans<<endl;
		
	}
	
    return 0;
}