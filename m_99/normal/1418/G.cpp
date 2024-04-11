#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000
int t = 37;
long long add(long long a,long long b){
	vector<int> x(t),y(t);
	rep(i,t){
		x[i] = a%3;
		y[i] = b%3;
		a/=3;
		b/=3;
	}
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	long long ret =0LL;
	rep(i,t){
		ret *= 3;
		ret += (x[i]+y[i])%3;
	}
	
	return ret;	
}

int main(){
	
	
	int n;
	scanf("%d",&n);
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
		a[i]--;
	}
	
	vector<long long> B(n);
	mt19937 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

	rep(i,n){
		
		long long x = 0LL;
		rep(j,t){
			x *= 3;
			x += rnd()%3;
		}
		B[i] = x;
	}
	
	map<int,int> mp;
	map<long long,int> cnt;
	cnt[0] = 1;
	
	long long ans = 0LL;
	long long now = 0LL;
	
	int p = 1;
	vector<long long> S(n+1,0LL);
	
	rep(i,n){
		mp[a[i]]++;
		while(mp[a[i]]>=4){
			mp[a[p-1]]--;
			cnt[S[p-1]]--;
			
			p++;
		}
		
		now = add(now,B[a[i]]);
		ans += cnt[now];
		cnt[now] ++;
		S[i+1] = now;
	}

	cout<<ans<<endl;
	
    return 0;
}