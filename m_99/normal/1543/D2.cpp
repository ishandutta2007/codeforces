#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int inv(int n,int k){
	int ret = 0;
	int cur = 1;
	while(n!=0){
		int t = n%k;
		n /= k;
		t = k-t;
		t %= k;
		ret += t * cur;
		cur *= k;
	}
	return ret;
}

int add(int a,int b,int k){
	int ret = 0;
	int cur = 1;
	while(a!=0||b!=0){
		int x = a%k,y = b%k;
		a/=k;
		b/=k;
		x += y;
		x %= k;
		ret += cur * x;
		cur *= k;
	}
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		scanf("%d",&n);
		int k;
		scanf("%d",&k);
		int cur = 0;
		rep(i,n){
			int temp = cur;
			if(i%2==0){
				temp = add(temp,i,k);
			}
			else{
				temp = add(temp,inv(i,k),k);
			}
			cout<<temp<<endl;
			int ret;
			scanf("%d",&ret);
			if(ret==0){
				cur = add(temp,inv(cur,k),k);
				continue;
			}
			else{
				break;
			}
		}
	}
	
    return 0;
}