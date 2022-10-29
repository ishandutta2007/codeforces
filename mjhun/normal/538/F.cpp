#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

struct O {
	int ans=0, k;
	queue<int> q;
	O(int k):k(k){}
	void pop(){if(q.empty())return; if(q.front()<k)ans--; q.pop();}
	void add(int v){if(v<k)ans++; q.push(v);}
	int get(){return ans;}
};

const int N=2e5+5;
int n, A[N], ans[N], cnt[N];

int main(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	fore(x,0,n)cin>>A[x];

	fore(k,1,min(n,500)){
		fore(x,1,n){
			int i=x/k-(x%k==0);
			ans[k]+=A[x]<A[i];
		}
	}

	fore(i,1,min(n,500)){
		int l=0, r=-1;
		O tmp(A[i]);
		fore(k,500,n){
			int ql=k*i+1, qr=min(k*(i+1),n-1);
			if(ql>=n)break;
			while(r<qr)r++,tmp.add(A[r]);
			while(l<ql)tmp.pop(),l++;
			ans[k]+=tmp.get();
		}
	}

	int tmp=0;
	fore(k,1,n){
		tmp += A[k]<A[0];
		if(k>=500)ans[k]+=tmp;
	}

	fore(x,1,n)cout<<ans[x]<<" \n"[x+1==n];

	return 0;
}