#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b,c;
		cin>>a>>b>>c;
		bool f = false;
		{
			int d = b-a;
			int cc = b+d;
			if(cc%c==0 && (cc/c)>=1){
				f = true;
			}
		}
		
		{
			int d = c-b;
			int aa = b-d;
			if(aa%a==0 && (aa/a)>=1){
				f = true;
			}
		}
		
		{
			int d = c-a;
			if(d%2==0){
				d/=2;
				int bb = a+d;
				if(bb%b==0 && (bb/b)>=1)f = true;
			}
		}
		if(f)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
	return 0;
}