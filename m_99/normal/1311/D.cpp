#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	
	
	
	rep(_,_t){
		
		int a,b,c;
		cin>>a>>b>>c;
		
		int ans = Inf;
		int A,B,C;
		for(int i=1;i<=20000;i++){
			for(int j=i;j<=20000;j+=i){
				int temp = abs(i-a) + abs(j-b);
				int xx = c/j;
				int yy = xx+1;
				xx *= j;
				yy *= j;
				if(xx==0)xx = yy;
				else if((abs(xx-c)>abs(yy-c)))xx = yy;
				temp += abs(xx-c);
				if(ans > temp){
					ans = temp;
					A = i;
					B = j;
					C = xx;
				}
				//ans = min(ans,temp);
			}
			
		}
		
		cout<<ans<<endl;
		cout<<A<<' '<<B<<' '<<C<<endl;
		
	}
	
	return 0;
}