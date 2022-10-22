#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

mt19937 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
	
int main(){
	
	int T;
	cin>>T;
	
	for(int _=0;_<T;_++){
		int n,k;
		cin>>n>>k;
		
		if(n==1){
			cout<<"! 1"<<endl;
			continue;
		}
		int F = 1;
		for(int i=0;i<30;i++){
			int S;
			do{
				S = rnd()%n+1;
			}
			while(S==F);
			cout<<"? 1 1"<<endl;
			cout<<F<<endl;
			cout<<S<<endl;
			string s;
			cin>>s;
			if(s=="SECOND")F = S;
		}
		
		
		int ok = 0;
		if(F==1)ok = 1;
		int ng = n;
		
		while(ng-ok>1){
			int mid = ok*2+1;
			if(ok>=F)mid--;
			mid = min(mid,(ok+ng)/2);
			vector<int> a,b;
			for(int i=ok+1;i<=mid;i++){
				if(i==F)continue;
				a.push_back(i);
			}
			b.push_back(F);
			for(int i=1;b.size()<a.size();i++){
				if(i==F)continue;
				b.push_back(i);
			}
			
			if(a.size()==0){
				ok = mid;
				continue;
			}
			
			cout<<"? "<<a.size()<<" "<<b.size()<<endl;
			for(int i=0;i<a.size();i++){
				if(i!=0)cout<<' ';
				cout<<a[i];
			}
			cout<<endl;
			for(int i=0;i<a.size();i++){
				if(i!=0)cout<<' ';
				cout<<b[i];
			}
			cout<<endl;
			string s;
			cin>>s;
			if(s=="EQUAL")ok = mid;
			else ng = mid;
		}
		
		cout<<"! "<<ok+1<<endl;
			
	}
	
	return 0;
}