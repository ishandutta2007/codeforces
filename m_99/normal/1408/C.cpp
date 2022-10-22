#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300


int main(){	
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n;
		cin>>n;
		int l;
		cin>>l;
		
		vector<int> a(n);
		
		rep(i,n)scanf("%d",&a[i]);
		
		a.insert(a.begin(),0);
		a.push_back(l);
		
		double ng = 0.0,ok = l+1.0;
		rep(__,60){
			double mid = (ok+ng)/2.0;
			
			double x = 0.0;
			double T = mid;
			rep(i,a.size()-1){
				double d = a[i+1]-a[i];
				double t = d/(i+1);
				if(t>=T){
					x += T * (i+1);
					break;
				}
				else{
					T -= t;
					x = a[i+1];
				}
			}
			
			double y = l;
			T = mid;
			for(int i=a.size()-1;i>=1;i--){
				double d = a[i]-a[i-1];
				double t = d/(a.size()-1+1-i);
				if(t>=T){
					y -= T * (a.size()-1+1-i);
					break;
				}
				else{
					T -= t;
					y = a[i-1];
				}
			}
			
			if(y<=x)ok = mid;
			else ng = mid;
			
		}
		
		cout<<fixed<<setprecision(10)<<ok<<endl;
		
	}
	
    return 0;
}