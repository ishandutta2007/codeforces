#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

template <typename T>
struct CHT{

	vector<T> v;
	vector<T> a,b;
	int n;
	long long sign;
	
	T init_value;
	
	CHT(vector<T> &x,T iv,long long s=1){
		init_value = iv;
		sign = s;
		v = x;
		sort(v.begin(),v.end());
		int temp = distance(v.begin(),unique(v.begin(),v.end()));
		v.resize(temp);
		n=1;
		while(true){
			if(n>=v.size())break;
			n<<=1;
		}
		
		v.resize(n,1000000001);
		a.resize(2*n,0);
		b.resize(2*n,init_value);
	}
		
	void add(T A,T B,int start){
		int now = start;
		
		while(true){
			int ll = (now<<(__builtin_clz(now)-__builtin_clz(n)))-n;
			int rr = ll + (n>>(31-__builtin_clz(now))) -1;
			int m = (ll+rr)>>1;
			bool fl = sign*(A*v[ll]+B)<sign*(a[now]*v[ll]+b[now]);
			bool fm = sign*(A*v[m]+B)<sign*(a[now]*v[m]+b[now]);
			bool fr = sign*(A*v[rr]+B)<sign*(a[now]*v[rr]+b[now]);

			if(fl&&fr){
				a[now]=A;
				b[now]=B;
				break;
			}
			if(!fl&&!fr){
				break;
			}
			if(fm){
				swap(A,a[now]);
				swap(B,b[now]);
				swap(fl,fr);
			}
			if(fl){
				now<<=1;
			}
			else{
				now<<=1;
				now++;
			}
		}
	}

	void add_line(T A,T B){
		add(A,B,1);
	}
	
	void add_segment(T A,T B,T L,T R){
		L = distance(v.begin(),lower_bound(v.begin(),v.end(),L));
		R = distance(v.begin(),lower_bound(v.begin(),v.end(),R));
		if(R==L)return;
		L+=n;
		R+=n;
		
		while(true){
			if(L&1){
				add(A,B,L++);
			}
			if(R&1){
				add(A,B,--R);
			}
			if(L>=R)break;
			L>>=1;R>>=1;
		}
	}
	
	T query(T x){
		int now = n + distance(v.begin(),lower_bound(v.begin(),v.end(),x));
		T ret = init_value;
		while(true){
			ret = min(sign*ret,sign*(a[now]*x+b[now]))*sign;
			now>>=1;
			if(now<=0)break;
		}
		return ret;
	}
	
	void show(){
		int n = 1;
		for(int i=1;i<a.size();i++){
			for(int j=0;j<n;j++){
				if(j!=0)cout<<' ';
				cout<<a[i+j];
			}
			cout<<endl;
			i+=n-1;
			n*=2;
		}
	}
	
};

int main(){
	
	int Q;
	cin>>Q;
	
	long long sum = 0;
	long long cnt = 0;
	
	double L = 0;
	
	vector<int> t(Q);
	vector<double> x(Q,0);
	
	
	for(int i=0;i<Q;i++){
		scanf("%d",&t[i]);
		if(t[i]==1){
			scanf("%lf",&x[i]);
		}
	}
	
	CHT<double> C(x,1000000000000000000.0);
	C.add_line(1.0,0.0);
	for(int i=0;i<Q;i++){
		if(t[i]==1){
			C.add_line((double)1.0/((double)cnt+1),(double)sum/((double)cnt+1));
			sum+=x[i];
			cnt++;
			L=x[i];
		}
		else{
			printf("%.10lf\n",L-C.query(L));
		}
	}
	return 0;
}