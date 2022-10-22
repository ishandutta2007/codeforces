#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		deque<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		int ng = -1,ok = n-1;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			deque<int> b = a;
			b.erase(b.begin(),b.begin()+mid);
			int last = -1;
			while(b.size()!=0){
				if(b.back()<=b.front()){
					if(b.back()<last)break;
					last = b.back();
					b.pop_back();
				}
				else{
					if(b.front()<last)break;
					last = b.front();
					b.pop_front();
				}
			}
			if(b.size()==0)ok = mid;
			else ng = mid;
		}
		printf("%d\n",ok);
		
	}
	
	return 0;
}