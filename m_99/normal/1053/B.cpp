#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table{	
	vector<S> v;
	int _n;
	int sz;
	
	sparse_table() : sparse_table(0) {}
    sparse_table(int n) : sparse_table(std::vector<S>(n, e())) {}
    sparse_table(const std::vector<S>& x) : _n(int(x.size())) {
       sz = x.size();
		for(int i=0;true;i++){
			if((1<<i)>_n){
				sz = i;
				break;
			}
		}
		v.resize(sz*_n,e());
		
		for(int i=0;i<_n;i++){
			v[i] = x[i];
		}
		
		for(int i=1;i<sz;i++){
			for(int j=0;j<_n+1-(1<<i);j++){
				int temp = j+(1<<(i-1));
				v[i*_n+j] = op(v[(i-1)*_n+j],v[(i-1)*_n+temp]);
			}
		}
    }
	
	S prod(int l,int r){
		if(l==r)return e();
		int x = 31-__builtin_clz(r-l);
		return op(v[_n*x+l],v[_n*x+r-(1<<x)]);
	}
};

int op(int a,int b){
	return max(a,b);
}

int e(){
	return -1;
}
int main(){
	
	int n;
	cin>>n;
	
	vector<int> v(n);
	rep(i,n){
		long long a;
		scanf("%lld",&a);
		v[i] = __builtin_popcountll(a);
	}
	vector<int> SS(n+1,0);
	rep(i,n){
		SS[i+1] = SS[i] + v[i];
	}
	
	sparse_table<int,op,e> seg(v);

	
	vector S(2,vector<int>(n+1,0));
	int cur = 0;
	rep(i,n){
		cur += v[i];
		cur %= 2;
		S[cur][i+1] ++;
		rep(j,2)S[j][i+1] += S[j][i];
	}
	
	vector<int> rs(61,0);
	
	long long ans = 0LL;
	
	rep(i,n){
		rep(j,61){
			while(rs[j]!=n && seg.prod(i,rs[j]+1)<j)rs[j]++;
		}
		rep(j,60){
			int ok = i-1,ng = n+1;
			
			int l = rs[j];//seg.max_right<f>(i);
			
			int r = rs[j+1];//seg.max_right<f>(i);
			
			ok = i-1,ng = n+1;
			
			while(ng-ok>1){
				int mid = (ok+ng)/2;
				//cout<<mid<<','<<i<<endl;
				if(SS[mid] - SS[i]<j*2)ok = mid;
				else ng = mid;
			}
			l = max(l,ok);
			//cout<<i<<','<<j<<','<<l<<','<<r<<endl;
			if(l<r){
				int b = SS[i]%2;//F.sum(0,i)%2;
				ans += S[b][r] - S[b][l];
			}
			//ans += max(0,r-l);
			
			
		}
	}
	cout<<ans<<endl;


	return 0;
}